// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
extern "C" {
int ReplaceHitFx(int, QW, int, int);
int ReplaceSwHitFx(char *self, int side, QW vec, int a, int b) {
    int target;
    switch (side) {
    case 0:
        target = *(int *)(self + 0x4020);
        break;
    case 1:
        target = *(int *)(self + 0x4024);
        break;
    default:
        target = 0;
        break;
    }
    return ReplaceHitFx(target, vec, a, b);
}
}
