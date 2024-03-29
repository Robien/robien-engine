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
 *	Project		: RobienEngine
 * 	Name File	: Model.h
 *
 *  Created on	: 17 mai 2011
 *      Author	: c�phise
 ***************************************/

#ifndef MODEL_H_
#define MODEL_H_

#include <list>
#include "../../utils/include/Referenced.h"
#include "../include/Object.h"
#include "../include/Vertices.h"

class Model: public Referenced
{
public:
	Model();
	virtual ~Model();

	//Assigns new list attribute to the model
	void add(ListAttribute* liste);
	//creates an object from the attributes of the model, this object is linked to model
	Object* creatObjet();

private:
	std::list<SmartPtr<Object> > linkingObjects;
	std::vector<SmartPtr<ListAttribute> > attributes;
	TypeVertex type;
};

#endif /* MODEL_H_ */
