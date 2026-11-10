/* SPDX-License-Identifier: GPL-3.0-or-later */
/* SLY, the player as Sly: class 53 of retail's class table, 0x2060 bytes, derived from JT (include/jt.h); NewSly is its factory and
   its vtable (0x2D2E98) holds InitSly (7), LoadSlyFromBrx (14), UpdateJtBounds (49), SetSlyHide (87), UseSlyGadget (100) and
   others of its own. The name follows those functions. A field here is read or set by one of those methods (slot given). C++ only. */
#ifndef SLY2_SLY_H
#define SLY2_SLY_H
#include "jt.h"

struct PART;
struct TARGET;

struct SLY : JT {
    u8 unknown_0x1320[0x400];
    /* 0x1720 */ void *apasegJts[0x2C]; /* BindJtStepAseg (slot 90) binds the entry jts indexes, entry 0 when it is empty; the count is the room
                                           left before the carry state InitSly starts at 0x17D0, not a measured one */
    u8 unknown_0x17D0[0xB0];
    /* 0x1880 */ s32 cbounds; /* UpdateJtBounds (slot 49) */
    u8 unknown_0x1884[0xC];
    /* 0x1890 */ QW abounds[3]; /* UpdateJtBounds extends the bounds by each of the first cbounds; at most 3, ptarget follows */
    /* 0x18C0 */ struct TARGET *ptarget; /* the cane's target: FFaceSlyAimTarget (slot 92) faces it, ChooseJtSweepTarget sets it */
    u8 unknown_0x18C4[0x4];
    /* 0x18C8 */ s32 jts; /* the state: NSlyActionCategory (85), FAllowBinocSly (94), BindJtStepAseg (90), JT_FInvulnerable (76), func_0018A428 (50) */
    u8 unknown_0x18CC[0xD4];
    /* 0x19A0 */ struct PART *apartHide[3]; /* SetSlyHide (87) */
    /* 0x19AC */ f32 rBounds; /* UpdateJtBounds */
    u8 unknown_0x19B0[0xF4];
    /* 0x1AA4 */ f32 field_0x1AA4; /* func_0018A428 (50) */
    u8 unknown_0x1AA8[0x538];
    /* 0x1FE0 */ s32 field_0x1FE0; /* UseSlyGadget (100) */
    /* 0x1FE4 */ s32 field_0x1FE4; /* UseSlyGadget (100) */
    u8 unknown_0x1FE8[0x64];
    /* 0x204C */ s32 field_0x204C; /* UseSlyGadget (100) */
    u8 unknown_0x2050[0x10];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(SLY, 0x2060);
SLY2_OFFSET_CHECK(SLY, cbounds, 0x1880);
SLY2_OFFSET_CHECK(SLY, abounds, 0x1890);
SLY2_OFFSET_CHECK(SLY, apasegJts, 0x1720);
SLY2_OFFSET_CHECK(SLY, ptarget, 0x18C0);
SLY2_OFFSET_CHECK(SLY, jts, 0x18C8);
SLY2_OFFSET_CHECK(SLY, apartHide, 0x19A0);
SLY2_OFFSET_CHECK(SLY, rBounds, 0x19AC);
SLY2_OFFSET_CHECK(SLY, field_0x1AA4, 0x1AA4);
SLY2_OFFSET_CHECK(SLY, field_0x1FE0, 0x1FE0);
SLY2_OFFSET_CHECK(SLY, field_0x1FE4, 0x1FE4);
SLY2_OFFSET_CHECK(SLY, field_0x204C, 0x204C);
#endif
#endif
