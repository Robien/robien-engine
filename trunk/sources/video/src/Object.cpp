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
 * 	Name File	: Object.cpp
 *
 *  Created on	: 17 mai 2011
 *      Author	: céphise
 ***************************************/

#include "../include/Object.h"
#include "../include/ColoredPoint.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::add(ListAttribute* liste)
{
	attributes.push_back(liste);
}

void Object::drawObject()
{
	drawObjectVA();

}

void Object::drawObjectVA()
{
	glEnableClientState(GL_VERTEX_ARRAY);

	std::vector<SmartPtr<ListAttribute> >::iterator it;
	for (it = attributes.begin(); it < attributes.end(); ++it)
	{
		if ((*it)->getTypeAttribute() == VERTICES)
			break;
	}
	int size;
	float* tab = ((ListPoint*) &(*(*it)))->getTab(size);
	glVertexPointer(3, GL_FLOAT, 0, tab);

	int sizeind;
	for (it = attributes.begin(); it < attributes.end(); ++it)
	{
		if ((*it)->getTypeAttribute() == FACE)
		{
			unsigned int* index = ((ListFace*) &(*(*it)))->getTabIndex(sizeind);
			glDrawElements(((ListFace*) &(*(*it)))->getType(), sizeind, GL_UNSIGNED_INT, index);
		}

	}
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Object::drawObjectVBO()
{

}

std::vector<SmartPtr<ListAttribute> >* Object::GetAttributes()
{
	return &attributes;
}

bool Object::hasTextureVertices()
{
	std::vector<SmartPtr<ListAttribute> >::iterator it;
	for (it = attributes.begin(); it < attributes.end(); ++it)
	{
		if ((*it)->getTypeAttribute() == TEXTURE_VERTICES)
			return true;
	}
	return false;
}

bool Object::hasVertexNormals()
{
	std::vector<SmartPtr<ListAttribute> >::iterator it;
	for (it = attributes.begin(); it < attributes.end(); ++it)
	{
		if ((*it)->getTypeAttribute() == VERTEX_NORMALS)
			return true;
	}
	return false;
}

void Object::setPath(std::string file)
{
	std::string s1 = "", s2 = "";
	for (unsigned int i = 0; i < file.size(); i++)
	{
		if (file[i] == '/' || file[i] == '\\')
		{
			s1 += s2 + "/";
			s2 = "";
		}
		else
			s2 += file[i];
	}
	path = s1;

}
std::string Object::getPath()
{
	return path;
}



