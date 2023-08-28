/**
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
 *
 * @mainpage BLI - Blender LIbrary external interface
 *
 * @section about About the BLI module
 *
 * This is the external interface of the Blender Library. If you find
 * a call to a BLI function that is not prototyped here, please add a
 * prototype here. The library offers mathematical operations (mainly
 * vector and matrix calculus), an abstraction layer for file i/o,
 * functions for calculating Perlin noise, scanfilling services for
 * triangles, and a system for guarded memory
 * allocation/deallocation. There is also a patch to make MS Windows
 * behave more or less Posix-compliant.
 *
 * @section issues Known issues with BLI
 *
 * - blenlib is written in C.
 * - The posix-compliancy may move to a separate lib that deals with 
 *   platform dependencies. (There are other platform-dependent 
 *   fixes as well.)
 * - The file i/o has some redundant code. It should be cleaned.
 * - arithb.c is a very messy matrix library. We need a better 
 *   solution.
 * - vectorops.c is close to superfluous. It may disappear in the 
 *   near future.
 * 
 * @section dependencies Dependencies
 *
 * - The blenlib uses type defines from makesdna/, and functions from
 * standard libraries.
 * 
 * $Id$ 
*/

#ifndef BLI_BLENLIB_H
#define BLI_BLENLIB_H

/**
 * Set a function taking a char* as argument to flag errors. If the 
 * callback is not set, the error is discarded.
 * @param f The function to use as a callback
 * @attention used in creator.c
 */
void BLI_setErrorCallBack(void (*f)(char*));

/**
 * Set a function to be able to intterupt the execution of processing
 * in this module. If the function returns true, the execution will
 * terminate gracefully. If the callback is not set, interruption is
 * not possible.
 * @param f The function to use as a callback
 * @attention used in creator.c
 */
void BLI_setInterruptCallBack(int (*f)(void));

#endif /* BLI_BLENLIB_H */