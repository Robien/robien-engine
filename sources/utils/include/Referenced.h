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
 *	Project		: robien-engine
 * 	Name File	: Referenced.h
 *
 *  Created on	: 17 mai 2011
 *      Author	: Romain
 ***************************************/

#ifndef REFERENCED_H_
#define REFERENCED_H_

#include <boost/intrusive_ptr.hpp>

class Referenced
{
public:
    Referenced();
    virtual ~Referenced();
    friend void intrusive_ptr_add_ref(Referenced* p)
    {
        ++p->references;
    }
    friend void intrusive_ptr_release(Referenced* p)
    {
        if (--p->references == 0)
            delete p;
    }
    inline unsigned int getNombreReference()
    {
        return references;
    }
    inline bool exist()
    {
        return references > 0;
    }
    inline bool isUndefined()
    {
        return references == 0;
    }

protected:
    Referenced& operator=(const Referenced&)
    {
        return *this;
    }
private:
    Referenced(const Referenced& other);

private:
    unsigned int references;
};

#endif /* REFERENCED_H_ */
