/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct ALLOCREQ { int cb; int align; };
struct OXA { char pad[0x18 + 4]; };
struct SO { char pad0[0xE0]; int cgeom; char pad1[0xEC - 0xE4]; char *poxa; };
extern QW g_2a2dc0;
extern QW g_2a2dd0;
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float LaneY(QW q) { QW t; float f; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline float LaneZ(QW q) { QW t; float f; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
extern "C" {
QW PosLoWorld(void *);
int FIsBasicDerivedFrom(void *, int);
int FFloatsNear__Ffff(float, float, float);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
int CpartCollectAlo(void *, int (*)(void *, void *), void *, void *);
int ClsgClipEdgeToObjects(QW, QW, int, void *, int, void *);
int func_00229D60(void *, void *);
float UGetWaterSubmerged(SO *pwater, SO *pso, QW *pposSurface, QW *pnormalSurface)
{
    struct { QW pos0; QW pos1; char frame[0x10]; ALLOCREQ req; QW alsg[0x60]; } l;
    char *pframe = l.frame;
    QW p = PosLoWorld(pso);
    l.pos1 = p;
    l.pos0 = p;
    float *z0 = (float *)&l.pos0 + 2;
    if (FIsBasicDerivedFrom(pso, 0x33)) {
        float bottom = *z0 + *(float *)((char *)pso + 0x248);
        *z0 = bottom;
        if (*(int *)((char *)pso + 0x208) != 0) {
            float floor = *(float *)((char *)pso + 0x238);
            *z0 = bottom > floor ? bottom : floor;
        }
    } else {
        *z0 = *(float *)(*(char **)((char *)pso + 0xEC) + 8);
    }
    *((float *)&l.pos1 + 2) = *(float *)(*(char **)((char *)pso + 0xEC) + 0x18);
    CStackFrame_Construct(pframe);
    ALLOCREQ *preq = &l.req;
    preq->cb = pwater->cgeom << 2;
    preq->align = 0x10;
    void *apart = PvAllocStackImpl__Fi(preq);
    int cpart = CpartCollectAlo(pwater, func_00229D60, 0, apart);
    if (!ClsgClipEdgeToObjects(l.pos0, l.pos1, cpart, apart, 0x10, l.alsg)) {
        if (pnormalSurface)
            *pnormalSurface = g_2a2dc0;
        CStackFrame_Destructor(pframe, 2);
        return 0.0f;
    }
    if (pposSurface)
        *pposSurface = l.alsg[1];
    if (pnormalSurface) {
        QW plane = l.alsg[3];
        *pnormalSurface = plane;
        QW zero = g_2a2dd0;
        int none = 0;
        float eps0 = 0.0001f;
        asm("" : "+f" (eps0));
        if (FFloatsNear__Ffff(LaneX(zero), LaneX(plane), eps0)) {
            float eps1 = 0.0001f;
            asm("" : "+f" (eps1));
            if (FFloatsNear__Ffff(LaneY(zero), LaneY(plane), eps1)) {
                float eps2 = 0.0001f;
                asm("" : "+f" (eps2));
                none = FFloatsNear__Ffff(LaneZ(zero), LaneZ(plane), eps2) != 0;
            }
        }
        if (none)
            *pnormalSurface = g_2a2dc0;
    }
    float entry = ((float *)&l.alsg[4])[0];
    float exit = ((float *)&l.alsg[4])[1];
    float result = exit - entry;
    CStackFrame_Destructor(pframe, 2);
    return result;
}
}
