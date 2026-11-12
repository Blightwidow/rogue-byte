/* SPDX-License-Identifier: GPL-3.0-or-later */
struct PAIRNODE {
    char pad0[4];
    int grf;
    char pad8[12];
};
extern "C" {
extern unsigned B_002DD284;
extern PAIRNODE *B_00452098[];
}

static inline void LocateGcNode(PAIRNODE *pnode, unsigned *pinode, unsigned *pichunk)
{
    for (unsigned ichunk = 0; ichunk < B_002DD284; ichunk++) {
        PAIRNODE *pchunk = B_00452098[ichunk];
        if (pchunk <= pnode && pnode < (PAIRNODE *)((char *)pchunk + 0x28000)) {
            *pinode = pnode - pchunk;
            *pichunk = ichunk;
            return;
        }
    }
    *pinode = 0;
    *pichunk = 0;
}

extern "C" void LinkPairNode(PAIRNODE *pnode, PAIRNODE **ppnodeHead)
{
    unsigned inode;
    unsigned ichunk;
    LocateGcNode(pnode, &inode, &ichunk);
    PAIRNODE *pnodeOld = *ppnodeHead;
    if (pnodeOld != 0) {
        unsigned bits = inode & 0x1fff;
        pnodeOld->grf = (pnodeOld->grf & ~0x1fff) | bits;
        pnodeOld->grf = (pnodeOld->grf & ~0x6000) | ((ichunk & 3) << 13);
    }
    unsigned inodeOld;
    unsigned ichunkOld;
    LocateGcNode(*ppnodeHead, &inodeOld, &ichunkOld);
    int grf = (pnode->grf & 0xe000ffff) | ((inodeOld & 0x1fff) << 16);
    pnode->grf = (grf & 0x9fffffff) | ((ichunkOld & 3) << 29);
    *ppnodeHead = pnode;
}
