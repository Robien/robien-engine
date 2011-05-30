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
void Object::initialize()
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

	glDisableClientState(GL_VERTEX_ARRAY);

}

void Object::drawObjectVA()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	std::cout << "draw int" << std::endl;
	std::vector<SmartPtr<ListAttribute> >::iterator it;
	int sizeind;
	for (it = attributes.begin(); it < attributes.end(); ++it)
	{std::cout << "draw for" << std::endl;
		if ((*it)->getTypeAttribute() == FACE)
		{std::cout << "draw forif1" << std::endl;
			unsigned int* index = ((ListFace*) &(*(*it)))->getTabIndex(sizeind);
			std::cout << "draw forif2" << std::endl;
			glDrawElements(((ListFace*) &(*(*it)))->getType(), sizeind, GL_UNSIGNED_INT, index);
			std::cout << "draw forif3" << std::endl;
		}

	}
	std::cout << "draw out" << std::endl;
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

