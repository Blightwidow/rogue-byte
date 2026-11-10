/* SPDX-License-Identifier: GPL-3.0-or-later */
/* XF, a transform node: what SO::pxfLinear, pxfAngular and pxfRoot point at and what the *Xf* functions take
   (docs/ROADMAP.md "Next", item 1). Not in the class table (no vtable). The first 0x80 bytes keep the Sly 1 decompilation's
   layout and names (source: sly1 include/alo.h XF, CC0): GetSoCpdefi reads the world matrix at 0x40 and the world position at
   0x70, and UpdateXfmMatWorld, TranslateSoToPos read 0x40 as one matrix too. From 0x80 on Sly 2 differs from Sly 1; a field
   there is read by two matched functions that reach an XF through SO or take one by name. C and C++.

   Sly 1 splits each matrix into MATRIX3 + VECTOR (mat 0x00, pos 0x30, matWorld 0x40, posWorld 0x70). Sly 2's readers treat each
   as one 4x4 MATRIX4 whose row 3 is the position: TranslateSoToPos copies the world matrix with quadword moves and writes row 3
   of mat with element 15 set to 1, UpdateXfmMatWorld multiplies matWorld as a MATRIX4, and GetActvalPositionGoal and
   GetSoCpdefi read rows 3 (0x30, 0x70) as quadwords. So both are MATRIX4 here; pos and posWorld are mat.row[3] and
   matWorld.row[3]. */
#ifndef SLY2_XF_H
#define SLY2_XF_H
#include "sly2.h"

struct ACT;
struct XFMIRROR;

struct XF {
    /* 0x00 */ struct MATRIX4 mat;      /* row 3: the position */
    /* 0x40 */ struct MATRIX4 matWorld; /* row 3: the world position */
    u8 unknown_0x80[0x10];
    /* 0x90 */ struct ACT *pactFirst;  /* the acts on this transform: InsertXfAct, RemoveXfAct, ResortXfActList, func_001F8910 */
    /* 0x94 */ s32 dof;                /* PchnFindAseg (an XF from SO's slot 51), func_00131B60 */
    /* 0x98 */ s16 kind;               /* func_001F4898, func_001F4930, ProjectSoTransform, func_001F8F80 (FXfKind* tests) */
    /* 0x9A */ s16 sub;                /* SleepXf */
    /* 0x9C */ s32 id;                 /* func_00131B60 */
    /* 0xA0 */ struct XF *pxfParent;   /* TranslateSoToPos, func_001CD308, func_001F4898, func_001F4930 */
    /* 0xA4 */ s32 generation;         /* TranslateSoToPos, UpdateXfmMatWorld */
    /* 0xA8: by kind. A moving XF keeps when it arrives (GetActvalPositionGoal reads it, func_001C8918 sets it); a mirrored
       one keeps its mirror (LoadXfMirrors). All three reach a certain XF (ACT::pxf, SetXfKind's argument). */
    union {
        f32 tArrive;
        struct XFMIRROR *pxfmirror;
    };
    u8 unknown_0xAC[0x4];
    /* 0xB0 */ QW vel;                 /* func_001F4898, func_001F4930, ProjectSoTransform, GetActvalPositionGoal */
    /* 0xC0 */ QW posGoal;             /* GetActPositionGoal, func_0012DFE0, func_001C8918 */
    /* 0xD0 */ QW velGoal;             /* GetActPositionGoal, func_001C8918 (a tangent there) */
    u8 unknown_0xE0[0x10];
    /* 0xF0 */ s32 accel[3];           /* ProjectSoTransform clears it for a dynamic kind (reached through SO::pxfLinear) */
};
typedef struct XF XF;

#if defined(__mips__)
typedef char check_XF_matWorld[((unsigned int)&((struct XF *)0)->matWorld == 0x40) ? 1 : -1];
typedef char check_XF_pactFirst[((unsigned int)&((struct XF *)0)->pactFirst == 0x90) ? 1 : -1];
typedef char check_XF_kind[((unsigned int)&((struct XF *)0)->kind == 0x98) ? 1 : -1];
typedef char check_XF_pxfParent[((unsigned int)&((struct XF *)0)->pxfParent == 0xA0) ? 1 : -1];
typedef char check_XF_vel[((unsigned int)&((struct XF *)0)->vel == 0xB0) ? 1 : -1];
typedef char check_XF_tArrive[((unsigned int)&((struct XF *)0)->tArrive == 0xA8) ? 1 : -1];
typedef char check_XF_posGoal[((unsigned int)&((struct XF *)0)->posGoal == 0xC0) ? 1 : -1];
typedef char check_XF_size[(sizeof(struct XF) == 0x100) ? 1 : -1]; /* func_00131B60 walks ALO::axf in steps of 0x100 */
typedef char check_XF_dof[((unsigned int)&((struct XF *)0)->dof == 0x94) ? 1 : -1];
typedef char check_XF_accel[((unsigned int)&((struct XF *)0)->accel == 0xF0) ? 1 : -1];
#endif
#endif
