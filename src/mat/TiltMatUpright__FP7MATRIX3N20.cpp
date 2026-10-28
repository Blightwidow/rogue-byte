#include "sly2.h"
struct Rows { QW row[3]; };
extern QW g_2a2dc0;
extern "C" Rows *BuildRotateVectorsMatrix(Rows *, QW, QW);
extern "C" void TiltMatUpright__FP7MATRIX3N20(Rows *pmat, Rows *pupright, Rows *ptilt)
{
    struct { Rows upright; Rows rotate; Rows junk; } l;
    if (pupright == 0) {
        pupright = &l.upright;
    }
    BuildRotateVectorsMatrix(&l.rotate, pmat->row[2], g_2a2dc0);
    register QW v6 asm("vf6") = l.rotate.row[0];
    pupright->row[0] = v6;
    register QW v5 asm("vf5") = l.rotate.row[1];
    pupright->row[1] = v5;
    register QW v4 asm("vf4") = l.rotate.row[2];
    pupright->row[2] = v4;
    if (ptilt) {
        asm("lqc2 vf1, %0" : : "m" (pmat->row[2]));
        asm("lqc2 vf2, %0" : : "m" (pmat->row[0]));
        asm("vmulax.xyz ACC, vf6, vf1x\n\tvmadday.xyz ACC, vf5, vf1y\n\tvmaddz.xyz vf1, vf4, vf1z");
        asm("lqc2 vf3, %0" : : "m" (pmat->row[1]));
        asm("vmulax.xyz ACC, vf6, vf2x\n\tvmadday.xyz ACC, vf5, vf2y\n\tvmaddz.xyz vf2, vf4, vf2z");
        asm("vmulax.xyz ACC, vf6, vf3x\n\tvmadday.xyz ACC, vf5, vf3y\n\tvmaddz.xyz vf3, vf4, vf3z");
        asm("sqc2 vf1, %0\n\tsqc2 vf2, %1\n\tsqc2 vf3, %2" : "=m" (ptilt->row[2]), "=m" (ptilt->row[0]), "=m" (ptilt->row[1]));
        asm("sqc2 vf2, %0\n\tsqc2 vf2, %1\n\tsqc2 vf3, %2\n\tsqc2 vf3, %3\n\tsqc2 vf1, %4\n\tsqc2 vf1, %5" : "=m" (l.junk.row[0]), "=m" (l.rotate.row[0]), "=m" (l.junk.row[1]), "=m" (l.rotate.row[1]), "=m" (l.junk.row[2]), "=m" (l.rotate.row[2]));
    }
}
