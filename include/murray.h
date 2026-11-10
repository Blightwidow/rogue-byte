/* SPDX-License-Identifier: GPL-3.0-or-later */
/* MURRAY, the player as Murray: class 54 of retail's class table, 0x1B00 bytes, derived from JT (include/jt.h). Its vtable
   (0x2D44C8) holds InitMurray (7), LoadMurrayFromBrx (14), PostMurrayLoad (15), GetMurrayCpdefi (50), PresetMurrayAccel (70),
   FInvulnerableMurray (76), func_001B8450 (61), func_001B81B8 (87), SetMurrayMode (88), SetMurrayAnimBase (90),
   UseMurrayGadget (100) and others of its own. The name follows those functions. A field here is read or set by one of those
   methods (slot given) or by two other readers that agree. C++ only. */
#ifndef SLY2_MURRAY_H
#define SLY2_MURRAY_H
#include "jt.h"

struct IKLIMB;

struct MURRAY : JT {
    u8 unknown_0x1320[0xB0];
    /* 0x13D0 */ s32 state; /* the state: InitMurray (7) sets -1; GetMurrayCpdefi (50), PresetMurrayAccel (70), FInvulnerableMurray (76), NMurrayActionCategory (85), SetMurrayAnimBase (90), FMurrayOnFoot (94), PredictMurrayLead (96) */
    u8 unknown_0x13D4[0x4];
    /* 0x13D8 */ s32 field_0x13D8; /* InitMurray sets -1; NMurrayActionCategory (85) */
    u8 unknown_0x13DC[0xC];
    /* 0x13E8 */ s32 field_0x13E8; /* UseMurrayGadget (100) sets 1 */
    /* 0x13EC */ s32 field_0x13EC; /* UpdateMurrayActive (from UpdateMurray, slot 16) */
    /* 0x13F0 */ struct LO *ploCarried; /* what Murray carries: SetMurrayMode (88), SetMurrayAnimBase (90), func_001B81B8 (87) */
    u8 unknown_0x13F4[0x1C];
    /* 0x1410 */ f32 field_0x1410; /* InitMurray sets 1500 */
    /* 0x1414 */ f32 field_0x1414; /* InitMurray sets 3500 */
    u8 unknown_0x1418[0x18];
    /* 0x1430 */ struct SO *psoDropped; /* func_001B8450 (61) tests it; DetachMurrayObject sets it to what it lets go */
    /* 0x1434 */ f32 field_0x1434; /* InitMurray sets -60 */
    u8 unknown_0x1438[0x4];
    /* 0x143C */ s32 field_0x143C; /* UseMurrayGadget (100) sets 1 */
    u8 unknown_0x1440[0x8];
    /* 0x1448 */ s32 field_0x1448; /* UpdateMurrayLift, SetMurrayLiftState (two readers) */
    /* 0x144C */ s32 field_0x144C; /* InitMurray sets -1 */
    /* 0x1450 */ s32 field_0x1450; /* InitMurray sets -1 */
    u8 unknown_0x1454[0x4];
    /* 0x1458 */ s32 iapasegByIndex; /* InitMurray sets -1; SetMurrayAnimBase (90) indexes apasegByIndex with it in state 5 */
    u8 unknown_0x145C[0xD4];
    /* 0x1530 */ struct SMA *psmaPartner; /* StartMurrayMash sets it, ReleaseMurrayObject (in the mash state, 6) reads it */
    /* 0x1534 */ s32 iMashLevel; /* StartMurrayMash; HandleMurrayMessage (5) */
    u8 unknown_0x1538[0xB8];
    /* 0x15F0 */ void *field_0x15F0; /* LoadMurrayFromBrx (14) */
    /* 0x15F4 */ void *field_0x15F4; /* LoadMurrayFromBrx */
    /* 0x15F8 */ void *field_0x15F8; /* LoadMurrayFromBrx */
    /* 0x15FC */ void *field_0x15FC; /* LoadMurrayFromBrx */
    u8 unknown_0x1600[0x10];
    /* 0x1610 */ struct IKLIMB *pikLimbA; /* LoadMurrayFromBrx allocates it and calls InitIkLimb */
    /* 0x1614 */ struct IKLIMB *pikLimbB; /* LoadMurrayFromBrx, as pikLimbA */
    u8 unknown_0x1618[0x1DC];
    /* 0x17F4 */ s32 field_0x17F4; /* InitMurray sets -1 */
    u8 unknown_0x17F8[0x18];
    /* 0x1810 */ s32 field_0x1810; /* InitMurray sets -1 */
    u8 unknown_0x1814[0x1C];
    /* 0x1830 */ QW field_0x1830; /* PredictMurrayLead (96) */
    /* 0x1840 */ s32 field_0x1840; /* InitMurray sets -1 */
    u8 unknown_0x1844[0x214];
    /* 0x1A58 */ void *apasegState[0x16]; /* SetMurrayAnimBase (90) binds the entry state indexes; the count is the room left before apasegByIndex */
    /* 0x1AB0 */ void *apasegByIndex[3]; /* SetMurrayAnimBase (90) */
    /* 0x1ABC */ void *pasegCarry; /* SetMurrayAnimBase (90), in state 2 while carrying */
    /* 0x1AC0 */ s32 field_0x1AC0; /* func_00146EE0 and func_001B8EC0 (two readers) */
    /* 0x1AC4 */ s32 field_0x1AC4; /* UseMurrayGadget (100) copies it to JT field_0x130C */
    /* 0x1AC8 */ f32 field_0x1AC8; /* InitMurray sets -60 */
    /* 0x1ACC */ s32 field_0x1ACC; /* PostMurrayLoad (15) */
    u8 unknown_0x1AD0[0x30];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(MURRAY, 0x1B00);
SLY2_OFFSET_CHECK(MURRAY, state, 0x13D0);
SLY2_OFFSET_CHECK(MURRAY, field_0x13D8, 0x13D8);
SLY2_OFFSET_CHECK(MURRAY, field_0x13E8, 0x13E8);
SLY2_OFFSET_CHECK(MURRAY, field_0x13EC, 0x13EC);
SLY2_OFFSET_CHECK(MURRAY, ploCarried, 0x13F0);
SLY2_OFFSET_CHECK(MURRAY, field_0x1410, 0x1410);
SLY2_OFFSET_CHECK(MURRAY, field_0x1414, 0x1414);
SLY2_OFFSET_CHECK(MURRAY, psoDropped, 0x1430);
SLY2_OFFSET_CHECK(MURRAY, field_0x1434, 0x1434);
SLY2_OFFSET_CHECK(MURRAY, field_0x143C, 0x143C);
SLY2_OFFSET_CHECK(MURRAY, field_0x1448, 0x1448);
SLY2_OFFSET_CHECK(MURRAY, field_0x144C, 0x144C);
SLY2_OFFSET_CHECK(MURRAY, field_0x1450, 0x1450);
SLY2_OFFSET_CHECK(MURRAY, iapasegByIndex, 0x1458);
SLY2_OFFSET_CHECK(MURRAY, psmaPartner, 0x1530);
SLY2_OFFSET_CHECK(MURRAY, iMashLevel, 0x1534);
SLY2_OFFSET_CHECK(MURRAY, field_0x15F0, 0x15F0);
SLY2_OFFSET_CHECK(MURRAY, field_0x15F4, 0x15F4);
SLY2_OFFSET_CHECK(MURRAY, field_0x15F8, 0x15F8);
SLY2_OFFSET_CHECK(MURRAY, field_0x15FC, 0x15FC);
SLY2_OFFSET_CHECK(MURRAY, pikLimbA, 0x1610);
SLY2_OFFSET_CHECK(MURRAY, pikLimbB, 0x1614);
SLY2_OFFSET_CHECK(MURRAY, field_0x17F4, 0x17F4);
SLY2_OFFSET_CHECK(MURRAY, field_0x1810, 0x1810);
SLY2_OFFSET_CHECK(MURRAY, field_0x1830, 0x1830);
SLY2_OFFSET_CHECK(MURRAY, field_0x1840, 0x1840);
SLY2_OFFSET_CHECK(MURRAY, apasegState, 0x1A58);
SLY2_OFFSET_CHECK(MURRAY, apasegByIndex, 0x1AB0);
SLY2_OFFSET_CHECK(MURRAY, pasegCarry, 0x1ABC);
SLY2_OFFSET_CHECK(MURRAY, field_0x1AC0, 0x1AC0);
SLY2_OFFSET_CHECK(MURRAY, field_0x1AC4, 0x1AC4);
SLY2_OFFSET_CHECK(MURRAY, field_0x1AC8, 0x1AC8);
SLY2_OFFSET_CHECK(MURRAY, field_0x1ACC, 0x1ACC);
#endif
#endif
