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
 * 	Name File	: Material.h
 *
 *  Created on	: 29 mai 2011
 *      Author	: céphise
 ***************************************/

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../../utils/include/Referenced.h"
#include "../../utils/include/Vector3f.h"
#include "../../utils/include/SmartPtr.h"
#include <iostream>

class Material: public Referenced
{
public:
	Material();
	Material(std::string nameMat);
	virtual ~Material();

	void setDiffuseTexture(std::string path);
	//void setAmbient(float x,float y,float z);
	void setDiffuse(float x,float y,float z);
	//void setSpecular(float x,float y,float z);
	//void setSpecularCoeff(float speculcoef);
	void setTransparency(float trans);

private:
	 std::string name;
	 std::string diffuseTexture;
	 SmartPtr<Vector3f> ambient;
	 SmartPtr<Vector3f> diffuse;

	 //SmartPtr<Vector3f> specular;
	 //float specularCoeff;
	 float transparency;

};

#endif /* MATERIAL_H_ */
