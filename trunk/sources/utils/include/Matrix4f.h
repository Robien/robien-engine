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
 * 	Name File	: Matrix4f.h
 *
 *  Created on	: 21 mai 2011
 *      Author	: Romain
 ***************************************/

#ifndef MATRIX4F_H_
#define MATRIX4F_H_
#include "../../utils/include/Referenced.h"
#include "../../utils/include/SmartPtr.h"

class Matrix4f: public Referenced
{
public:
    Matrix4f(float a11, float a21, float a31, float a41, float a12, float a22, float a32,
            float a42, float a13, float a23, float a33, float a43, float a14, float a24, float a34,
            float a44);

    Matrix4f( float mat[4][4]);
    Matrix4f(); // créé une matrice indéfinie.
    virtual ~Matrix4f();
public:

public: // en attendant de trouver mieux
    float mat[4][4];
};
Matrix4f* operator*(SmartPtr<Matrix4f> a, SmartPtr<Matrix4f> b);

#endif /* MATRIX4F_H_ */
