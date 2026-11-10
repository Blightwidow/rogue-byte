// SPDX-License-Identifier: GPL-3.0-or-later
#include "dl.h"
struct JSG;
struct JVT { char pad[0x18]; short delta; short index; void (*fn)(char *, int, int, int, int, int); };
struct JSG {
    char pad0[0xC];
    JVT *vt;
    char pad1[0x40 - 0x10];
    unsigned grf;
    char pad2[0x54 - 0x44];
    int ajsge;
    char pad3[0x5C - 0x58];
    DL dlSeqnode;
    char pad4[0x6C - 0x68];
    int psoSubject;
    float tRun;
    int fRunning;
    int fLatched;
    int fPendingCut;
};
extern "C" {
void StopSeqnode(void *);
void func_001E0120(JSG *);
void func_001A6CA8(JSG *, int);
}

// Retail reads the list's ibDle once (lw v0,8(a0)) and takes the first node
// through the iterator's own cursor, which starts at the list head: the loop
// is the PvStep-first form of OnRipgRemove (src/rip/), with no separate
// "first" helper re-reading pdl->ibDle.
void StopJsg(JSG *pjsg)
{
    if (pjsg->fRunning == 0)
        return;
    pjsg->psoSubject = 0;
    pjsg->tRun = 0.0f;
    pjsg->fRunning = 0;
    DLI dli;
    PushDli(&dli, &pjsg->dlSeqnode);
    char *pseqnode;
    for (pseqnode = (char *)PvStep(&dli); pseqnode != 0; pseqnode = (char *)PvStep(&dli))
        StopSeqnode(pseqnode);
    func_001E0120(pjsg);
    if (pjsg->fLatched != 0) {
        func_001A6CA8(pjsg, 2);
        unsigned grf = pjsg->grf;
        if (((grf ^ 1) & 1) != 0)
            *(int *)grf &= -3;
        else
            pjsg->grf = (int)grf & -3;
    }
    pjsg->vt->fn((char *)pjsg + pjsg->vt->delta, 6, 0, 0, 0, 0);
    PopDli(&dli);
}
