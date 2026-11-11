/* SPDX-License-Identifier: GPL-3.0-or-later */
/* The option tables PeopidFind (0x1FFCF8) searches: one ARYSPLOPT per class id (RO_00279AD0, 199 classes, indexed by the cid that
   the object's class-info slot returns), each a count and a run of SPLOPTs sorted by option id, which PeopidFind binary-searches
   for the option's record (`peopid`, a 0x28-byte record in .data from 0x2AC880 on). The runs of all classes sit back to back in
   the 12,010 SPLOPTs at 0x262380 (src/rodata/start.cpp). Names as in PeopidFind's matched source. C and C++. */
#ifndef SLY2_SPLOPT_H
#define SLY2_SPLOPT_H
#include "types.h"

typedef struct SPLOPT {
    /* 0x0 */ s32 optid;   /* the key: PeopidFind compares it with the option id it looks for */
    /* 0x4 */ void *peopid; /* what PeopidFind returns */
} SPLOPT;

typedef struct ARYSPLOPT {
    /* 0x0 */ s32 csplopt;     /* how many SPLOPTs the class has */
    /* 0x4 */ SPLOPT *asplopt; /* the first of them */
} ARYSPLOPT;

#if defined(__mips__)
typedef char check_SPLOPT_size[(sizeof(SPLOPT) == 8) ? 1 : -1];
typedef char check_ARYSPLOPT_size[(sizeof(ARYSPLOPT) == 8) ? 1 : -1];
#endif

#endif
