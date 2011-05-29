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
 * 	Name File	: ListTextureVertices.h
 *
 *  Created on	: 24 mai 2011
 *      Author	: c�phise
 ***************************************/

#ifndef LISTTEXTUREVERTICES_H_
#define LISTTEXTUREVERTICES_H_

#include "ListAttribute.h"

class ListTextureVertices: public ListAttribute
{
public:
	ListTextureVertices();
	virtual ~ListTextureVertices();
	void add(float x, float y);
private :
    std::vector<float> positions;
};

#endif /* LISTTEXTUREVERTICES_H_ */
