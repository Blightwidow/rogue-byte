// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern "C" {
MATRIX4 InvertMatrix4Affine(const MATRIX4 *);
MATRIX4 __ml__FRC7MATRIX4T0(const MATRIX4 &, const MATRIX4 &);
}

// Retail: InvertMatrix4Affine returns its MATRIX4 by hidden pointer (a0 = result, a1 = input, `daddu $v0,$a0` in its
// prologue; Carry_Attach.cpp uses the same signature), so the inverse is an argument expression, not an out-parameter
// local. The product's return temp (sp+0x40) is set up before the argument is evaluated, which puts it below the
// inverse's temp (sp+0x80) and makes gcse hoist its address first (`addiu $s3,$sp,0x40` before `addiu $s2,$sp,0x80`).
// A named `inverse` local passed to a void InvertMatrix4Affine swaps either the two slots or those two addiu.
extern "C" void CombineEyeLookAtProj(const MATRIX4 *eye, const MATRIX4 *proj, MATRIX4 *out)
{
    MATRIX4 basis;
    memset(&basis, 0, sizeof(basis));
    basis.mat[3][3] = 1.0f;
    basis.mat[2][2] = 1.0f;
    basis.mat[1][1] = 1.0f;
    basis.mat[0][0] = 1.0f;
    for (int column = 0; column < 3; column++) {
        basis.mat[0][column] = -eye->mat[1][column];
        basis.mat[1][column] = -eye->mat[2][column];
        basis.mat[2][column] = eye->mat[0][column];
        basis.mat[3][column] = eye->mat[3][column];
    }
    *out = __ml__FRC7MATRIX4T0(*proj, InvertMatrix4Affine(&basis));
}
