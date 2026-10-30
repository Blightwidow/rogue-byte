#include "sly2.h"
struct XF { char pad[0x70]; QW pos; };
struct GEOM { XF *pxf; int pad4; float radius; };
extern QW g_2a2dc0;
extern "C" void PxpAdd(float, void *, void *, void *, QW, QW);
extern "C" void MarkSoContactsSphereSphere(void *psw, GEOM *pg0, GEOM *pg1, void *ppxpFirst)
{
    XF *pxf1 = pg1->pxf;
    float radiusSum;
    float dist2;
    QW tmp;
    QW normal;
    asm("lqc2 vf1, %0" : : "m" (pxf1->pos));
    radiusSum = pg0->radius + pg1->radius;
    XF *pxf0 = pg0->pxf;
    asm("lqc2 vf4, %0" : : "m" (pxf0->pos));
    asm("vsub.xyzw vf3, vf4, vf1");
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    int dist2bits;
    asm("qmfc2.ni %0, vf1" : "=r" (dist2bits));
    asm("mtc1 %1, %0\n\tnop" : "=f" (dist2) : "r" (dist2bits));
    if (radiusSum * radiusSum < dist2) return;
    float dist;
    if (dist2 < 0.0001f) {
        dist = 0.0f;
        asm("lqc2 vf2, %0" : : "m" (g_2a2dc0));
    } else {
        asm("nop\n\tnop\n\tsqrt.s %0, %1" : "=&f" (dist) : "f" (dist2));
        asm("qmtc2.ni %0, vf1\n\tsqc2 vf1, %1" : : "r" (dist), "m" (tmp));
        asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q");
    }
    asm("qmfc2.ni %0, vf2" : "=r" (normal));
    float nr = -pg0->radius;
    QW pos;
    asm("qmtc2.ni %0, vf1" : : "r" (nr));
    asm("vadda.xyzw ACC, vf0, vf4\n\tvmaddx.xyzw vf3, vf2, vf1x\n\tsqc2 vf1, %0" : "=m" (tmp));
    asm("qmfc2.ni %0, vf3" : "=r" (pos));
    PxpAdd(dist - radiusSum, psw, pg0, pg1, pos, normal);
}
