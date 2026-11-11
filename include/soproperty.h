/* SPDX-License-Identifier: GPL-3.0-or-later */
/* SOPROPERTY: one entry of the property lists SetSoProperties (0x1A64E8) walks for an object at load (LoadBentleyFromBrx,
   LoadSlyFromBrx, LoadMurrayFromBrx, PostJtLoad, func_001C82F0 pass a count and the list). It reads 12-byte entries: `flags` selects
   how the key is looked up (bits 0x2, 0x10, 0x20, 0x40, 0x200), `key` is what it looks up and `offset` is where in the object the
   result is stored. The lists are defined in src/data (typed from that reader). C and C++. */
#ifndef SLY2_SOPROPERTY_H
#define SLY2_SOPROPERTY_H
#include "types.h"

typedef struct SOPROPERTY {
    /* 0x0 */ s32 flags;
    /* 0x4 */ s32 key;
    /* 0x8 */ s32 offset;
} SOPROPERTY;

#endif
