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
 */

#define PY_TOOLBOX 1

#include <stdarg.h>
#include <stdio.h>

#include "BKE_global.h"

#include "BIF_interface.h"

/*  ******* NOTES  ************* **********************************
    - Complete toolbox items youself
    - the colourmap colours are with comments in the bgntoolbox()
    - possibly replace the extern_qread function
    - note the names of special keys (Num: etc)
    - link: Button.c related to rawcodes
    ******* NOTES  ************* **********************************
*/

static int vconfirm(char *title, char *itemfmt, va_list ap)
{
    char *s, buf[512];

    s = buf;

    if(title) 
    {
        s += sprintf(s, "%s%%t|", title);
    }

    vsprintf(s, itemfmt, ap);

    return (pupmenu(buf) >= 0);
}

void error(char *fmt, ...)
{
    va_list ap;
    char nfmt[256];

    sprintf(nfmt, "%s", fmt);

    va_start(ap, fmt);

    if(G.background || !G.curscreen)
    {
        vprintf(nfmt, ap);
        printf("\n");
    }
    else
    {
        vconfirm(NULL, nfmt, ap);
    }
    va_end(ap);
}