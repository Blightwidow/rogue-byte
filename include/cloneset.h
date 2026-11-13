/* SPDX-License-Identifier: GPL-3.0-or-later */
/* CLONESET, one entry of the world's table of clone sets (SW::acloneset, SW::ccloneset in sw.h): 0x6C bytes, the stride
   InitCloneSets and InstantiateClone step by. Field names and meanings are ours, from those two readers: a set holds
   `cpalo` objects per clone (`apalo`, indexed clone * cpalo + object), `cclone` clones of which the first `icloneFree`
   are leased out, and `aoidClone` is the object ids InstantiateClone hands to each clone. C++ only. */
#ifndef SLY2_CLONESET_H
#define SLY2_CLONESET_H
#include "lo.h"

struct CLONESET {
    /* 0x00 */ s32 cpalo;           /* InitCloneSets, InstantiateClone: objects per clone */
    /* 0x04 */ struct LO **apalo;   /* the same */
    /* 0x08 */ s32 cclone;          /* InitCloneSets */
    /* 0x0C */ s32 icloneFree;      /* InitCloneSets, InstantiateClone */
    u8 unknown_0x10[0x4];
    /* 0x14 */ s32 value;           /* InitCloneSets */
    /* 0x18 */ s32 *aoidClone;      /* InitCloneSets, InstantiateClone */
    u8 unknown_0x1C[0x48];
    /* 0x64 */ char *amat;          /* InitCloneSets: matrices, 0x10-aligned */
    /* 0x68 */ char *axf;           /* InitCloneSets: transforms, 0x10-aligned */
};

#if defined(__mips__)
SLY2_SIZE_CHECK(CLONESET, 0x6C);
SLY2_OFFSET_CHECK(CLONESET, apalo, 0x04);
SLY2_OFFSET_CHECK(CLONESET, icloneFree, 0x0C);
SLY2_OFFSET_CHECK(CLONESET, aoidClone, 0x18);
SLY2_OFFSET_CHECK(CLONESET, amat, 0x64);
SLY2_OFFSET_CHECK(CLONESET, axf, 0x68);
#endif
#endif
