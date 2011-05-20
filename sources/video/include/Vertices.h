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
 * 	Name File	: Vertices.h
 *
 *  Created on	: 19 mai 2011
 *      Author	: Romain
 ***************************************/

#ifndef VERTICES_H_
#define VERTICES_H_

#include <deque>
#include "../../utils/include/Referenced.h"
#include "../include/ColoredPoint.h"

enum TypeVertex
{
    POINT, LINE, TRIANGLE, QUAD
};

class Vertices: public std::deque<SmartPtr<ColoredPoint> >, public Referenced
{
public:
    Vertices(TypeVertex type);
    virtual ~Vertices();

    TypeVertex getType();
    //copy the vertex set parameter in the vertices
    void copyVertices(Vertices* src);

private:
    TypeVertex type;
};

#endif /* VERTICES_H_ */
