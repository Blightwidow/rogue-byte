#include "sly2.h"
struct M4 { QW row[4]; };
struct M3 { QW row[3]; };
struct XF { char pad0[0xA0]; XF *pxfParent; int generation; };
struct XFMIRROR { XF *pxfSource; XF *pxfTarget; int fPosition; int fRotation; };
extern char B_003DD490[];
extern "C" void InvertMatrix4Affine(M4 *, void *);
extern "C" void InvertMatrix3(M3 *, void *);
extern "C" void NormalizeRotateMatrix3__FP7MATRIX3(void);
extern "C" void __as__6VECTORG9VU_VECTOR(void *, QW);
extern "C" void UpdateXfMirror(void *pv, XFMIRROR *pmirror)
{
    M3 local;
    if (pmirror->fPosition != 0) {
        M4 inv;
        XF *pxfTarget = pmirror->pxfTarget;
        InvertMatrix4Affine(&inv, (char *)pmirror->pxfTarget->pxfParent + 0x40);
        XF *pxfSource = pmirror->pxfSource;
        QW vec;
        asm("lqc2 vf5, %1\n\tlqc2 vf4, %2\n\tlqc2 vf3, %3\n\tlqc2 vf2, %4\n\tlqc2 vf1, %5\n\tvmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf6, vf1, vf0w\n\tqmfc2.ni %0, vf6"
            : "=r" (vec) : "m" (*(QW *)((char *)pxfSource + 0x70)), "m" (inv.row[0]), "m" (inv.row[1]), "m" (inv.row[2]), "m" (inv.row[3]));
        __as__6VECTORG9VU_VECTOR((char *)pxfTarget + 0x30, vec);
        *(float *)((char *)pxfTarget + 0x3C) = 1.0f;
    }
    if (pmirror->fRotation != 0) {
        M4 a;
        M3 inv;
        M3 b;
        InvertMatrix3(&inv, (char *)pmirror->pxfTarget->pxfParent + 0x40);
        QW *src = (QW *)((char *)pmirror->pxfSource + 0x40);
        asm volatile("lqc2 vf3, %2\n\tlqc2 vf4, %3\n\tlqc2 vf6, %4\n\tlqc2 vf5, %5\n\tvmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf6, vf4y\n\tvmaddz.xyz vf4, vf5, vf4z\n\tsqc2 vf4, %0\n\tsqc2 vf4, %1"
            : "=m" (a.row[0]), "=m" (b.row[0]) : "m" (inv.row[0]), "m" (src[0]), "m" (inv.row[1]), "m" (inv.row[2]));
        asm volatile("lqc2 vf2, %2\n\tvmulax.xyz ACC, vf3, vf2x\n\tvmadday.xyz ACC, vf6, vf2y\n\tvmaddz.xyz vf2, vf5, vf2z\n\tsqc2 vf2, %0\n\tsqc2 vf2, %1"
            : "=m" (a.row[1]), "=m" (b.row[1]) : "m" (src[1]));
        asm volatile("lqc2 vf1, %5\n\tvmulax.xyz ACC, vf3, vf1x\n\tvmadday.xyz ACC, vf6, vf1y\n\tvmaddz.xyz vf3, vf5, vf1z\n\tsqc2 vf4, %0\n\tsqc2 vf2, %1\n\tsqc2 vf3, %2\n\tsqc2 vf3, %3"
            : "=m" (local.row[0]), "=m" (local.row[1]), "=m" (local.row[2]), "=m" (b.row[2]) : "m" (src[2]), "m" (src[2]));
        asm volatile("sqc2 vf3, %0" : "=m" (a.row[2]));
        NormalizeRotateMatrix3__FP7MATRIX3();
        XF *pxfTarget = pmirror->pxfTarget;
        ((QW *)pxfTarget)[0] = local.row[0];
        ((QW *)pxfTarget)[1] = local.row[1];
        ((QW *)pxfTarget)[2] = local.row[2];
        ((int *)pxfTarget)[3] = 0;
        ((int *)pxfTarget)[7] = 0;
        ((int *)pxfTarget)[0xB] = 0;
    }
    int *pgen = (int *)(B_003DD490 + 0x3D58);
    *pgen = *pgen + 1;
    pmirror->pxfTarget->generation = *pgen;
}
