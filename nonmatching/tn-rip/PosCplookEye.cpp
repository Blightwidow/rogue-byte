// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct MAT { QW row[4]; };
extern "C" void LoadRotateMatrixPanTilt(MAT *, float, float);
extern "C" QW PosCplookAnchor(void *);
extern const QW RO_002A5000;
extern "C" QW PosCplookEye(float *pcplook)
{
    MAT mat;
    mat.row[3] = RO_002A5000;
    LoadRotateMatrixPanTilt(&mat, pcplook[4], pcplook[5]);
    QW anchor = PosCplookAnchor(pcplook);
    int t1, t2, t3, t4, t5;
    QW result;
    asm("lqc2 vf2, %1" : "=r" (t1) : "m" (mat.row[1]));
    asm("lqc2 vf3, %1" : "=r" (t2) : "m" (mat.row[0]), "r" (t1));
    asm("lqc2 vf1, %1" : "=r" (t3) : "m" (mat.row[2]), "r" (t2));
    asm("lqc2 vf4, %1" : "=r" (t4) : "m" (mat.row[3]), "r" (t3));
    asm("vmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf2, vf4y\n\tvmaddz.xyz vf1, vf1, vf4z" : "=r" (t5) : "r" (t4));
    asm("qmtc2.ni %1, vf2\n\tvadd.xyzw vf2, vf2, vf1\n\tqmfc2.ni %0, vf2" : "=r" (result) : "r" (anchor), "r" (t5));
    return result;
}
