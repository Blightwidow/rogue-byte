#include "sly2.h"
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct LO { char pad0[0xC]; VT *vt; };
struct LEAD { int kind; float radiusA; float radiusB; int pad; QW velocity_unused; };
extern QW g_2a2dc0;
extern "C" QW PosLoWorld(LO *);
QW PredictLoLead(LO *plo, char *plead, float dt)
{
    VT *vt = plo->vt;
    QW velocity = vt->fn((char *)plo + vt->delta);
    struct { QW dtSlot; QW horizontal; } l;
    QW *gp = &g_2a2dc0;
    int fence;
    asm("qmtc2.ni %1, vf3" : "=r" (fence) : "r" (velocity));
    asm("lqc2 vf1, 0(%0)\n\tvmul.xyz vf2, vf3, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z\n\t"
        "vmulx.xyzw vf2, vf1, vf2x\n\tvsub.xyzw vf3, vf3, vf2" : : "r" (gp), "r" (fence));
    asm("sqc2 vf3, %0" : "=m" (l.horizontal));
    QW  pos;
    pos = PosLoWorld(plo);
    asm("lqc2 vf3, %0" : : "m" (l.horizontal));
    asm("qmtc2.ni %0, vf4" : : "r" (pos));
    asm("qmtc2.ni %0, vf2" : : "r" (dt));
    float radiusA = 150.0f;
    float radiusB = 75.0f;
    asm("vadda.xyzw ACC, vf0, vf4\n\tvmaddx.xyzw vf1, vf3, vf2x\n\tsqc2 vf3, 0x20(%0)" : : "r" (plead) : "memory");
    *(float *)(plead + 4) = radiusA;
    *(float *)(plead + 8) = radiusB;
    asm("sqc2 vf1, 0x10(%0)" : : "r" (plead) : "memory");
    asm("sqc2 vf2, %0" : "=m" (l.dtSlot));
    *(int *)plead = 0;
    return pos;
}
