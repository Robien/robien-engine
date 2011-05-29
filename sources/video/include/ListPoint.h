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
 * 	Name File	: ListPoint.h
 *
 *  Created on	: 23 mai 2011
 *      Author	: Romain
 ***************************************/

#ifndef LISTPOINT_H_
#define LISTPOINT_H_

#include "ListAttribute.h"
#include "Point.h"
#include "../../utils/include/Vector3f.h"



class ListPoint: public ListAttribute
{
public:
    ListPoint();
    virtual ~ListPoint();
    float* getTab(int& size);
    void add(Point* point);//et ne fait pas chier
    void add(Vector3f* pos);
    void add(float x, float y, float z);

private:
    std::vector<float> positions;
};

#endif /* LISTPOINT_H_ */
