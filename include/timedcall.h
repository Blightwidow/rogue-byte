/* SPDX-License-Identifier: GPL-3.0-or-later */
/* TIMEDCALL, a script call the world runs at a time (SW::ptimedcallFirst in sw.h, sorted by `tFire`), and CPair, the
   Splice pair it keeps. Field names and meanings are ours, from the three functions that touch them: AddSwTimedCall
   fills a fresh entry from a slot heap and links it in time order, CancelSwTimedCall finds one by `idCall` and frees
   it with its pair, RefOpScheduleCallback hands AddSwTimedCall the pair it built. `idCall` is -1 for a call with an
   owner and a running count (SW 0x3D6C) otherwise. CPair is 8 bytes of reference count and padding, a CRef and the next
   pair of the list; 27 sources still write their own copy (docs/ROADMAP.md item 1). C++ only. */
#ifndef SLY2_TIMEDCALL_H
#define SLY2_TIMEDCALL_H
#include "cref.h"

struct CPair {
    /* 0x00 */ s32 cref;            /* the reference count AddSwTimedCall bumps and CancelSwTimedCall drops */
    u8 unknown_0x4[0x4];
    /* 0x08 */ CRef ref;
    /* 0x10 */ CPair *next;
};

struct TIMEDCALL {
    /* 0x00 */ f32 tFire;           /* AddSwTimedCall keeps the list sorted by it */
    /* 0x04 */ void *powner;        /* 0 for a call made by a script; AddSwTimedCall stores it before choosing `idCall` */
    /* 0x08 */ CPair *ppair;
    /* 0x0C */ s32 idCall;
    /* 0x10 */ TIMEDCALL *pnext;
};

#if defined(__mips__)
typedef char check_CPair_ref[((unsigned int)&((CPair *)0)->ref == 0x08) ? 1 : -1];
typedef char check_CPair_next[((unsigned int)&((CPair *)0)->next == 0x10) ? 1 : -1];
typedef char check_TIMEDCALL_ppair[((unsigned int)&((TIMEDCALL *)0)->ppair == 0x08) ? 1 : -1];
typedef char check_TIMEDCALL_idCall[((unsigned int)&((TIMEDCALL *)0)->idCall == 0x0C) ? 1 : -1];
typedef char check_TIMEDCALL_pnext[((unsigned int)&((TIMEDCALL *)0)->pnext == 0x10) ? 1 : -1];
#endif
#endif
