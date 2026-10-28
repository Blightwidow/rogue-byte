// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct XF { char pad[0x94]; unsigned mode; };
extern "C" QW DecomposeRotateMatrixEuler(float *);
static inline QW Build(float x, float y, float z, int variant) {
    QW wx = Word(x), wy = Word(y);
    QW low = __builtin_pextlw(wy, wx);
    return __builtin_pcpyld(Word(z), low);
}
QW GetXfDofValue(XF *xf, float *mat, QW result) {
    QW junk;
    float x, y, z;
    QW built;
    switch (xf->mode) {
    case 1: case 4: case 5: case 9: case 10:
        x = mat[12]; y = mat[13]; z = mat[14];
        goto build;
    case 0: case 15:
        break;
    case 6: case 7:
        result = DecomposeRotateMatrixEuler(mat);
        break;
    case 11:
        x = mat[4]; y = mat[8]; z = mat[9];
    build:
        built = Build(x, y, z, 0);
        junk = built; asm("" : : "m" (junk)); result = built;
        break;
    case 12:
        z = mat[10]; x = mat[0]; y = mat[5];
        built = Build(x, y, z, 0);
        junk = built; asm("" : : "m" (junk)); result = built;
        break;
    }
    return result;
}
