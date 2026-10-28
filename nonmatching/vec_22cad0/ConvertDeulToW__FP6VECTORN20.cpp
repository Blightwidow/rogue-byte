// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void CalculateSinCos__FfPfT1(float, float *, float *);
QW ConvertDeulToW__FP6VECTORN20(QW a, QW b, VECTOR *unused)
{
    register QW zeroReg asm("$0");
    VECTOR res;
    float sinY, cosY, sinZ, cosZ;
    CalculateSinCos__FfPfT1(Lane(__builtin_prot3w(a)), &sinY, &cosY);
    CalculateSinCos__FfPfT1(Lane(__builtin_pextuw(zeroReg, a)), &sinZ, &cosZ);
    float dy = Lane(__builtin_prot3w(b));
    float dz = Lane(__builtin_pextuw(zeroReg, b));
    float dx = Lane(b);
    float xv = cosY * cosZ * dx - sinZ * dy;
    float yv = cosY * sinZ * dx + cosZ * dy;
    float zv = -sinY * dx + dz;
    QW low = __builtin_pextlw(Word(yv), Word(xv));
    QW result = __builtin_pcpyld(Word(zv), low);
    *(QW *)&res = result;
    return *(QW *)&res;
}
