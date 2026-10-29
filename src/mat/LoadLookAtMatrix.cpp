/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
extern "C" void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(void *out, int passthrough, QW basis);
extern "C" QW g_2a2dc0;
extern "C" void *LoadLookAtMatrix(void *matrix, int passthrough) {
    QW scratch[3];
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(scratch, passthrough, g_2a2dc0);
    memcpy(matrix, scratch, 0x30);
    return matrix;
}
