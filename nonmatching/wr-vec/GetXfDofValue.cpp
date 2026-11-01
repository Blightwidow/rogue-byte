// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct Frame_22CA18 { QW dead[1]; };
struct XF { char pad[0x94]; unsigned mode; };
extern "C" QW DecomposeRotateMatrixEuler(float *);
// Lanes 0..2 of the vector: mfc1 each float into a GPR, pextlw packs x,y, pcpyld adds z.
static inline QW Build(float x, float y, float z, int variant) {
    QW result;
    QW low;
    asm("mfc1 %0, %1" : "=r"(low) : "f"(x));
    asm("mfc1 %0, %1" : "=r"(result) : "f"(y));
    low = __builtin_pextlw(result, low);
    asm("mfc1 %0, %1" : "=r"(result) : "f"(z));
    return __builtin_pcpyld(result, low);
}
QW GetXfDofValue(XF *xf, float *mat, QW result) {
    Frame_22CA18 frame;
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
        frame.dead[0] = built;
        result = built;
        break;
    case 12:
        z = mat[10]; x = mat[0]; y = mat[5];
        built = Build(x, y, z, 0);
        frame.dead[0] = built;
        result = built;
        break;
    }
    return result;
}
