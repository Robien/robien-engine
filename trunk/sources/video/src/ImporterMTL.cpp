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
 * 	Name File	: ImporterMTL.cpp
 *
 *  Created on	: 24 mai 2011
 *      Author	: céphise
 ***************************************/

#include "../include/ImporterMTL.h"

ImporterMTL::ImporterMTL()
{
	// TODO Auto-generated constructor stub

}

ImporterMTL::~ImporterMTL()
{
	// TODO Auto-generated destructor stub
}

//parser un fichier OBJ
void ImporterMTL::parse(Object* objet, const std::string& pathFileName)
{

	//Ouverture du fichier, et positionnement a la fin
	std::ifstream ifs((objet->getPath() +pathFileName).c_str(), std::ios::in | std::ios::ate);
	if (!ifs)
	{return;
	}//TODO throw(Exception); //ca n'a pas marché

	//recupere la taille du fichier
	const int fileSize = ifs.tellg();
	//positionne au debut du fichier
	ifs.seekg(0, std::ios::beg);

	if (0 == fileSize)
	{return;
	}//TODO throw Exception

	//commence l'analyse du fichier
	int percent = 10; //	indicateur de progression
	Material* mat = NULL;
	SmartPtr<ListMaterial> listMat = new ListMaterial();
	objet->add(listMat);

	while (skipCommentLine(ifs))
	{
		if ((fileSize > 1024 * 1024) && (100 * ifs.tellg() / fileSize >= percent))
		{
			percent = 100 * ifs.tellg() / fileSize;
			percent = (percent / 10) * 10;
			std::cout << "  " << percent << " % done...\n" << std::flush;
			percent += 10;
		}
		if (false == processLine(objet, mat, ifs))
			break;
	}
	if (mat != NULL)
	{
		std::vector<SmartPtr<ListAttribute> >* att = objet->GetAttributes();
		std::vector<SmartPtr<ListAttribute> >::reverse_iterator rit;
		for (rit = att->rbegin(); rit < att->rend(); ++rit)
		{
			if ((*rit)->getTypeAttribute() == MATERIAL)
				break;
		}
		((ListMaterial*) &(*(*rit)))->add(mat);
	}
	//fermeture du fichier
	ifs.close();
}

bool ImporterMTL::processLine(Object* objet, Material* mat, std::istream& is)
{
	std::string ele_id;
	float x, y, z;

	if (!(is >> ele_id))
		return false;

	if ("newmtl" == ele_id) //nom d'un matériau
	{
		std::string strMtlName;
		is >> strMtlName;
		if (mat == NULL)
		{
			mat = new Material(strMtlName);
		}
		else
		{
			std::vector<SmartPtr<ListAttribute> >* att = objet->GetAttributes();
			std::vector<SmartPtr<ListAttribute> >::reverse_iterator rit;
			for (rit = att->rbegin(); rit < att->rend(); ++rit)
			{
				if ((*rit)->getTypeAttribute() == MATERIAL)
					break;
			}
			((ListMaterial*) &(*(*rit)))->add(mat);
		}
	}
	else if ("map_Kd" == ele_id) //diffuse texture
	{
		std::string strMtlName;
		is >> strMtlName;
		mat->setDiffuseTexture(strMtlName);
	}
	else if ("d" == ele_id || "Tr" == ele_id) //transparent
	{
		is >> x;
		mat->setTransparency(x);
	}
	else if ("Kd" == ele_id) //diffuse
	{
		is >> x >> y >> z;
		mat->setDiffuse(x,y,z);
	}
	/*else if ("Ka" == ele_id) //ambiant
	{
		is >> x >> y >> z;
		mat->setAmbient(x,y,z);
	}*/
	/*else if ("Ks" == ele_id) //specular
	{
		is >> x >> y >> z;
				mat->setSpecular(x,y,z);
	}*/
	/*else if ("Ns" == ele_id) //specular Coefficient
	{
		is >> x;
		mat->setSpecularCoeff(x,y,z);
	}*/
	else
		skipLine(is);
	return true;
}

//	sauter une ligne
void ImporterMTL::skipLine(std::istream& is)
{
	char carac;
	is >> std::noskipws;
	while ((is >> carac) && ('\n' != carac))
		;
}

//	Sauter les ligne de commentaire
bool ImporterMTL::skipCommentLine(std::istream& is)
{
	char carac;
	while (is >> std::skipws >> carac)
	{
		is.putback(carac);
		if ('#' == carac)
			skipLine(is);
		else
			return true;
	}
	return false;
}

