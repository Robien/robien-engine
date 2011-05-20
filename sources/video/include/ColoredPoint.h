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
 * 	Name File	: ColoredPoint.h
 *
 *  Created on	: 19 mai 2011
 *      Author	: Romain
 ***************************************/

#ifndef COLOREDPOINT_H_
#define COLOREDPOINT_H_

#include "Point.h"
#include "../include/Color.h"

class ColoredPoint: public Point
{
public:
    ColoredPoint(Vector3f* position, Color* color);
    ColoredPoint(ColoredPoint* coloredPoint);
    virtual ~ColoredPoint();
    Color* getColor();
    int getRed();
	int getGreen();
	int getBlue();
private:
    SmartPtr<Color> color;
};

#endif /* COLOREDPOINT_H_ */
