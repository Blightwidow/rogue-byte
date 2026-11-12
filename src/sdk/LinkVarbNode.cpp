/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
extern "C" {
extern unsigned B_002DD294;
extern unsigned B_004520C0[];
}

struct NODE { char b[0x18]; };
static inline void LocateGcNode(unsigned pnode, unsigned *pinode, unsigned *pichunk)
{
    for (unsigned ichunk = 0; ichunk < B_002DD294; ichunk++) {
        unsigned pvChunk = B_004520C0[ichunk];
        if (pvChunk <= pnode && pnode < pvChunk + 0xC000) {
            *pinode = (NODE *)pnode - (NODE *)pvChunk;
            *pichunk = ichunk;
            return;
        }
    }
    *pinode = 0;
    *pichunk = 0;
}

struct GNODE { int cref; unsigned prevIndex : 13; unsigned prevChunk : 2; unsigned unused : 1; unsigned nextIndex : 13; unsigned nextChunk : 2; unsigned gen : 1; };

extern "C" void LinkVarbNode(void *pnode, unsigned *ppnodeHead)
{
    unsigned pnodeAddress = (unsigned)pnode;
    unsigned inode;
    unsigned ichunk;
    LocateGcNode(pnodeAddress, &inode, &ichunk);
    if (*ppnodeHead != 0) {
        GNODE *pold = (GNODE *)*ppnodeHead;
        pold->prevIndex = inode;
        pold->prevChunk = ichunk;
    }
    unsigned inodeOld;
    unsigned ichunkOld;
    LocateGcNode(*ppnodeHead, &inodeOld, &ichunkOld);
    GNODE *pnew = (GNODE *)pnode;
    pnew->nextIndex = inodeOld;
    pnew->nextChunk = ichunkOld;
    *ppnodeHead = pnodeAddress;
}
