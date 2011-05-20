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
 * 	Name File	: RobienEngine.cpp
 *
 *  Created on	: 11 mai 2011
 *      Author	: Romain
 ***************************************/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <boost/numeric/conversion/cast.hpp> 
#include <boost/lexical_cast.hpp>
#include <iostream>
#include "video/include/WindowManager.h"
#include "video/include/EventManager.h"
#include "utils/include/SmartPtr.h"
#include "../../../video/include/Object.h"
#include "../../../video/include/Vertices.h"
#include "../../../video/include/Model.h"

int etape = 0;
//SDL_Event event;

Object* cube();

void draw_screen(EventManager* E)
{
	//creation de variable pour le temps
	double current_time = 0;
	double last_time = 0;
	double fps = 0;
	int n = 0;
	SmartPtr<Object> cube1 = cube();
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
		cube1->drawObject();
		/*glBegin(GL_QUADS);
		 glColor3d(1, 0, 0);
		 glVertex3i(1, 1, 1);
		 glColor3d(-1, -9, 0);
		 glColor3d(1, -3, 5);
		 glVertex3i(1, -1, 1);
		 glColor3d(3, 1, -1);
		 glVertex3i(-1, -1, 1);
		 glColor3d(-1, -1, 0);
		 glVertex3i(-1, 1, 1);
		 glColor3d(1, 1, 0);
		 glVertex3i(1, 1, -1);
		 glColor3d(-1, -1, -1);
		 glVertex3i(1, -1, -1);
		 glColor3d(-1, -1, 0);
		 glVertex3i(-1, -1, -1);
		 glColor3d(-1, -1, 0);
		 glVertex3i(-1, 1, -1);
		 glColor3d(1, 0, -1);
		 glVertex3i(1, 1, 1);
		 glColor3d(2, -1, 0);
		 glVertex3i(1, -1, 1);
		 glVertex3i(1, -1, -1);
		 glColor3d(-1, -1, 0);
		 glVertex3i(1, 1, -1);
		 glColor3d(1, 3, 0);
		 glVertex3i(-1, 1, 1);
		 glColor3d(-1, 4, -1);
		 glVertex3i(-1, -1, 1);
		 glColor3d(3, -1, 0);
		 glVertex3i(-1, -1, -1);
		 glColor3d(1, 0, 0);
		 glVertex3i(-1, 1, -1);
		 glColor3d(-1, 0, 6);
		 glVertex3i(-1, 1, -1);
		 glColor3d(-1, 2, -2);
		 glVertex3i(-1, 1, 1);
		 glColor3d(1, -5, 0);
		 glVertex3i(1, 1, 1);
		 glColor3d(-1, -1, 0);
		 glVertex3i(1, 1, -1);
		 glColor3d(-1, -1, 0);
		 glVertex3i(-1, -1, -1);
		 glVertex3i(-1, -1, 1);
		 glColor3d(-3, 2, 0);
		 glVertex3i(1, -1, 1);
		 glColor3d(-1, -2, 3);
		 glVertex3i(1, -1, -1);
		 glEnd();*/

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
			SDL_WM_SetCaption(
					("fps : " + boost::lexical_cast<std::string>((int) fps)).c_str(),
					NULL);

		}
		else /* Si la fait moins de 30ms depuis le dernier tour de boucle, on endort le programme le temps qu'il faut */
		{
			SDL_Delay(30 - (current_time - last_time));
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
	int i = 42;
	short s = numeric_cast<short> (i);
	/*SDL_Init(SDL_INIT_VIDEO);
	 flags = SDL_OPENGL;
	 SDL_SetVideoMode(hauteur, largeur, bits, flags);*/
	WindowManager fen(hauteur, largeur);
	SmartPtr<EventManager> E = new EventManager();
	setup_opengl(hauteur, largeur);
	draw_screen(E);
	return 0;
}

Object* cube()
{
	//si avec model
	Model* mod = new Model();
	//si sans model
	Object* obj;//= new Object();
	SmartPtr<Vertices> vert = obj->getNewVertices(QUAD);
	vert->push_back(new ColoredPoint(new Vector3f(1, 1, 1), new Color(1, 0, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, -1, 1), new Color(1, -3, 5)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, -1, 1), new Color(3, 1, -1)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, 1, 1), new Color(-1, -1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, 1, -1), new Color(1, 1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, -1, -1), new Color(-1, -1, -1)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, -1, -1), new Color(-1, -1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, 1, -1), new Color(-1, -1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, 1, 1), new Color(1, 0, -1)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, -1, 1), new Color(2, -1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, -1, -1), new Color(2, -1, 0)));//--ici on est obligé de remettre la meme couleur

	vert->push_back(
			new ColoredPoint(new Vector3f(1, 1, -1), new Color(-1, -1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, 1, 1), new Color(1, 3, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, -1, 1), new Color(-1, 4, -1)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, -1, -1), new Color(3, -1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, 1, -1), new Color(1, 0, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, 1, -1), new Color(-1, 0, 6)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, 1, 1), new Color(-1, 2, -2)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, 1, 1), new Color(1, -5, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, 1, -1), new Color(-1, -1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, -1, -1), new Color(-1, -1, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(-1, -1, 1), new Color(-1, -1, 0)));//--ici on est obligé de remettre la meme couleur

	vert->push_back(
			new ColoredPoint(new Vector3f(1, -1, 1), new Color(-3, 2, 0)));

	vert->push_back(
			new ColoredPoint(new Vector3f(1, -1, -1), new Color(-1, -2, 3)));
	//si sans model
	//	obj->setVertices(vert);
	//sinon avec model les 2 ligne suivant
	mod->setVertices(vert);
	obj = mod->creatObjet();
	return obj;

}
