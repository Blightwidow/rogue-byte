/* SPDX-License-Identifier: GPL-3.0-or-later */
/* SLOTSO: class 96 of retail's class table, 0x250 bytes, derived from SO (include/so.h). Its vtable holds UpdateSlotSo (slot 16),
   AccelSlotSoRotation (70), FAbsorbSlotSoWkr (75) and its init function func_001B0B78 (7); the functions named *SlotSo* take it.
   The name is ours, from those functions. A field here is read by a matched method of this class at that offset, and no matched
   function reads the offset differently; the readers are listed. C++ only. */
#ifndef SLY2_SLOTSO_H
#define SLY2_SLOTSO_H
#include "so.h"

struct CRV;
struct ACT;

struct SLOTSO : SO {
    u8 unknown_0x150[0x18];
    /* 0x168 */ f32 dtFade;            /* UpdateSlotSo; func_001B0B78 sets it to 1 */
    /* 0x16C */ struct CRV *pcrvWander; /* UpdateSlotSo, func_001B0D90 */
    u8 unknown_0x170[0x4];
    /* 0x174 */ f32 uWander;           /* func_001B0D90: the position along pcrvWander */
    /* 0x178 */ f32 duWander;          /* func_001B0D90 */
    u8 unknown_0x17C[0x48];
    /* 0x1C4 */ struct ACT *pactAnim;  /* UpdateSlotSo */
    u8 unknown_0x1C8[0x10];
    /* 0x1D8 */ f32 radHeading;        /* FSlotSoFacingHeading */
    u8 unknown_0x1DC[0x44];
    /* 0x220 */ s32 state;             /* UpdateSlotSo, FAbsorbSlotSoWkr; func_001B0B78 sets it to -1 */
    u8 unknown_0x224[0x4];
    /* 0x228 */ f32 tNext;             /* UpdateSlotSo */
    /* 0x22C */ f32 tFade;             /* UpdateSlotSo */
    u8 unknown_0x230[0x20];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(SLOTSO, 0x250);
SLY2_OFFSET_CHECK(SLOTSO, dtFade, 0x168);
SLY2_OFFSET_CHECK(SLOTSO, pcrvWander, 0x16C);
SLY2_OFFSET_CHECK(SLOTSO, uWander, 0x174);
SLY2_OFFSET_CHECK(SLOTSO, pactAnim, 0x1C4);
SLY2_OFFSET_CHECK(SLOTSO, radHeading, 0x1D8);
SLY2_OFFSET_CHECK(SLOTSO, state, 0x220);
SLY2_OFFSET_CHECK(SLOTSO, tNext, 0x228);
SLY2_OFFSET_CHECK(SLOTSO, tFade, 0x22C);
#endif
#endif
