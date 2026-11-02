#include "sly2.h"
struct M4 { QW row[4]; };
struct XFN { char pad[0xA0]; XFN *next; };
extern "C" {
static inline void AddRows(M4 *dst, M4 *srcA, M4 *srcB)
{
    QW *pa = &srcA->row[0];
    QW *pb = &srcB->row[0];
    QW *pd = &dst->row[0];
    int count = 3;
    do {
        asm volatile("lqc2 vf1, 0(%0)" : : "r"(pa));
        count -= 1;
        asm volatile("lqc2 vf2, 0(%0)" : : "r"(pb));
        pa++;
        asm volatile("vadd.xyzw vf1, vf1, vf2");
        pb++;
        asm volatile("sqc2 vf1, 0(%0)" : : "r"(pd));
        pd++;
    } while (count >= 0);
}
void PredictXfLocal(XFN *, M4 *, M4 *, float);
void __ml__FRC7MATRIX4T0(M4 *, const M4 *, const M4 *);
void PredictXfTransformAdjust(XFN *begin, XFN *end, M4 *parent, M4 *adjust, float time)
{
    struct LOCALS { M4 local, world, pm, am, sum, prod, wprod; } l;
    if (adjust) {
        l.am.row[0] = adjust->row[0];
        l.am.row[1] = adjust->row[1];
        l.am.row[2] = adjust->row[2];
        l.am.row[3] = adjust->row[3];
    } else {
        memset(&l.am, 0, 0x40);
    }
    if (parent) {
        l.pm.row[0] = parent->row[0];
        l.pm.row[1] = parent->row[1];
        l.pm.row[2] = parent->row[2];
        l.pm.row[3] = parent->row[3];
    } else {
        memset(&l.pm, 0, 0x40);
        float *pf = (float *)&l.pm;
        pf[15] = 1.0f;
        pf[5] = pf[10] = 1.0f;
        pf[0] = 1.0f;
    }
    M4 *pworld = &l.world;
    M4 *pprod = &l.prod;
    M4 *pwprod = &l.wprod;
    M4 *psum = &l.sum;
    for (XFN *node = begin; node != end; node = node->next) {
        PredictXfLocal(node, &l.local, pworld, time);
        __ml__FRC7MATRIX4T0(pprod, &l.local, &l.am);
        __ml__FRC7MATRIX4T0(pwprod, pworld, &l.pm);
        AddRows(psum, pprod, pwprod);
        l.am.row[0] = l.sum.row[0];
        l.am.row[1] = l.sum.row[1];
        l.am.row[2] = l.sum.row[2];
        l.am.row[3] = l.sum.row[3];
        __ml__FRC7MATRIX4T0(psum, &l.local, &l.pm);
        l.pm.row[0] = l.sum.row[0];
        l.pm.row[1] = l.sum.row[1];
        l.pm.row[2] = l.sum.row[2];
        l.pm.row[3] = l.sum.row[3];
    }
    if (parent) {
        parent->row[0] = l.pm.row[0];
        parent->row[1] = l.pm.row[1];
        parent->row[2] = l.pm.row[2];
        parent->row[3] = l.pm.row[3];
    }
    if (adjust) {
        adjust->row[0] = l.am.row[0];
        adjust->row[1] = l.am.row[1];
        adjust->row[2] = l.am.row[2];
        adjust->row[3] = l.am.row[3];
    }
}
}
