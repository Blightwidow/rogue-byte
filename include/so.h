/* SPDX-License-Identifier: GPL-3.0-or-later */
/* SO, the solid object: the first shared class layout (docs/ROADMAP.md "Next", item 1, pilot).
   A field is here when at least two matched functions read it at the same offset with the same type; its name is the one
   those functions use. Everything else is an unknown gap, named by its offset. Sly 2's SO is real C++ (vtable pointer at
   0xC, a base class chain from LO); the classes and the vtable come later, so this is a flat view of the first 0x150 bytes. */
#ifndef SLY2_SO_H
#define SLY2_SO_H
#include "types.h"

struct XF;
struct PHYS;
struct OXA;

struct SO {
    u8 unknown_0x0[0x10];
    struct SO *psoParent;   /* 0x10: InitSo, FFilterSensorSight (followed up to the root) */
    s32 proot;              /* 0x14: FFilterSensorSight (compared as an id), PoxaAllocSw (a list entry) */
    u8 unknown_0x18[0x10];
    u64 grfo;               /* 0x28: RecalcSoLocked, func_001C4BD8, UpdateRip */
    u8 unknown_0x30[0x28];
    struct XF *pxfLinear;   /* 0x58: Carry_Attach, ProjectSoTransform, func_001F8F80, func_001CD308 */
    struct XF *pxfAngular;  /* 0x5C: the same functions */
    struct XF *pxfRoot;     /* 0x60: GetSoCpdefi, func_001F4898, func_001F4930 */
    u8 unknown_0x64[0x84];
    struct PHYS *pphys;     /* 0xE8: FIsSoLocked, ProjectSoTransform, TranslateSoToPos, UpdateSo and others */
    struct OXA *poxa;       /* 0xEC: GetSoNoXpsAll, FFilterSensorSight, RecalcSoLocked and others */
    u8 unknown_0xF0[0x58];
    u64 grfso;              /* 0x148: ZapContinue, ExtractUniqueSosFromGeoms, UpdateSwXaList and others */
};
typedef struct SO SO;

/* Retail's layout, checked by the PS2 build: an offset that moves fails to compile. */
#if defined(__mips__)
#define SLY2_OFFSET_CHECK(type, field, offset) \
    typedef char check_##type##_##field[((unsigned int)&((struct type *)0)->field == (offset)) ? 1 : -1]
SLY2_OFFSET_CHECK(SO, psoParent, 0x10);
SLY2_OFFSET_CHECK(SO, proot, 0x14);
SLY2_OFFSET_CHECK(SO, grfo, 0x28);
SLY2_OFFSET_CHECK(SO, pxfLinear, 0x58);
SLY2_OFFSET_CHECK(SO, pxfAngular, 0x5C);
SLY2_OFFSET_CHECK(SO, pxfRoot, 0x60);
SLY2_OFFSET_CHECK(SO, pphys, 0xE8);
SLY2_OFFSET_CHECK(SO, poxa, 0xEC);
SLY2_OFFSET_CHECK(SO, grfso, 0x148);
#endif
#endif
