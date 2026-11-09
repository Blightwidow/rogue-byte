/* SPDX-License-Identifier: GPL-3.0-or-later */
/* SO, the solid object: class 48 of retail's class table, 0x150 bytes, 75 vtable slots, derived from LO (include/lo.h, which
   explains the rules: slot order, names, signatures, the two-reader rule for fields). C++ only. */
#ifndef SLY2_SO_H
#define SLY2_SO_H
#include "lo.h"

struct XF;
struct PHYS;
struct OXA;
struct GEOM;

struct SO : LO {
    virtual void Slot49();
    virtual void GetCpdefi();           /* 50: GetSoCpdefi */
    virtual void PxfFromRef();          /* 51: PxfFromAloRef */
    virtual void Slot52();
    virtual struct OXA *PoxaAlloc();    /* 53: PoxaAllocSo; RecalcSoLocked keeps the result */
    virtual void Slot54(void *pso);     /* 54: func_001F5988; DiscardSoXps passes another SO or 0 */
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();              /* 58: func_001F4F10 */
    virtual void Slot59();
    virtual void Slot60(struct GEOM *pgeom, int cbsp, void *absp, void *pbspLast, void *ptarget); /* 60: func_001F5990; MarkSoCustomContacts */
    virtual int FIgnoreIntersection(struct SO *psoOther); /* 61: FIgnoreSoIntersection; FPoxaPairInteracts */
    virtual int FIsLocked();            /* 62: FIsSoLocked; func_00206380, AddSoGeomToOxa, RemoveSoGeomFromOxa */
    virtual void Slot63();
    virtual void Slot64();              /* 64: func_001F3590 */
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();              /* 70: called without arguments (ProjectSoTransform) */
    virtual void Slot71();
    virtual void Slot72(void *pwater, float dt); /* 72: AddWaterExternalAccelerations */
    virtual int Slot73(QW pos);         /* 73: UpdateRip */
    virtual void Slot74();              /* 74: func_001F7410; func_001F7950 calls it without arguments */
    virtual void FAbsorbWkr();          /* 75: FAbsorbSoWkr */

    u8 unknown_0x50[0x8];
    /* 0x58 */ struct XF *pxfLinear;   /* Carry_Attach, ProjectSoTransform, func_001F8F80, func_001CD308 */
    /* 0x5C */ struct XF *pxfAngular;  /* the same functions */
    /* 0x60 */ struct XF *pxfRoot;     /* GetSoCpdefi, func_001F4898, func_001F4930 */
    u8 unknown_0x64[0x7C];
    /* 0xE0 */ s32 cgeom;              /* ProjectSoTransform, RemoveSoGeomFromOxa (elements of 0xB0 bytes) */
    /* 0xE4 */ struct GEOM *ageom;     /* the same functions, PpartFindAlo, func_001F7A68 (as PART) */
    /* 0xE8 */ struct PHYS *pphys;     /* FIsSoLocked, ProjectSoTransform, TranslateSoToPos, UpdateSo and others */
    /* 0xEC */ struct OXA *poxa;       /* GetSoNoXpsAll, FFilterSensorSight, RecalcSoLocked and others; func_001F7410 and
                                       func_001F7950 read the same object (+0x6C) as PHYS */
    u8 unknown_0xF0[0x3C];
    /* 0x12C */ f32 uFade;             /* UpdateSo, InitFragile */
    /* 0x130 */ f32 duFade;            /* the same functions */
    u8 unknown_0x134[0x14];
    /* 0x148 */ u64 grfso;             /* ZapContinue, ExtractUniqueSosFromGeoms, UpdateSwXaList and others */
};

#if defined(__mips__)
SLY2_SIZE_CHECK(SO, 0x150);
SLY2_OFFSET_CHECK(SO, pxfLinear, 0x58);
SLY2_OFFSET_CHECK(SO, pxfAngular, 0x5C);
SLY2_OFFSET_CHECK(SO, pxfRoot, 0x60);
SLY2_OFFSET_CHECK(SO, cgeom, 0xE0);
SLY2_OFFSET_CHECK(SO, ageom, 0xE4);
SLY2_OFFSET_CHECK(SO, pphys, 0xE8);
SLY2_OFFSET_CHECK(SO, poxa, 0xEC);
SLY2_OFFSET_CHECK(SO, uFade, 0x12C);
SLY2_OFFSET_CHECK(SO, duFade, 0x130);
SLY2_OFFSET_CHECK(SO, grfso, 0x148);
#endif
#endif
