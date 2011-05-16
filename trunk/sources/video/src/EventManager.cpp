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
 * 	Name File	: EventManager.cpp
 *
 *  Created on	: 13 mai 2011
 *      Author	: cephise
 ***************************************/

#include "../include/EventManager.h"

EventManager::EventManager()
{
	// TODO Auto-generated constructor stub

}

EventManager::~EventManager()
{
	// TODO Auto-generated destructor stub
}

void EventManager::EM_EnableKeyRepeat(int delay, int interval)
{
	SDL_EnableKeyRepeat(delay, interval);
}

void EventManager::EM_DisableKeyRepeat()
{
	SDL_EnableKeyRepeat(0, 0);
}

bool EventManager::EM_Quit()
{
	/* Récupèration de l'évènement dans event */
	SDL_PollEvent(&event);
	return (event.type == SDL_QUIT);
}

bool EventManager::EM_QuitB()
{
	/* Récupèration de l'évènement dans event */
	SDL_WaitEvent(&event);
	return (event.type == SDL_QUIT);

}

bool EventManager::EM_MouseDown(int button)
{
	/* Récupèration de l'évènement dans event */
	SDL_PollEvent(&event);
	return (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == button);

}

bool EventManager::EM_MouseUp(int button)
{
	/* Récupèration de l'évènement dans event */
		SDL_PollEvent(&event);
		return (event.type == SDL_MOUSEBUTTONUP && event.button.button == button);
}

bool EventManager::EM_KeyDown(SDLKey key)
{
	/* Récupèration de l'évènement dans event */
	SDL_PollEvent(&event);
	return (event.type == SDL_KEYDOWN && event.key.keysym.sym == key);

}

bool EventManager::EM_KeyDownB(SDLKey key)
{
	/* Récupèration de l'évènement dans event */
	SDL_WaitEvent(&event);
	return (event.type == SDL_KEYDOWN && event.key.keysym.sym == key);

}

bool EventManager::EM_KeyUp(SDLKey key)
{
	/* Récupèration de l'évènement dans event */
	SDL_PollEvent(&event);
	return (event.type == SDL_KEYUP && event.key.keysym.sym == key);

}

bool EventManager::EM_KeyUpB(SDLKey key)
{
	/* Récupèration de l'évènement dans event */
	SDL_WaitEvent(&event);
	return (event.type == SDL_KEYUP && event.key.keysym.sym == key);
}

