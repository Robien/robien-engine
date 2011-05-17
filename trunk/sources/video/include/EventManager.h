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
 * 	Name File	: EventManager.h
 *
 *  Created on	: 13 mai 2011
 *      Author	: cephise
 ***************************************/

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include <SDL/SDL.h>
#include "../../utils/include/Referenced.h"

/*
 *Class EventManager
 */
class EventManager : public Referenced
{
public:
	EventManager();
	virtual ~EventManager();

	//Setting
	void EM_EnableKeyRepeat(int delay, int interval);
	void EM_DisableKeyRepeat();
	//Catch Event

	/**/
	bool EM_Quit();
	/*bloquant*/
	bool EM_QuitB();
	/**/
	bool EM_MouseDown(int button);
	/**/
	bool EM_MouseUp(int button);
	/**/
	bool EM_KeyDown(SDLKey);
	/*bloquant*/
	bool EM_KeyDownB(SDLKey);
	/**/
	bool EM_KeyUp(SDLKey);
	/*bloquant*/
	bool EM_KeyUpB(SDLKey);

private:
	SDL_Event event;
};

#endif /* EVENTMANAGER_H_ */
