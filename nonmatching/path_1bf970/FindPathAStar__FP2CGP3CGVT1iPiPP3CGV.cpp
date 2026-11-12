// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
#include "alloc.h"
#include "vu0inline.h"
#include "ps2inline.h"

struct CGV;
struct CG { int ccgv; };
struct CGVEDGE { CGV *pcgvTo; float dist; };
struct CGV { QW pos; int cedge; CGVEDGE *aedge; };
struct ASTARNODE { CGV *pcgv; float sPriority; float sCost; ASTARNODE *pparent; int cStep; ASTARNODE *pnext; };

extern "C" void *CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" int IcgvFromPcgv__FP2CGP3CGV(CG *, CGV *);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);

static inline void *PvAllocStackClear(ALLOCREQ *preq, int cb)
{
    preq->cb = cb;
    preq->cbAlign = 0x10;
    return PvAllocStackClearImpl__Fi(preq);
}
static inline void *PvAllocStack(ALLOCREQ *preq, int cb)
{
    preq->cb = cb;
    preq->cbAlign = 0x10;
    return PvAllocStackImpl__Fi(preq);
}

static inline int FSkip(CG *pcg, CGV *pcgvNext, CGV *pcgvGoal, int *avisited)
{
    if (pcgvNext == pcgvGoal)
        return 0;
    int *pvisited = (int *)(IcgvFromPcgv__FP2CGP3CGV(pcg, pcgvNext) * 4 + (int)avisited);
    if (*pvisited != 0)
        return 1;
    *pvisited = 1;
    return 0;
}

extern "C" void FindPathAStar__FP2CGP3CGVT1iPiPP3CGV(CG *pcg, CGV *pcgvStart, CGV *pcgvGoal, int unused, int *pccgvPath, CGV **apcgvPath)
{
    ASTARNODE nodeStart;
    char frame[16];
    ALLOCREQ req;
    ASTARNODE *pnodeOpen;
    CStackFrame_Construct(frame);
    int *avisited = (int *)PvAllocStackClear(&req, pcg->ccgv * 4);
    ASTARNODE *pnode = &nodeStart;
    pnodeOpen = 0;
    *apcgvPath = (CGV *)pcgvStart;
    nodeStart.cStep = 1;
    nodeStart.pcgv = pcgvStart;
    nodeStart.sCost = 0;
    nodeStart.pparent = 0;
    nodeStart.sPriority = LaneX(SqrtX(SquaredLengthXy(VectorSub(pcgvStart->pos, pcgvGoal->pos))));
    if (pcgvStart != pcgvGoal) {
        do {
            CGV *pcgv = pnode->pcgv;
            for (int iedge = 0; iedge < pcgv->cedge; iedge++) {
                CGVEDGE *pedge = &pcgv->aedge[iedge];
                CGV *pcgvNext = pedge->pcgvTo;
                int skip = FSkip(pcg, pcgvNext, pcgvGoal, avisited);
                if (!skip) {
                    ASTARNODE *pnodeNew = (ASTARNODE *)PvAllocStack(&req, 0x18);
                    pnodeNew->pcgv = pcgvNext;
                    float sCost = pnode->sCost + pedge->dist;
                    pnodeNew->sCost = sCost;
                    float sPriority = sCost + LaneX(SqrtX(SquaredLengthXy(VectorSub(pcgv->pos, pcgvGoal->pos))));
                    pnodeNew->sPriority = sPriority;
                    pnodeNew->pparent = pnode;
                    pnodeNew->cStep = pnode->cStep + 1;
                    ASTARNODE **ppnodeLink = &pnodeOpen;
                    ASTARNODE *pnodeScan = pnodeOpen;
                    while (pnodeScan != 0) {
                        if (pnodeNew->sPriority < pnodeScan->sPriority)
                            break;
                        ppnodeLink = &pnodeScan->pnext;
                        pnodeScan = pnodeScan->pnext;
                    }
                    pnodeNew->pnext = pnodeScan;
                    *ppnodeLink = pnodeNew;
                }
            }
            pnode = pnodeOpen;
            if (pnode == 0)
                goto notfound;
            pnodeOpen = pnode->pnext;
        } while (pnode->pcgv != pcgvGoal);
    }
    if (pnode != 0) {
        *pccgvPath = pnode->cStep;
        do {
            apcgvPath[pnode->cStep - 1] = pnode->pcgv;
            pnode = pnode->pparent;
        } while (pnode != 0);
    } else {
notfound:
        *pccgvPath = 0;
    }
    CStackFrame_Destructor(frame, 2);
}
