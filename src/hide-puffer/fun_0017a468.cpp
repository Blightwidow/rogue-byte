// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern "C" void func_0017A468(char *p)
{
    char *pother = *(char **)(p + 0x10);
    QW *mat = (QW *)(p + 0x70);
    QW base = *(QW *)(*(char **)(pother + 0x60) + 0x30);
    QW offset = *(QW *)(*(char **)(pother + 0xF90) + 0x90);
    QW pos = *(QW *)(p + 0x50);
    QW delta;
    asm("vsub.xyzw %0, %1, %2" : "=j"(delta) : "j"(pos), "j"(base));
    /* xyz = mat * offset, w kept from offset */
    QW rotated;
    asm("vmulax.xyz ACC, %1, %4x\n\tvmadday.xyz ACC, %2, %4y\n\tvmaddz.xyz %0, %3, %4z" : "=j"(rotated) : "j"(mat[0]), "j"(mat[1]), "j"(mat[2]), "0"(offset));
    QW result;
    asm("vsub.xyzw %0, %1, %2" : "=j"(result) : "j"(delta), "j"(rotated));
    *(QW *)(p + 0x50) = result;
}
