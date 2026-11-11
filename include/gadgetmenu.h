/* SPDX-License-Identifier: GPL-3.0-or-later */
/* GADGETMENUENTRY: one row of the gadget menu's pages (D_002C2DE8, D_002C3028), 0x20 bytes, as GadgetMenu_SetPage reads them (the
   link at 0x10, the two floats it adds at 0x14 and 0x18, flag 4 at 0x1C) and the splice-gc-wipe code steps through them (the id at
   0). Names as in GadgetMenu_SetPage's matched source. The pages are defined in src/data. C and C++. */
#ifndef SLY2_GADGETMENU_H
#define SLY2_GADGETMENU_H
#include "types.h"

typedef struct GADGETMENUENTRY {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 field_0x4[3];
    /* 0x10 */ s32 link;
    /* 0x14 */ f32 low;
    /* 0x18 */ f32 high;
    /* 0x1C */ s32 flags;
} GADGETMENUENTRY;

#endif
