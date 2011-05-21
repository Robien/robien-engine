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
 * 	Name File	: Matrix4f.cpp
 *
 *  Created on	: 21 mai 2011
 *      Author	: Romain
 ***************************************/

#include "../include/Matrix4f.h"

Matrix4f::Matrix4f(float a11, float a21, float a31, float a41, float a12, float a22, float a32,
        float a42, float a13, float a23, float a33, float a43, float a14, float a24, float a34,
        float a44)
{
    mat[0][0] = a11;
    mat[1][0] = a21;
    mat[2][0] = a31;
    mat[3][0] = a41;
    mat[0][1] = a12;
    mat[1][1] = a22;
    mat[2][1] = a32;
    mat[3][1] = a42;
    mat[0][2] = a13;
    mat[1][2] = a23;
    mat[2][2] = a33;
    mat[3][2] = a43;
    mat[0][3] = a14;
    mat[1][3] = a24;
    mat[2][3] = a34;
    mat[3][3] = a44;

}

Matrix4f::Matrix4f(float mat[4][4])
{
    for (int i = 0; i < 4; ++i)
    {

        for (int j = 0; j < 4; ++j)
        {
            this->mat[i][j] = mat[i][j];
        }
    }
}
Matrix4f::Matrix4f()
{
}

Matrix4f::~Matrix4f()
{
}



Matrix4f* operator*(SmartPtr<Matrix4f> a, SmartPtr<Matrix4f> b)
{
    Matrix4f* tmp;
    for (int i = 0; i < 4; ++i)
    {

        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                tmp->mat[i][j] += a->mat[i][k] * b->mat[k][j];
            }
        }
    }
    return tmp;
}
