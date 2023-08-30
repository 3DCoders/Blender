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

#ifndef GHOST_C_API_H
#define GHOST_C_API_H

#ifdef __cplusplus
extern "C" {
#endif

#define GHOST_DECLARE_HANDLE(name) typedef struct name##__ { int unused; } *name;

GHOST_DECLARE_HANDLE(GHOST_SystemHandle);

/***************************************************************************
 ** Event management functionality
 **************************************************************************/

/**
 * Retrieves events from the system and stores them in the queue.
 * @param systemhandle The handle to the system
 * @param waitForEvent Boolean to indicate that ProcessEvents should
 * wait (block) until the next event before returning.
 * @return Indication of the presence of events.
 */
extern int GHOST_ProcessEvents(GHOST_SystemHandle systemhandle, int waitForEvent);

#ifdef __cplusplus
}
#endif

#endif /* GHOST_C_API_H */