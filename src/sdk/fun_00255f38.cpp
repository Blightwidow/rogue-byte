/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
extern "C" {
extern unsigned g_2dd2d4;
extern unsigned B_00452160[];
}

struct NODE { char b[0x14]; };
static inline void LocateGcNode(unsigned pnode, unsigned *pinode, unsigned *pichunk)
{
    for (unsigned ichunk = 0; ichunk < g_2dd2d4; ichunk++) {
        unsigned pvChunk = B_00452160[ichunk];
        if (pvChunk <= pnode && pnode < pvChunk + 0x1400) {
            *pinode = (NODE *)pnode - (NODE *)pvChunk;
            *pichunk = ichunk;
            return;
        }
    }
    *pinode = 0;
    *pichunk = 0;
}

struct GNODE { int cref; unsigned prevIndex : 13; unsigned prevChunk : 2; unsigned unused : 1; unsigned nextIndex : 13; unsigned nextChunk : 2; unsigned gen : 1; };

extern "C" void func_00255F38(void *pnode, unsigned *ppnodeHead)
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
