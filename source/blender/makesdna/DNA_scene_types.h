/**
 * blenlib/DNA_scene_types.h (mar-2001 nzc)
 *
 * Renderrecipe and scene decription. The fact that there is a
 * hierarchy here is a bit strange, and not desirable.
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
#ifndef DNA_SCENE_TYPES_H
#define DNA_SCENE_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "DNA_vec_types.h"
#include "DNA_listBase.h"
#include "DNA_scriptlink_types.h"

struct FreeCamera;
struct Radio;
struct Object;
struct World;
struct Scene;
struct Image;
struct Group;

typedef struct AviCodecData
{
    void                *lpFormat;          /* save format */
    void                *lpParams;          /* compressor options */
    unsigned int        cbFormat;           /* size of lpFormat buffer */
    unsigned int        cbParams;           /* size of lpParams buffer */

    unsigned int        fccType;            /* stream type, for consistency */
    unsigned int        fccHandler;         /* compressor */
    unsigned int        dwKeyFrameEvery;    /* keyframe rate */
    unsigned int        dwQuality;          /* compress quality 0-10,000 */
    unsigned int        dwBytesPerSecond;   /* bytes per second */
    unsigned int        dwFlags;            /* flags... see below */
    unsigned int        dwInterleaveEvery;  /* for non-video streams only */
    unsigned int        pad;
} AviCodecData;

typedef struct RenderData
{
    struct AviCodecData AviCodecData;

    /* How will time be defined */
    short cfra, sfra, efra;     /* pictures */
    short images, framapto, flag;
    float ctime;                /* can we count on this? */
    float framelen, blurfac;

    /* For UR edge rendering: give the edges this colour */
    float edgeR, edgeG, edgeB;

    short fullscreen, xplay, yplay, freqplay;       /* standalone player */
    short depth, attrib, rt1, rt2;                  /* standalone player */

    short stereomode;                               /* standalone player stero settings */
    short pad[3];

    short size, maximsize;                         /* size in %, max in KB */

    /* uit buttons: */
    /**
     * The desired number of pixels in the x direction
     */
    short xsch;

    /**
     * @The desired number of pixels in the y direction
     */
    short ysch;

    /**
     * Adjustment factors for the aspect ratio in the x direction
     */
    short xasp;

    /**
     * Adjustment factors for the aspect ratio in the y direction
     */
    short yasp;

    /**
     * The number of parts to use in the x direction
     */
    short xparts;

    /**
     * The number of parts to use in the y direction
     */
    short yparts;

    /* should rewrite this I think */
    rctf safety, border;

    short winpos, planes, imtype;

    /** Mode bits */
    /* 0: Enable backbuffering for images */
    short bufflag;
    short quality;

    /**
     * Flags for render settings. Use bit-masking to access the settings.
     * The bits have these meanings:
     * 0: do oversampling
     * 1: do shadows
     * 2: do gamma correction
     * 3: ortho: not used?
     * 4: trace: not used?
     * 5: edge shading
     * 6: field rendering
     * 7: Disables time difference in field calculations
     * 8: Guess this is for sampling
     * 9: borders
     * 10: panorama
     * 11: crop
     * 12: Save SGI movies with Cosmo Hardware?
     * 13: add field first rendering
     * 14: motion blur
     * 15: use unified render for this pic
     */
    short mode;

    /**
     * What to do with the sky/background. Picks sky/premul/key
     * blending for the background.
     */
    short alphamode;

    /**
     * Toggles whether to apply a gamma correction for subpixel to
     * pixel blending.
     */
    short dogamma;

    /**
     * The number of samples to use per pixel.
     */
    short osa;
    short frs_sec, edgeint;

    /**
     * For unified renderer: reduce intensity on boundaries with
     * identical materials with this number.
     */
    short same_mat_redux, pad_3[3];

    /**
     * The gamma for the normal rendering. Used when doing
     * oversampling, to correctly blend subpixels to pixels.
     */
    float gamma;

    /**
     * Post production settings, don't really belong here.
     */
    float postmul, postgamma, postadd, postigamma;

    char backbuf[160], pic[160], ftype[160];

} RenderData;

typedef struct GameFraming
{
    float col[3];
    char type, pad1, pad2, pad3;
} GameFraming;

typedef struct Scene
{
    ID id;
    struct Object *camera;
    struct World *world;

    struct Scene *set;
    struct Image *ima;

    ListBase base;
    struct Base *basact;
    struct Group *group;

    float cursor[3];
    unsigned int lay;

    /* Some real time variables */
    struct FreeCamera *fcam;

    void *ed;
    struct Radio *radio;
    void *sumohandle;

    struct GameFraming framing;

    /* migrate or replace? depends on some internal things? */
    /* no, is in the right place (Ton) */
    struct RenderData r;

    ScriptLink scriptlink;

} Scene;

#ifdef __cplusplus
}
#endif

#endif