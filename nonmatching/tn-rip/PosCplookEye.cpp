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
    QW result;
    int vf2Free;
    // fence token: the qmtc2 overwrites the vf2 this block reads
    asm("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tlqc2 vf1, %3\n\tlqc2 vf4, %4\n\tvmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf2, vf4y\n\tvmaddz.xyz vf1, vf1, vf4z" : "=r" (vf2Free) : "m" (mat.row[1]), "m" (mat.row[0]), "m" (mat.row[2]), "m" (mat.row[3]));
    int vf2Ready;
    // fence token: the vadd reads the vf2 the qmtc2 writes
    asm("qmtc2.ni %1, vf2" : "=r" (vf2Ready) : "r" (anchor), "r" (vf2Free));
    asm("vadd.xyzw vf2, vf2, vf1\n\tqmfc2.ni %0, vf2" : "=r" (result) : "r" (vf2Ready));
    return result;
}
