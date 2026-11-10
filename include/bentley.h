/* SPDX-License-Identifier: GPL-3.0-or-later */
/* BENTLEY, the player as Bentley: class 55 of retail's class table, 0x1880 bytes, derived from JT (include/jt.h). Its vtable
   (0x2CB230) holds InitBentley (7), PostBentleyLoad (15), HandleBentleyMessage (5), AdjustBentleyNewXp (55),
   FInvulnerableBentley (76), NBentleyActionCategory (85), SetBentleyMode (88), UseBentleyGadget (100) and others of its own.
   The name follows those functions. A field here is read or set by one of those methods (slot given) or by two other readers
   that agree. C++ only. */
#ifndef SLY2_BENTLEY_H
#define SLY2_BENTLEY_H
#include "jt.h"

/* One of Bentley's six gadget entries: InitBentley sets each gadget, UseBentleyGadget leases a clone from the pool. */
struct BENTLEYSLOT {
    /* 0x0 */ s32 gadget;
    /* 0x4 */ void *ppool;
    /* 0x8 */ struct LO *plo;
};

struct BENTLEY : JT {
    u8 unknown_0x1320[0xB0];
    /* 0x13D0 */ s32 state; /* the state: InitBentley (7) sets -1; AdjustBentleyNewXp (55), FInvulnerableBentley (76), NBentleyActionCategory (85), func_00135D80 (90), func_00135FF0 (94), func_00135E40 (98) */
    /* 0x13D4 */ f32 tState; /* when the state was set: UpdateBentleyActive (from UpdateBentley, slot 16) */
    u8 unknown_0x13D8[0x2D8];
    /* 0x16B0 */ s32 field_0x16B0; /* InitBentley sets -1 */
    /* 0x16B4 */ BENTLEYSLOT *pslotActive; /* UseBentleyGadget (100) sets it; HandleBentleyMessage (5) */
    u8 unknown_0x16B8[0x4];
    /* 0x16BC */ s32 field_0x16BC; /* InitBentley sets -1 */
    u8 unknown_0x16C0[0x30];
    /* 0x16F0 */ QW posTarget; /* the bomb target: CalcBentleyBombTarget and ThrowBentleyBomb (two readers) */
    u8 unknown_0x1700[0x100];
    /* 0x1800 */ s32 field_0x1800; /* InitBentley sets -1 */
    u8 unknown_0x1804[0x20];
    /* 0x1824 */ BENTLEYSLOT aslot[6]; /* InitBentley sets each gadget; HandleBentleyMessage (5) walks them */
    /* 0x186C */ struct LO *ploGadget; /* HandleBentleyMessage (5) leases it */
    /* 0x1870 */ s32 field_0x1870; /* InitBentley sets 5 */
    /* 0x1874 */ s32 field_0x1874; /* UseBentleyGadget (100) */
    u8 unknown_0x1878[0x8];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(BENTLEYSLOT, 0xC);
SLY2_SIZE_CHECK(BENTLEY, 0x1880);
SLY2_OFFSET_CHECK(BENTLEY, state, 0x13D0);
SLY2_OFFSET_CHECK(BENTLEY, tState, 0x13D4);
SLY2_OFFSET_CHECK(BENTLEY, field_0x16B0, 0x16B0);
SLY2_OFFSET_CHECK(BENTLEY, pslotActive, 0x16B4);
SLY2_OFFSET_CHECK(BENTLEY, field_0x16BC, 0x16BC);
SLY2_OFFSET_CHECK(BENTLEY, posTarget, 0x16F0);
SLY2_OFFSET_CHECK(BENTLEY, field_0x1800, 0x1800);
SLY2_OFFSET_CHECK(BENTLEY, aslot, 0x1824);
SLY2_OFFSET_CHECK(BENTLEY, ploGadget, 0x186C);
SLY2_OFFSET_CHECK(BENTLEY, field_0x1870, 0x1870);
SLY2_OFFSET_CHECK(BENTLEY, field_0x1874, 0x1874);
#endif
#endif
