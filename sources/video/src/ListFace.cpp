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
 * 	Name File	: ListFace.cpp
 *
 *  Created on	: 24 mai 2011
 *      Author	: céphise
 ***************************************/

#include "../include/ListFace.h"

ListFace::ListFace() :
	nameObjet(""), nameMtl("")
{
	typeAttribute = FACE;
}

ListFace::~ListFace()
{
	// TODO Auto-generated destructor stub
}

void ListFace::addIndexVertices(unsigned int num)
{
	indexVertices.push_back(num);
}
//unsigned int* ListFace::getTab()
//{
//    return index.get_allocator();
//}

void ListFace::addIndexVertices(unsigned int* num, int taille)
{
	for (unsigned int i = 0; i < taille; ++i)
	{
		indexVertices.push_back(num[i]);
	}
}
void ListFace::addIndexVertices(std::vector<unsigned int>& num)
{
	for (unsigned int i = 0; i < num.size(); ++i)
	{
		indexVertices.push_back(num[i]);
	}
}
void ListFace::setIndexVertices(unsigned int* num, int taille)
{
	indexVertices.clear();
	addIndexVertices(num, taille);

}
void ListFace::setIndexVertices(std::vector<unsigned int>& num)
{
	indexVertices.clear();
	addIndexVertices(num);
}

unsigned int* ListFace::getTabIndex(int &size)
{
	size = indexVertices.size();
	unsigned int* tab = new unsigned int[size];
	for (int i = 0; i < size; ++i)
	{
		tab[i] = indexVertices[i];
	}
	return tab;
}

void ListFace::addIndexNormal(unsigned int num)
{
	indexVertices.push_back(num);
}

void ListFace::addIndexTexture(unsigned int num)
{
	indexVertices.push_back(num);
}

void ListFace::addIndexNormal(unsigned int* num, int taille)
{
	for (unsigned int i = 0; i < taille; ++i)
	{
		indexVertices.push_back(num[i]);
	}
}

void ListFace::addIndexTexture(unsigned int* num, int taille)
{
	for (unsigned int i = 0; i < taille; ++i)
	{
		indexVertices.push_back(num[i]);
	}
}

void ListFace::setNameObjet(std::string& name)
{
	nameObjet = name;
}

void ListFace::setNameMtl(std::string& name)
{
	nameMtl = name;
}

void ListFace::setType(int tp)
{
	switch (tp)
	{
	case 1:
		type = POINT;
		break;
	case 3:
		type = TRIANGLE;
		break;
	case 4:
		type = QUAD;
		break;
	default:
		type = POLYGON;
		break;
	}
}

TypeVertex ListFace::getType()
{
	return type;
}
