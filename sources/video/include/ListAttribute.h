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

enum TypeVertex
{
    POINT =0, LINE = 1, LINE_LOOP = 2, TRIANGLE = 4, QUAD = 7, POLYGON = 9
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
