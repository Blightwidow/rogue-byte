#include "sly2.h"
struct GL { char pad0[0x1020]; void *paseg; char p0[0xC]; void *xfa; void *xfb; char pad1[0x1040-0x1038]; QW off; char pad2[0x1060-0x1050]; int f1060; char pad3[0x106C-0x1064]; int f106c; };
struct XF { char pad[0x30]; QW pos; char pad2[0xA0-0x40]; int v; };
extern "C" void PostGuardLoad(GL *);
extern "C" void SetSoProperties(GL *, int, const void *);
extern "C" float *PeaFindAsegLabel(void *, int);
extern "C" void PredictAsegEffect(float, float, void *, GL *, void *, int, QW *, int);
extern "C" void SetSoMass__FP2SOf(GL *, float);
extern char D_002C0A50[];

void func_001BA018(GL *g)
{
    QW mat[4];
    PostGuardLoad(g);
    SetSoProperties(g, 3, D_002C0A50);
    float *t = PeaFindAsegLabel(g->paseg, 0x5DB);
    PredictAsegEffect(*t, 1.0f, g->paseg, g, g->xfa, ((XF *)g->xfb)->v, mat, 0);
    XF *xf = (XF *)g->xfb;
    asm("lqc2 vf2, %1; lqc2 vf1, %2; vsub.xyzw vf2, vf2, vf1; sqc2 vf2, %0" : "=m"(g->off) : "m"(mat[3]), "m"(xf->pos));
    g->f1060 = 0;
    g->f106c = 1;
    SetSoMass__FP2SOf(g, 0.25f);
}
