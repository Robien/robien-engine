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
 * 	Name File	: ListAttribute.cpp
 *
 *  Created on	: 23 mai 2011
 *      Author	: Romain
 ***************************************/

#include "../include/ListAttribute.h"

ListAttribute::ListAttribute()
{
}

ListAttribute::~ListAttribute()
{
}

void ListAttribute::addIndex(unsigned int num)
{
    index.push_back(num);
}
//unsigned int* ListAttribute::getTab()
//{
//    return index.get_allocator();
//}
void ListAttribute::addIndex(unsigned int* num, int taille)
{
    for (unsigned int i = 0; i < taille; ++i)
    {
        index.push_back(num[i]);
    }
}
void ListAttribute::addIndex(std::vector<unsigned int> num)
{
    for (unsigned int i = 0; i < num.size(); ++i)
    {
        index.push_back(num[i]);
    }
}
void ListAttribute::setIndex(unsigned int* num, int taille)
{
    index.clear();
    addIndex(num, taille);

}
void ListAttribute::setIndex(std::vector<unsigned int> num)
{
    index.clear();
    addIndex(num);
}