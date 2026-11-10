/* SPDX-License-Identifier: GPL-3.0-or-later */
/* ALLOCREQ, the request the world's and the stack's allocators take (PvAllocSwImpl, PvAllocSwClearImpl,
   PvAllocSwCopyImpl, PvAllocStackImpl, PvAllocStackClearImpl): a size and an
   alignment, filled on the caller's stack and passed by address (docs/ROADMAP.md "Next", item 1). Matched callers fill both words
   before every call: InitCloneSets (0x10-aligned matrices and transforms), AllocSwBuffers, func_0013E0E0 and many others. The
   name and field names are ours (cb as in Sly 1's PvAllocSwImpl(int cb)). C and C++. */
#ifndef SLY2_ALLOC_H
#define SLY2_ALLOC_H
#include "types.h"

struct ALLOCREQ {
    s32 cb;         /* bytes */
    s32 cbAlign;    /* alignment in bytes */
};
typedef struct ALLOCREQ ALLOCREQ;

#if defined(__mips__)
typedef char check_ALLOCREQ_size[(sizeof(struct ALLOCREQ) == 0x8) ? 1 : -1];
#endif
#endif
