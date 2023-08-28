/**
 * blenlib/DNA_ID.h (mar-2001 nzc)
 *
 * ID and Library types, which are fundamental for sdna, 
 *
 * $Id$ 
 *
 * ***** BEGIN GPL/BL DUAL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. The Blender
 * Foundation also sells licenses for use in proprietary software under
 * the Blender License.  See http://www.blender.org/BL/ for information
 * about this.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL/BL DUAL LICENSE BLOCK *****
 */
#ifndef DNA_ID_H
#define DNA_ID_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * There's nasty circular dependecy here... void* to the rescue! I
 * really wonder why this is here.
 */
struct Library;
struct FileData;

/**
 * ID is the first thing included in all serializable types. It 
 * provides a common handle to place all data in double-linked lists. 
 **/
typedef struct ID
{
    void *next, *prev;
    struct ID *newid;
    struct Library *Lib;
    char name[24];
    short us;
    /**
     * LIB_... flags report on status of the datablock this ID belongs
     * to.
     */
    short flag;
    int pad;
} ID;

/**
 * ???
 */
typedef struct Library
{
    ID id;
    ID *idblock;
    struct FileData *filedata;
    char name[160];
    int tot, pad;   /* tot and idblock are file data for reading and writing */
} Library;

#ifdef __cplusplus
}
#endif

#endif /* DNA_ID_H */