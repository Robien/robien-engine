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
 * 	Name File	: ListAttribute.h
 *
 *  Created on	: 23 mai 2011
 *      Author	: Romain
 ***************************************/

#ifndef LISTATTRIBUTE_H_
#define LISTATTRIBUTE_H_

#include <vector>
#include "../../utils/include/Referenced.h"
#include <GL/gl.h>

enum TypeVertex
{
    POINT = GL_POINTS, LINE = GL_LINES, LINE_LOOP = GL_LINE_LOOP, TRIANGLE = GL_TRIANGLES, QUAD = GL_QUADS, POLYGON = GL_POLYGON
};
enum TypeAttribute
{
    VERTICES, FACE, TEXTURE_VERTICES, VERTEX_NORMALS, COLOR, MATERIAL
};

class ListAttribute: public Referenced
{
public:
    ListAttribute();
    virtual ~ListAttribute();

    virtual TypeAttribute getTypeAttribute();

protected:
    TypeAttribute typeAttribute;

};

#endif /* LISTATTRIBUTE_H_ */
