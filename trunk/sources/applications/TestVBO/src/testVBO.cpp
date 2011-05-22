/*
 Copyright (C) 2011 Robien-Engine team

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

 You can contact Robien-Engine team by electronic mail: robien.engine@gmail.com
 */
/****************************************
 *	Project		: robien-engine
 * 	Name File	: TestVBO.cpp
 *
 *  Created on	: 22 mai 2011
 *      Author	: Romain
 ***************************************/


#define GLEW_STATIC
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <boost/numeric/conversion/cast.hpp> 
#include <boost/lexical_cast.hpp>
#include <iostream>
#include "video/include/WindowManager.h"
#include "video/include/EventManager.h"
#include "utils/include/SmartPtr.h"
#include "../../../video/include/Object.h"
#include "../../../video/include/Vertices.h"
#include "../../../video/include/Model.h"
#include "../../../utils/include/Matrix4f.h"
#include "../../../utils/include/SmartPtr.h"


    GLuint buf;         /* identifiant de notre objet tampon */

    #define N_VERTS 24
    #define P_SIZE 3
    #define C_SIZE 3
#define BUFFER_OFFSET(a) ((char*)NULL + (a))


int etape = 0;
//SDL_Event event;


void draw_screen(EventManager* E, float* pos, float* colors)
{
    //creation de variable pour le temps
    double current_time = 0;
    double last_time = 0;
    double fps = 0;
    int n = 0;
    while (1)
    {
        etape = (etape + 1) % 360;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);
        glRotated(etape, 1, 1, 1);
        glRotated(etape, 0, 0, 1);
        glRotated(etape, 1, 0, 0);
        glRotated(etape, 1, 1, 0);
        glRotated(etape, 1, 0, 1);
        glRotated(etape, 1, 0, 3);
        /* on passe en mode VBO */
               glBindBuffer(GL_ARRAY_BUFFER, buf);

               glVertexPointer(P_SIZE, GL_FLOAT, 0, BUFFER_OFFSET(0));
               glColorPointer(C_SIZE, GL_FLOAT, 0, BUFFER_OFFSET(N_VERTS*P_SIZE*sizeof *pos));

               /* activation des tableaux de sommets */
               glEnableClientState(GL_VERTEX_ARRAY);
               glEnableClientState(GL_COLOR_ARRAY);

               glDrawArrays(GL_QUADS, 0, N_VERTS);

               /* desactivation des tableaux de sommet */
               glDisableClientState(GL_COLOR_ARRAY);
               glDisableClientState(GL_VERTEX_ARRAY);

               /* on flip les tampons */
               glFlush();
        SDL_GL_SwapBuffers();
        //reduire les fps


        //TRUC PAS BEAU pour afficher les fps
        current_time = SDL_GetTicks() / 1000;
        n++;
        if ((current_time - last_time) >= 1.0)
        {
            // nombre de frames par seconde
            fps = n;
            n = 0;
            last_time = current_time;
            SDL_WM_SetCaption(("fps : " + boost::lexical_cast<std::string>((int) fps)).c_str(),
                    NULL);

        }
        else /* Si la fait moins de 30ms depuis le dernier tour de boucle, on endort le programme le temps qu'il faut */
        {
//            SDL_Delay(30 - (current_time - last_time));
        }

        //SDL_PollEvent(&event);
        //gestion evenement
        if (E->EM_Quit() || E->EM_KeyDown(SDLK_ESCAPE))
        {
            return;
        }
    }
}

void setup_opengl(int hauteur, int largeur)
{
    float ratio = (float) hauteur / (float) largeur;
    glClearColor(0, 0, 0, 0);
    glViewport(0, 0, hauteur, largeur);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 0.5, 50);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    using boost::numeric_cast;
    int hauteur = 800;
    int largeur = 600;
    int bits = 32;
    int flags = 0;

std::cout << "salut" << std::endl;

    float pos[N_VERTS*P_SIZE] =
    {
            0,0,0,
            1,0,0,
            1,1,0,
            0,1,0,

            1,0,0,
            1,1,0,
            1,1,1,
            1,0,1,

            1,1,0,
            0,1,0,
            0,1,1,
            1,1,1,

            0,0,0,
            1,0,0,
            1,0,1,
            0,0,1,

            0,0,0,
            0,1,0,
            0,1,1,
            0,0,1,

            0,0,1,
            1,0,1,
            1,1,1,
            0,1,1


    };
    std::cout << "salut" << std::endl;
    float colors[N_VERTS*C_SIZE] =
    {
            1, 0, 0,
            -1, -9, 0,
            1, -3, 5,
            3, 1, -1,

            -1, -1, 0,
            1, 1, 0,
            -1, -1, -1,
            -1, -1, 0,

            -1, -1, 0,
            1, 0, -1,
            2, -1, 0,
            -1, -1, 0,

            1, 3, 0,
            -1, 4, -1,
            1, 0, 0,
            -1, 0, 6,

            -1, 2, -2,
            1, -5, 0,
            -1, -1, 0,
            -1, -1, 0,

            -3, 2, 0,
            -1, -2, 3
            -1, 2, -2,
            1, -5, 0,

    };

    /*SDL_Init(SDL_INIT_VIDEO);
     flags = SDL_OPENGL;
     SDL_SetVideoMode(hauteur, largeur, bits, flags);*/
    WindowManager fen(hauteur, largeur);
    SmartPtr<EventManager> E = new EventManager();
    setup_opengl(hauteur, largeur);
       /* initialisation de glew */
          glewInit();
          /* creation d'un objet tampon et recuperation de son identifiant */
          glGenBuffers(1, &buf);

          /** creation de notre VBO **/
          /* on bind le buffer */
          glBindBuffer(GL_ARRAY_BUFFER, buf);
          /* on alloue un espace */
          glBufferData(GL_ARRAY_BUFFER,                   /* target */
                          (N_VERTS*P_SIZE*sizeof *pos) +  /* taille des positions */
                          (N_VERTS*C_SIZE*sizeof *colors),/* taille des couleurs */
                          NULL,                           /* ... */
                          GL_STREAM_DRAW);                /* mode */
          /* on specifie les donnees */
          glBufferSubData(GL_ARRAY_BUFFER,
                          0,                            /* emplacement des donnees dans le VBO */
                          (N_VERTS*P_SIZE*sizeof *pos), /* taille des donnees */
                          pos);                         /* adresse des donnees */
          glBufferSubData(GL_ARRAY_BUFFER,
                          (N_VERTS*P_SIZE*sizeof *pos),   /* emplacement */
                          (N_VERTS*C_SIZE*sizeof *colors),/* taille */
                          colors);                        /* donnees */
          glBindBuffer(GL_ARRAY_BUFFER, 0);
    draw_screen(E, pos, colors);
    return 0;
}
