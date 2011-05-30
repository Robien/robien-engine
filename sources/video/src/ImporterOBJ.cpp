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
 * 	Name File	: ImporterOBJ.cpp
 *
 *  Created on	: 23 mai 2011
 *      Author	: céphise
 ***************************************/

#include "../include/ImporterOBJ.h"

ImporterOBJ::ImporterOBJ()
{
	// TODO Auto-generated constructor stub

}

ImporterOBJ::~ImporterOBJ()
{
	// TODO Auto-generated destructor stub
}

//parser un fichier OBJ
bool ImporterOBJ::parse(Object* objet, const std::string& pathFileName)
{

	//Ouverture du fichier, et positionnement a la fin
	std::ifstream ifs(pathFileName.c_str(), std::ios::in | std::ios::ate);
	if (!ifs)
	{
		return false;
	}//TODO throw(Exception); //ca n'a pas marché

	//recupere la taille du fichier
	const int fileSize = ifs.tellg();
	//positionne au debut du fichier
	ifs.seekg(0, std::ios::beg);

	if (0 == fileSize)
	{
		return false;
	}//TODO throw Exception

	objet->setPath(pathFileName);

	//commence l'analyse du fichier
	int percent = 10; //	indicateur de progression
	while (skipCommentLine(ifs))
	{
		if ((fileSize > 1024 * 1024) && (100 * ifs.tellg() / fileSize >= percent))
		{
			percent = 100 * ifs.tellg() / fileSize;
			percent = (percent / 10) * 10;
			std::cout << "  " << percent << " % done...\n" << std::flush;
			percent += 10;
		}

		if (false == processLine(objet, ifs))
			break;
	}

	//fermeture du fichier
	ifs.close();
	return true;
}

