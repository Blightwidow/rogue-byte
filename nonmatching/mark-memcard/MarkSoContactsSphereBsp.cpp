#include "sly2.h"
struct XF { char pad[0x70]; QW pos; };
struct GEOM { XF *pxf; int pad4; float radius; };
struct SBI { QW pos; QW normal; int xpk; int cookie; int pad[2]; };
struct V4 { QW q; };
extern "C" {
void *func_002564B8(void *);
int CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(QW, float, void *, int, int, void *, int, SBI *);
void PxpAdd(float, void *, void *, void *, QW, QW, int, void *, int, void *);
}
extern "C" void MarkSoContactsSphereBsp(void *psw, GEOM *pgeomSphere, void *pgeomBsp, int cbspPruned, void *abspPruned, void *ppxpFirst)
{
    struct { SBI asbi[0x40]; V4 vecA; V4 vecB; QW pos; QW normal; } l;
    int csbi = CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(pgeomSphere->pxf->pos, pgeomSphere->radius, pgeomBsp, 0x7FFFFFFF, cbspPruned, abspPruned, 0x40, l.asbi);
    for (int isbi = csbi - 1; isbi >= 0; isbi--) {
        SBI *psbi = &l.asbi[isbi];
        l.pos = psbi->pos;
        l.normal = psbi->normal;
        func_002564B8(&l.vecA);
        func_002564B8(&l.vecB);
        float dist;
        int distBits;
        register QW v1 asm("vf1");
        register QW v2 asm("vf2");
        asm("lqc2 vf3, %0" : : "m" (l.normal));
        asm("lqc2 vf4, %0" : : "m" (l.pos));
        asm("vmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w" : "=j" (v1), "=j" (v2));
        asm("vadday.x ACC, vf2, vf2y\n\tvmaddaz.x ACC, vf1, vf2z\n\tvmsubw.x vf2, vf1, vf3w" : "=j" (v2) : "j" (v1), "j" (v2));
        asm("sqc2 vf1, %0" : "=m" (l.vecB) : "j" (v1));
        asm("sqc2 vf2, %0" : "=m" (l.vecA) : "j" (v2));
        asm("qmfc2.ni %0, vf2" : "=r" (distBits) : "j" (v2));
        asm("mtc1 %1, %0" : "=f" (dist) : "r" (distBits));
        PxpAdd(dist, psw, pgeomSphere, pgeomBsp, l.pos, l.normal, psbi->xpk, 0, psbi->cookie, ppxpFirst);
    }
}
