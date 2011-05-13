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
#include <iostream>
#include "../include/WindowManager.h"
#include "../include/EventManager.h"

int etape = 0;
//SDL_Event event;
void draw_screen(EventManager* E)
{
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
		glBegin(GL_QUADS);
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
		glEnd();
		SDL_GL_SwapBuffers();
		//SDL_PollEvent(&event);
		if (E->EM_Quit() || E->EM_KeyDown(SDLK_ESCAPE))
		{
			return;
		}
		/*if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			//SDL_Quit();
			return;
		}*/
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
	int hauteur = 800;
	int largeur = 600;
	int bits = 32;
	int flags = 0;
	/*SDL_Init(SDL_INIT_VIDEO);
	flags = SDL_OPENGL;
	SDL_SetVideoMode(hauteur, largeur, bits, flags);*/
	WindowManager fen(hauteur, largeur);
	EventManager* E = new EventManager();
	setup_opengl(hauteur, largeur);
	draw_screen(E);
	return 0;
}

