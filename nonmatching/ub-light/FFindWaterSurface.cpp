// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct ALLOCREQ { int cb; int align; };
struct JT { char pad[0x1098]; float zTop; float zBottom; };
struct ALO { char pad[0xE0]; int cpart; };
extern QW g_2a2dd0;
extern "C" {
QW PosLoWorld(void *);
void CStackFrame_Construct(void);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
int CpartCollectAlo(ALO *, int (*)(void *, void *), void *, void *);
int ClsgClipEdgeToObjects(QW, QW, int, void *, int, void *);
int func_00229D60(void *, void *);
}
int FFindWaterSurface(JT *pjt, ALO *pwater, QW *pposSurface)
{
    struct { QW zero; float posTo[4]; float posFrom[4]; QW alsg[0x60]; char frame[0x10]; ALLOCREQ req; } l;
    l.zero = g_2a2dd0;
    QW pos = PosLoWorld(pjt);
    char *pframe = l.frame;
    int t0;
    asm volatile("lqc2 vf1, %1\n\tqmtc2.ni %2, vf3" : "=r" (t0) : "m" (l.zero), "r" (pos));
    float zTop = pjt->zTop;
    asm volatile("vsub.xyzw vf2, vf3, vf1\n\tsqc2 vf2, %0" : "=m" (l.posTo));
    asm volatile("sqc2 vf2, %0" : "=m" (l.posFrom));
    float gTo = l.posTo[2];
    float zBottom = pjt->zBottom;
    float gFrom = l.posFrom[2];
    gTo += zTop;
    gFrom += zBottom;
    l.posTo[2] = gTo;
    l.posFrom[2] = gFrom;
    CStackFrame_Construct();
    ALLOCREQ *preq = &l.req;
    preq->cb = pwater->cpart << 2;
    preq->align = 0x10;
    void *apart = PvAllocStackImpl__Fi(preq);
    int cpart = CpartCollectAlo(pwater, func_00229D60, 0, apart);
    if (!ClsgClipEdgeToObjects(*(QW *)l.posFrom, *(QW *)l.posTo, cpart, apart, 0x10, l.alsg)) {
        CStackFrame_Destructor(pframe, 2);
        return 0;
    }
    asm volatile("lqc2 vf1, %0" : : "m" (l.alsg[0]));
    asm volatile("lqc2 vf2, %0" : : "m" (l.zero));
    asm volatile("vadd.xyzw vf1, vf1, vf2");
    asm volatile("sqc2 vf1, %0" : "=m" (*pposSurface));
    CStackFrame_Destructor(pframe, 2);
    return 1;
}
