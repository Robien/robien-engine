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
 * 	Name File	: Object.cpp
 *
 *  Created on	: 17 mai 2011
 *      Author	: c�phise
 ***************************************/

#include "../include/Object.h"
#include "../include/ColoredPoint.h"

Object::Object(TypeVertex type) :
    type(type)
{
}

Object::~Object()
{
}

void Object::add(ListAttribute* liste)
{
    attributes.push_back(liste);
}

void Object::drawObject()
{

    switch (type)
    {
    case POINT:

        drawObjectPoint();
        break;
    case LINE:
        drawObjectLine();
        break;
    case LINE_LOOP:
        drawObjectLine(true);
        break;
    case TRIANGLE:
        drawObjectTriangle();
        break;
    case QUAD:
        drawObjectQuad();
        break;
    }

}

void Object::drawObjectPoint()
{
//    glBegin(GL_POINTS);
//    for (std::deque<SmartPtr<ColoredPoint> >::iterator i = vertices->begin(); i < vertices->end(); i++)
//    {
//        glColor3d((*i)->getRed(), (*i)->getGreen(), (*i)->getBlue());
//        glVertex3i((*i)->getPosition()->x, (*i)->getPosition()->y, (*i)->getPosition()->z);
//    }
//
//    glEnd();
}

void Object::drawObjectLine(bool loop)
{
//    glBegin(loop ? GL_LINE_STRIP : GL_LINE_LOOP);
//    for (std::deque<SmartPtr<ColoredPoint> >::iterator i = vertices->begin(); i < vertices->end(); ++i)
//    {
//        glColor3d((*i)->getRed(), (*i)->getGreen(), (*i)->getBlue());
//        glVertex3i((*i)->getPosition()->x, (*i)->getPosition()->y, (*i)->getPosition()->z);
//    }
//    glEnd();
}

void Object::drawObjectTriangle()
{
//    glBegin(GL_TRIANGLES);
//    for (std::deque<SmartPtr<ColoredPoint> >::iterator i = vertices->begin(); i < vertices->end(); ++i)
//    {
//        glColor3d((*i)->getRed(), (*i)->getGreen(), (*i)->getBlue());
//        glVertex3i((*i)->getPosition()->x, (*i)->getPosition()->y, (*i)->getPosition()->z);
//    }
//    glEnd();
}

void Object::drawObjectQuad()
{
//    glBegin(GL_QUADS);
//    for (std::deque<SmartPtr<ColoredPoint> >::iterator i = vertices->begin(); i < vertices->end(); ++i)
//    {
//        glColor3d((*i)->getRed(), (*i)->getGreen(), (*i)->getBlue());
//        glVertex3i((*i)->getPosition()->x, (*i)->getPosition()->y, (*i)->getPosition()->z);
//    }
//    glEnd();
}
