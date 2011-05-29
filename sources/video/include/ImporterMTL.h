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
 * 	Name File	: ImporterMTL.h
 *
 *  Created on	: 24 mai 2011
 *      Author	: céphise
 ***************************************/

#ifndef IMPORTERMTL_H_
#define IMPORTERMTL_H_

#include <fstream>
#include "../include/Object.h"
#include "../../utils/include/Referenced.h"
#include "../include/ListMaterial.h"
#include "../include/Material.h"



class ImporterMTL: public Referenced
{
public:
	ImporterMTL();
	virtual ~ImporterMTL();
	static void parse(Object* objet, const std::string& strFileName);
private:
	static bool	processLine(Object* objet, Material* mat, std::istream& is);
	static void	skipLine(std::istream& is);
	static bool	skipCommentLine(std::istream& is);
};

#endif /* IMPORTERMTL_H_ */
