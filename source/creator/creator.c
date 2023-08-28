/* 
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

#include <stdlib.h>

/* This little block needed for linking to Blender... */

#include "MEM_guardedalloc.h"

#include "DNA_ID.h"

#include "BLI_blenlib.h"

/* for passing informtion between ccreator and gameengine */
#include "BKE_scene.h"

#include "BIF_toolbox.h"

#include "RE_renderconverter.h"
#include "blendertimer.h"

#include "render.h"

#include "SYS_system.h" 

/* Temporary includes */
#include "DNA_scene_types.h"
/* Temporary includes */

/* initialise the callbacks for the modules that need them */
void setCallbacks(void);

int main(int argc, char **argv)
{
    int a, i, stax, stay, sizx, sizy;
    SYS_SystemHandle syshandle;
    Scene *sce;

    int audio = 0;

    setCallbacks();

    return 0;
} /* end of int main(argc, argv) */

static void error_cb(char *err)
{
    error("%s", err);
}

void setCallbacks(void)
{
    /* Error output from the alloc routines */
    MEM_set_error_stream(stderr);

    /* BLI_blenlib: */

    //BLI_setErrorCallBack(error_cb);
    //BLI_setInterruptCallBack(MISC_test_break);

    /* render module: execution flow, timers cursors and display. */
    //RE_set_getrenderdata_callback(RE_rotateBlenderScene);
    //RE_set_freerenderdata_callback(RE_freeRotateBlenderScene);
}