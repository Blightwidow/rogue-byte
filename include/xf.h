/* SPDX-License-Identifier: GPL-3.0-or-later */
/* XF, a transform node: what SO::pxfLinear, pxfAngular and pxfRoot point at and what the *Xf* functions take
   (docs/ROADMAP.md "Next", item 1). Not in the class table (no vtable). The first 0x80 bytes keep the Sly 1 decompilation's
   layout and names (source: sly1 include/alo.h XF, CC0): GetSoCpdefi reads the world matrix at 0x40 and the world position at
   0x70, and UpdateXfmMatWorld, TranslateSoToPos read 0x40 as one matrix too. From 0x80 on Sly 2 differs from Sly 1; a field
   there is read by two matched functions that reach an XF through SO or take one by name. C and C++.

   The matrices are declared as Sly 1 has them (MATRIX3 + VECTOR). Some readers copy 0x40-0x80 as one MATRIX4 (quadword moves);
   those stay local until the two views are settled against retail's copies. */
#ifndef SLY2_XF_H
#define SLY2_XF_H
#include "sly2.h"

struct ACT;

struct XF {
    /* 0x00 */ struct MATRIX3 mat;
    /* 0x30 */ struct VECTOR pos;
    /* 0x40 */ struct MATRIX3 matWorld;
    /* 0x70 */ struct VECTOR posWorld;
    u8 unknown_0x80[0x10];
    /* 0x90 */ struct ACT *pactFirst;  /* the acts on this transform: InsertXfAct, RemoveXfAct, ResortXfActList, func_001F8910 */
    u8 unknown_0x94[0x4];
    /* 0x98 */ s16 kind;               /* func_001F4898, func_001F4930, ProjectSoTransform, func_001F8F80 (FXfKind* tests) */
    /* 0x9A */ s16 sub;                /* SleepXf */
    u8 unknown_0x9C[0x4];
    /* 0xA0 */ struct XF *pxfParent;   /* TranslateSoToPos, func_001CD308, func_001F4898, func_001F4930 */
    /* 0xA4 */ s32 generation;         /* TranslateSoToPos, UpdateXfmMatWorld */
    u8 unknown_0xA8[0x8];
    /* 0xB0 */ QW vel;                 /* func_001F4898, func_001F4930, ProjectSoTransform */
    u8 unknown_0xC0[0x30];
    /* 0xF0 */ s32 accel[3];           /* ProjectSoTransform clears it for a dynamic kind (reached through SO::pxfLinear) */
};
typedef struct XF XF;

#if defined(__mips__)
typedef char check_XF_matWorld[((unsigned int)&((struct XF *)0)->matWorld == 0x40) ? 1 : -1];
typedef char check_XF_posWorld[((unsigned int)&((struct XF *)0)->posWorld == 0x70) ? 1 : -1];
typedef char check_XF_pactFirst[((unsigned int)&((struct XF *)0)->pactFirst == 0x90) ? 1 : -1];
typedef char check_XF_kind[((unsigned int)&((struct XF *)0)->kind == 0x98) ? 1 : -1];
typedef char check_XF_pxfParent[((unsigned int)&((struct XF *)0)->pxfParent == 0xA0) ? 1 : -1];
typedef char check_XF_vel[((unsigned int)&((struct XF *)0)->vel == 0xB0) ? 1 : -1];
typedef char check_XF_accel[((unsigned int)&((struct XF *)0)->accel == 0xF0) ? 1 : -1];
#endif
#endif
