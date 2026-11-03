// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct M4 { QW row[4]; };
struct XFN { M4 local; M4 world; char pad[0xA0 - 0x80]; XFN *parent; int generation; };
struct VT_186A50 { char pad[0x10]; short delta; short index; void (*fn)(void *, float *, int, float, float); };
struct OBJ_186A50 { VT_186A50 *vt; };
struct IKLIMB {
    XFN *root;            // 0x00
    XFN *upper;           // 0x04
    XFN *lower;           // 0x08
    XFN *chain;           // 0x0C
    M4 xf;                // 0x10
    QW rot[3];            // 0x50
    QW posLower;          // 0x80
    QW axis;              // 0x90
    QW target;            // 0xA0
    QW effector;          // 0xB0
    float lenUpper;       // 0xC0
    float lenLower;       // 0xC4
    float angleRest;      // 0xC8
    float angleSwing;     // 0xCC
    OBJ_186A50 *pobj;     // 0xD0
    float *pswing;        // 0xD4
};
struct G_186A50 { char pad[0x3D58]; int counter; };
extern G_186A50 B_003DD490;
extern "C" {
float acosf(float);
QW *LoadRotateMatrixRad(QW *, QW, float);
QW *__as__6VECTORG9VU_VECTOR(QW *, QW);
float RadBetweenVectors__FP6VECTORN20(QW, QW, QW *);
QW ConvertXfVec(XFN *, XFN *, QW);
}
extern "C" void SolveIkLimb(void *, IKLIMB *limb)
{
    QW l[23];
    float lo = -1.0f;
    float hi = 1.0f;
    limb->upper->local = limb->xf;
    XFN *upper = limb->upper;
    XFN *root = limb->root;
    XFN *parent = upper->parent;
    asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(limb));
    char *rootWorld = (char *)root + 0x40;
    char *parentWorld = (char *)parent + 0x40;
    asm volatile("lqc2 vf7, 0x40(%0)" : : "r"(parent));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(parentWorld));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(parentWorld));
    asm volatile("lqc2 vf6, 0x30(%0)" : : "r"(parentWorld));
    asm volatile("vmulax.xyz ACC, vf7, vf3x");
    asm volatile("vmadday.xyz ACC, vf2, vf3y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf3z");
    asm volatile("vmaddw.xyz vf4, vf6, vf0w");
    asm volatile("lqc2 vf5, 0x40(%0)" : : "r"(root));
    asm volatile("lqc2 vf8, 0x30(%0)" : : "r"(rootWorld));
    asm volatile("sqc2 vf4, %0" : "=m"(l[21]));
    asm volatile("lqc2 vf4, 0xa0(%0)" : : "r"(limb));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(rootWorld));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(rootWorld));
    asm volatile("vmulax.xyz ACC, vf5, vf4x");
    asm volatile("vmadday.xyz ACC, vf2, vf4y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf4z");
    asm volatile("vmaddw.xyz vf5, vf8, vf0w");
    float a = limb->lenUpper;
    asm volatile("lqc2 vf1, %0" : : "m"(l[21]));
    asm volatile("vsub.xyzw vf1, vf5, vf1");
    float aa = a * a;
    asm volatile("sqc2 vf1, %0" : "=m"(l[22]));
    float twoA = a + a;
    asm volatile("lqc2 vf3, %0" : : "m"(l[22]));
    asm volatile("vmul.xyz vf1, vf1, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    float b = limb->lenLower;
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    QW dist;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(dist));
    float d;
    asm("mtc1 %1, %0" : "=f"(d) : "r"(dist)); // lane 0: the distance
    float c = (d * d - aa - b * b) / (twoA * b);
    if (c < lo)
        c = lo;
    else if (hi < c)
        c = hi;
    M4 *pxf = &limb->xf;
    float angle = acosf(c) - limb->angleRest;
    LoadRotateMatrixRad(&l[0], limb->axis, angle);
    asm volatile("lqc2 vf2, 0x50(%0)" : : "r"(limb));
    char *prot = (char *)limb + 0x50;
    asm volatile("lqc2 vf5, %0" : : "m"(l[1]));
    asm volatile("lqc2 vf3, %0" : : "m"(l[0]));
    asm volatile("lqc2 vf4, %0" : : "m"(l[2]));
    XFN *lower = limb->lower;
    asm volatile("vmulax.xyz ACC, vf3, vf2x");
    asm volatile("vmadday.xyz ACC, vf5, vf2y");
    asm volatile("vmaddz.xyz vf2, vf4, vf2z");
    asm volatile("sqc2 vf2, %0" : "=m"(l[3]));
    QW *pposLower = &lower->local.row[3];
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(prot));
    QW posLower = limb->posLower;
    asm volatile("vmulax.xyz ACC, vf3, vf1x");
    asm volatile("vmadday.xyz ACC, vf5, vf1y");
    asm volatile("vmaddz.xyz vf1, vf4, vf1z");
    asm volatile("sqc2 vf1, %0" : "=m"(l[4]));
    asm volatile("sqc2 vf1, %0" : "=m"(l[7]));
    asm volatile("sqc2 vf2, %0" : "=m"(l[6]));
    asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(prot));
    asm volatile("vmulax.xyz ACC, vf3, vf2x");
    asm volatile("vmadday.xyz ACC, vf5, vf2y");
    asm volatile("vmaddz.xyz vf3, vf4, vf2z");
    asm volatile("sqc2 vf3, %0" : "=m"(l[5]));
    asm volatile("sqc2 vf3, %0" : "=m"(l[8]));
    __as__6VECTORG9VU_VECTOR(pposLower, posLower);
    QW *paxis = &l[3];
    QW *pmatSwing = &l[9];
    QW *pmatTwist = &l[12];
    lower->local.row[0] = l[3];
    lower->local.row[1] = l[4];
    lower->local.row[2] = l[5];
    ((float *)&lower->local)[15] = 1.0f;
    ((float *)&lower->local)[7] = 0;
    ((float *)&lower->local)[3] = 0;
    ((float *)&lower->local)[11] = 0;
    XFN *end = limb->upper->parent;
    XFN *link = limb->chain;
    asm volatile("lqc2 vf5, 0xb0(%0)" : : "r"(limb));
    while (link != end) {
        int fence;
        asm("lqc2 vf4, 0x0(%1)" : "=r"(fence) : "r"(link));
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(link), "r"(fence));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(link));
        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(link));
        link = link->parent;
        asm volatile("vmulax.xyz ACC, vf4, vf5x");
        asm volatile("vmadday.xyz ACC, vf3, vf5y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf5z");
        asm volatile("vmaddw.xyz vf5, vf1, vf0w");
    }
    XFN *top = limb->upper->parent;
    char *topWorld = (char *)top + 0x40;
    asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(top));
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(topWorld));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(topWorld));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(topWorld));
    asm volatile("vmulax.xyz ACC, vf4, vf5x");
    asm volatile("vmadday.xyz ACC, vf2, vf5y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf5z");
    asm volatile("vmaddw.xyz vf5, vf3, vf0w");
    asm volatile("lqc2 vf1, %0" : : "m"(l[21]));
    asm volatile("vsub.xyzw vf1, vf5, vf1");
    QW reach;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(reach));
    float swing = RadBetweenVectors__FP6VECTORN20(reach, l[22], paxis);
    QW axis = ConvertXfVec(0, limb->upper->parent, l[3]);
    asm volatile("qmtc2.ni %0, vf1" : : "r"(axis));
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("sqc2 vf1, %0" : "=m"(l[3]));
    asm volatile("vdiv Q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf3, vf1, Q");
    QW unitAxis;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(unitAxis));
    LoadRotateMatrixRad(pmatSwing, unitAxis, swing);
    OBJ_186A50 *pobj = limb->pobj;
    l[4] = l[9];
    l[5] = l[10];
    l[6] = l[11];
    if (pobj != 0) {
        VT_186A50 *vt = pobj->vt;
        vt->fn((char *)pobj + vt->delta, &limb->angleSwing, 0, *limb->pswing, 0.0f);
    }
    QW dir = ConvertXfVec(0, limb->upper->parent, l[22]);
    asm volatile("qmtc2.ni %0, vf2" : : "r"(dir));
    asm volatile("vmul.xyz vf1, vf2, vf2");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf3, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("vdiv Q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf4, vf2, Q");
    QW unitDir;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(unitDir));
    LoadRotateMatrixRad(pmatTwist, unitDir, limb->angleSwing);
    asm volatile("lqc2 vf9, %0" : : "m"(l[12]));
    G_186A50 *pg = &B_003DD490;
    asm volatile("lqc2 vf6, %0" : : "m"(l[13]));
    asm volatile("lqc2 vf7, %0" : : "m"(l[14]));
    asm volatile("lqc2 vf2, %0" : : "m"(l[4]));
    asm volatile("lqc2 vf3, %0" : : "m"(l[5]));
    asm volatile("vmulax.xyz ACC, vf9, vf2x");
    asm volatile("vmadday.xyz ACC, vf6, vf2y");
    asm volatile("vmaddz.xyz vf2, vf7, vf2z");
    asm volatile("lqc2 vf1, %0" : : "m"(l[6]));
    asm volatile("vmulax.xyz ACC, vf9, vf3x");
    asm volatile("vmadday.xyz ACC, vf6, vf3y");
    asm volatile("vmaddz.xyz vf3, vf7, vf3z");
    asm volatile("lqc2 vf8, %0" : : "m"(pxf->row[2]));
    asm volatile("vmulax.xyz ACC, vf9, vf1x");
    asm volatile("vmadday.xyz ACC, vf6, vf1y");
    asm volatile("vmaddz.xyz vf1, vf7, vf1z");
    asm volatile("lqc2 vf5, %0" : : "m"(limb->xf.row[0]));
    asm volatile("vmulax.xyz ACC, vf2, vf8x");
    asm volatile("vmadday.xyz ACC, vf3, vf8y");
    asm volatile("vmaddz.xyz vf8, vf1, vf8z");
    asm volatile("lqc2 vf4, %0" : : "m"(pxf->row[1]));
    asm volatile("vmulax.xyz ACC, vf2, vf5x");
    asm volatile("vmadday.xyz ACC, vf3, vf5y");
    asm volatile("vmaddz.xyz vf5, vf1, vf5z");
    asm volatile("sqc2 vf2, %0" : "=m"(l[18]));
    asm volatile("vmulax.xyz ACC, vf2, vf4x");
    asm volatile("vmadday.xyz ACC, vf3, vf4y");
    asm volatile("vmaddz.xyz vf4, vf1, vf4z");
    asm volatile("sqc2 vf3, %0" : "=m"(l[19]));
    asm volatile("sqc2 vf1, %0" : "=m"(l[20]));
    XFN *up = limb->upper;
    asm volatile("sqc2 vf4, %0" : "=m"(l[11]));
    asm volatile("sqc2 vf8, %0" : "=m"(l[12]));
    asm volatile("sqc2 vf9, %0" : "=m"(l[7]));
    asm volatile("sqc2 vf6, %0" : "=m"(l[8]));
    asm volatile("sqc2 vf7, %0" : "=m"(l[9]));
    asm volatile("sqc2 vf2, %0" : "=m"(l[15]));
    asm volatile("sqc2 vf3, %0" : "=m"(l[16]));
    asm volatile("sqc2 vf1, %0" : "=m"(l[17]));
    asm volatile("sqc2 vf5, %0" : "=m"(l[18]));
    asm volatile("sqc2 vf5, %0" : "=m"(l[10]));
    asm volatile("sqc2 vf4, %0" : "=m"(l[19]));
    asm volatile("sqc2 vf8, %0" : "=m"(l[20]));
    asm volatile("sqc2 vf5, %0" : "=m"(up->local.row[0]));
    up->local.row[1] = l[11];
    up->local.row[2] = l[12];
    ((float *)&up->local)[11] = 0;
    ((float *)&up->local)[7] = 0;
    ((float *)&up->local)[3] = 0;
    int generation = ++pg->counter;
    limb->upper->generation = generation;
    limb->lower->generation = generation;
}