bool ImporterOBJ::processLine(Object* objet, std::istream& is)
{
	std::cout << "processLine" <<std::endl;
	std::string ele_id;
	float x, y, z;

	if (!(is >> ele_id))
		return false;

	if ("mtllib" == ele_id) //nom du .MTL, il faut le parcer
	{
		std::string pathFileName;
		is >> pathFileName;
		parseMtlFile(objet, pathFileName);
	}
	else if ("usemtl" == ele_id) //nom d'un matériau
	{
		std::string strMtlName;
		is >> strMtlName;
		SmartPtr<ListFace> face = new ListFace();
		face->setNameMtl(strMtlName);
		objet->add(face);
		//map<std::string, SMaterial>::iterator it = m_materialMap.find(strMtlName);
		//if (it != m_materialMap.end())
		//	pMesh->setMaterial((*it).second);
		//else
		//	CLogger::get() << "  * Material not found in current mtllib :\"" << strMtlName << "\". Ignoring material.\n";
	}
	else if ("v" == ele_id) //coordonnée d'un sommet, ajouter au Mesh
	{
		std::vector<SmartPtr<ListAttribute> >* att = objet->GetAttributes();
		std::vector<SmartPtr<ListAttribute> >::reverse_iterator rit;
		for (rit = att->rbegin(); rit < att->rend(); ++rit)
		{
			if ((*rit)->getTypeAttribute() == VERTICES)
				break;
		}
		if (rit >= att->rend())
		{
			SmartPtr<ListPoint> vert = new ListPoint();
			objet->add(vert);
			rit = att->rbegin();
		}
		is >> x >> y >> z;

		((ListPoint*) &(*(*rit)))->add(x, y, z);
		//pMesh->addVertex(SVertex(x, y, z));
	}
	else if ("vt" == ele_id) //coordonnée de texture
	{
		/*TODO debug
		std::vector<SmartPtr<ListAttribute> >* att = objet->GetAttributes();
		std::vector<SmartPtr<ListAttribute> >::reverse_iterator rit;
		for (rit = att->rbegin(); rit < att->rend(); ++rit)
		{
			if ((*rit)->getTypeAttribute() == TEXTURE_VERTICES)
				break;
		}
		if (rit >= att->rend())
		{
			SmartPtr<ListTextureVertices> vert = new ListTextureVertices();
			objet->add(vert);
			rit = att->rbegin();
		}
		is >> x >> y >> z;
		is.clear(); // is z (i.e. w) is not available, have to clear error flag.
		((ListTextureVertices*) &(*(*rit)))->add(x, y);
		//pMesh->addTextureCoord(SVertex(x, y, z));
		 */
	}
	else if ("vn" == ele_id) //coordonnée de la normale
	{
		/*TODO debug
		 std::cout << "vn" << std::endl;
		std::vector<SmartPtr<ListAttribute> >* att = objet->GetAttributes();
		std::vector<SmartPtr<ListAttribute> >::reverse_iterator rit;
		for (rit = att->rbegin(); rit < att->rend(); ++rit)
		{
			if ((*rit)->getTypeAttribute() == VERTEX_NORMALS)
				break;
		}
		if (rit >= att->rend())
		{
			SmartPtr<ListVertexNormals> vert = new ListVertexNormals();
			objet->add(vert);
			rit = att->rbegin();
		}
		is >> x >> y >> z;
		if (!is.good())
		{ // in case it is -1#IND00
			x = y = z = 0.0;
			is.clear();
			skipLine(is);
		}
		((ListVertexNormals*) &(*(*rit)))->add(x, y, z);
		//pMesh->addNormal(SVertex(x, y, z));
		 */
	}
	else if ("f" == ele_id) // information sur une face pour un matériau
	{
		std::vector<SmartPtr<ListAttribute> >* att = objet->GetAttributes();
		std::vector<SmartPtr<ListAttribute> >::reverse_iterator rit;
		for (rit = att->rbegin(); rit < att->rend(); ++rit)
		{
			if ((*rit)->getTypeAttribute() == FACE)
				break;
		}
		if (rit >= att->rend())
		{
			SmartPtr<ListFace> face = new ListFace();
			objet->add(face);
			rit = att->rbegin();
		}
		//  Marche pour des polygones de 10 coordonée maximum
		unsigned int vi[10]; // vertex indices.
		unsigned int ni[10] =
		{ -1, -1, -1, -1, }; // normal indices.
		unsigned int ti[10] =
		{ -1, -1, -1, -1, }; // tex indices.
		int i = 0;
		bool hasTex = objet->hasTextureVertices();
		bool hasNor = objet->hasVertexNormals();

		for (char c; i < 10; ++i)
		{
			if (!hasTex && !hasTex)
				is >> vi[i];
			else if (!hasTex)
				is >> vi[i] >> c >> c >> ni[i];
			else if (!hasTex)
				is >> vi[i] >> c >> ti[i];
			else
				is >> vi[i] >> c >> ti[i] >> c >> ni[i];
			if (!is.good())
				break;
		}

		//Ajouter le type de face
		((ListFace*) &(*(*rit)))->setType(i + 1);
		//ajouter les indices de la nouvelle face
		((ListFace*) &(*(*rit)))->addIndexVertices(vi, i + 1);
		if (hasTex)
			((ListFace*) &(*(*rit)))->addIndexNormal(ni, i + 1);
		if (hasNor)
			((ListFace*) &(*(*rit)))->addIndexTexture(ti, i + 1);

		is.clear();
	}
	else
		skipLine(is);
	return true;
}


void ImporterOBJ::parseMtlFile(Object* objet, const std::string& strFileName)
{//TODO

	//ImporterMTL::parse(objet, strFileName);

}

//	sauter une ligne
void ImporterOBJ::skipLine(std::istream& is)
{
	char carac;
	is >> std::noskipws;
	while ((is >> carac) && ('\n' != carac))
		;
}

//	Sauter les ligne de commentaire
bool ImporterOBJ::skipCommentLine(std::istream& is)
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
