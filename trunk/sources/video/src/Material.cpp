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
 * 	Name File	: Material.cpp
 *
 *  Created on	: 29 mai 2011
 *      Author	: céphise
 ***************************************/

#include "../include/Material.h"

Material::Material()
{
	// TODO Auto-generated constructor stub

}

Material::Material(std::string nameMat): name(nameMat)
{
}

Material::~Material()
{
}

void Material::setDiffuseTexture(std::string path)
{
	diffuseTexture = path;
}

/*void Material::setAmbient(float x,float y,float z)
{
	ambient->x = x;
	ambient->y = y;
	ambient->z = z;
}*/

void Material::setDiffuse(float x,float y,float z)
{
	diffuse->x = x;
	diffuse->y = y;
	diffuse->z = z;

}

/*void Material::setSpecular(float x,float y,float z)
{
	specular->x = x;
	specular->y = y;
	specular->z = z;
}*/

/*void Material::setSpecularCoeff(float speculcoef)
{
	specularCoeff = speculcoef;
}*/


void Material::setTransparency(float trans)
{
 transparency= trans;
}
