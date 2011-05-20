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
 * 	Name File	: Color.h
 *
 *  Created on	: 19 mai 2011
 *      Author	: Romain
 ***************************************/

#ifndef COLOR_H_
#define COLOR_H_
#include "../../utils/include/Referenced.h"

class Color: public Referenced
{
public:
    Color(int red, int green, int blue);
    Color(Color* color);
    virtual ~Color();
    int getRed();
    int getGreen();
    int getBlue();
private:
    int red;
    int green;
    int blue;
};

#endif /* COLOR_H_ */
