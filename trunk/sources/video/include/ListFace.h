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
 * 	Name File	: ListFace.h
 *
 *  Created on	: 24 mai 2011
 *      Author	: céphise
 ***************************************/

#ifndef LISTFACE_H_
#define LISTFACE_H_

#include "ListAttribute.h"
#include <iostream>

class ListFace: public ListAttribute
{
public:
	ListFace();
	virtual ~ListFace();
	//    unsigned int* getTab();
    void addIndexVertices(unsigned int num);
    void addIndexVertices(unsigned int* num, int taille);
    void addIndexVertices(std::vector<unsigned int>& num);
    void setIndexVertices(unsigned int* num, int taille);
    void setIndexVertices(std::vector<unsigned int>& num);
    unsigned int* getTabIndex(int &size);
    void addIndexTexture(unsigned int* num, int taille);
    void addIndexTexture(unsigned int num);

    void addIndexNormal(unsigned int* num, int taille);
    void addIndexNormal(unsigned int num);

    void setNameObjet(std::string& name);
    void setNameMtl(std::string& name);
    void setType(int tp);
    TypeVertex getType();

private:
	 std::vector<unsigned int> indexVertices;
	 std::vector<unsigned int> indexTexture;
	 std::vector<unsigned int> indexNormal;
	 std::string nameObjet;
	 std::string nameMtl;
	 TypeVertex type;
};

#endif /* LISTFACE_H_ */
