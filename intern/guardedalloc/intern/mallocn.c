/**
 * $Id$
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

/**

 * $Id$
 * Copyright (C) 2001 NaN Technologies B.V.
 * Guarded memory allocation, and boundary-write detection.
 */

#include <stdlib.h>

#include "MEM_guardedalloc.h"

/* ----------------------------------------------------------- */
/* Data defition                                               */
/* ------------------------------------------------------------*/
/* all memory chunks are put in linked */
typedef struct localLink
{
    struct localLink *next, *prev;
} localLink;

typedef struct localListbase
{
    void *first, *last;
} localListBase;

typedef struct MemHead
{
    int tag1;
    int len;
    struct MemHead *next, *prev;
    char * name;
    char * nextname;
    /* int level; */ /* historical, can be removed, but check alignment issues */
    int tag2;
} MemHead;

typedef struct MemTail
{
    int tag3, pad;
} MemTail;

/* ----------------------------------------------------------- */
/* local functions                                             */
/* ------------------------------------------------------------*/

static void addtail(localListBase *listbase, void *vlink);
static void remlink(localListBase *listbase, void *vlink);
static void rem_memblock(MemHead *memh);
static void MemorY_ErroR(char *block, char *erro);
static char *check_memlist(MemHead *memh);

/* ----------------------------------------------------------- */
/* locally used defines                                        */
/* ------------------------------------------------------------*/

#define MAKE_ID(a,b,c,d) ( (int)(a)<<24 | (int)(b)<<16 | (c)<<8 | (d) )

/* ----------------------------------------------------------- */
/* vars                                                        */
/* ------------------------------------------------------------*/

static FILE* err_stream = NULL;

/* ----------------------------------------------------------- */
/* implementation                                              */
/* ------------------------------------------------------------*/

void MEM_set_error_stream(FILE* i)
{
    err_stream = i;
}