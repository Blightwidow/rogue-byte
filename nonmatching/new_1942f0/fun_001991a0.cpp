#include "sly2.h"
struct VT { char p[0x290]; short d; short i; void (*fn)(void *, int, void *, QW, QW, QW); };
struct OBJ { char pad[0xC]; VT *vt; };
struct GEOM { OBJ *pxf; void *p4; };
struct JMP { OBJ *pjt; char pad0[0x1C - 4]; int jtbs; char pad1[0xC8 - 0x20]; GEOM *pgeom; char pad2[4]; QW contact; QW normal; QW offset; };
extern "C" {
QW PosLoWorld(void *);
QW ConvertXfPos(void *, void *, QW);
void GetNormalVectors__FP6VECTORN30(QW, QW, QW, void *);
}
extern QW g_2a2dc0;
extern QW g_2a2db0;
struct L { QW posJt; QW posLedge; QW normalIn; QW side0; QW side1; QW neg; };
extern "C" void func_001991A0(JMP *pjmp)
{
    L l;
    if (pjmp->jtbs != 0x11) return;
    l.posJt = PosLoWorld(pjmp->pjt);
    l.posLedge = ConvertXfPos(pjmp->pgeom->pxf, 0, pjmp->contact);
    QW normalIn;
    float nf = -1.0f;
    int bits;
    asm("lqc2 vf1, %0" : : "m" (pjmp->normal));
    asm("mfc1 %0, %1" : "=r" (bits) : "f" (nf));
    asm("qmtc2.ni %0, vf2" : : "r" (bits));
    asm("vmulx.xyzw vf1, vf1, vf2x");
    asm("qmfc2.ni %0, vf1" : "=r" (normalIn));
    asm("sqc2 vf2, %0" : "=m" (l.neg));
    asm("sqc2 vf1, %0" : "=m" (l.normalIn));
    QW *pside = &l.side0;
    GetNormalVectors__FP6VECTORN30(normalIn, g_2a2dc0, g_2a2db0, pside);
    QW hang;
    asm("lqc2 vf3, %1\n\tlqc2 vf5, %2\n\tlqc2 vf4, %3\n\tlqc2 vf2, %4\n\tlqc2 vf1, %5\n\tvmulax.xyz ACC, vf5, vf3x\n\tvmadday.xyz ACC, vf4, vf3y\n\tvmaddz.xyz vf3, vf2, vf3z\n\tvsub.xyzw vf1, vf1, vf3\n\tsqc2 vf1, %6\n\tqmfc2.ni %0, vf1" : "=r" (hang) : "m" (pjmp->offset), "m" (l.normalIn), "m" (l.side0), "m" (l.side1), "m" (l.posLedge), "m" (l.posLedge));
    OBJ *pjt = pjmp->pjt;
    pjt->vt->fn((char *)pjt + pjt->vt->d, 7, pjmp->pgeom->p4, hang, g_2a2db0, l.posJt);
}
