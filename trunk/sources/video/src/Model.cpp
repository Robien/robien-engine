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
 * 	Name File	: Model.cpp
 *
 *  Created on	: 17 mai 2011
 *      Author	: c�phise
 ***************************************/

#include "../include/Model.h"

Model::Model()
{
}

Model::~Model()
{
}


void Model::add(ListAttribute* liste)
{
    attributes.push_back(liste);
}

//creates an object from the vertices of the model, this object is linked to model
Object* Model::creatObjet()
{
	/*Object* newObj = new Object(vertices->getType());
	SmartPtr<Vertices> newVer = new Vertices(vertices);
	//SmartPtr<Vertices> newVer = new Vertices(vertices->getType());
	//newVer->copyVertices(vertices);
	//newObj->setVertices(newVer);
	linkingObjects.push_back(newObj);
	return newObj;
*/
	return NULL;
}
