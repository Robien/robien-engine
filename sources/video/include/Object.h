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
 * 	Name File	: Object.h
 *
 *  Created on	: 17 mai 2011
 *      Author	: céphise
 ***************************************/

#ifndef OBJECT_H_
#define OBJECT_H_

#include <vector>
#include <deque>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../../utils/include/Referenced.h"
#include "../include/ListAttribute.h"
#include "../include/ListPoint.h"
#include "../include/ListFace.h"
#include "../../utils/include/SmartPtr.h"



class Object: public Referenced
{
public:
    Object();
    virtual ~Object();
    void add(ListAttribute* liste);
    void drawObject();
    void initialize();
    std::vector<SmartPtr<ListAttribute> >* GetAttributes();
    bool hasTextureVertices();
    bool hasVertexNormals();
    void setPath(std::string file);
    std::string getPath();

protected:
    void drawObjectVA();
    void drawObjectVBO();


private:

    std::string path;
    std::vector<SmartPtr<ListAttribute> > attributes;


};

#endif /* OBJECT_H_ */
