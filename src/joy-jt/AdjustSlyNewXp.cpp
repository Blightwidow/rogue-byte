// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
extern "C" {
void AdjustStepNewXp(char *, char *, int);
void AdjustJtZapNewXp(char *, char *, int);
void func_001374E0(char *, char *, int);
void func_0019E9C8(char *, char *, int);
extern float g_2dded0;
extern float D_002BF298;
extern float D_002BF29C;
}
void AdjustSlyNewXp(char *arg0, char *arg1, int arg2)
{
    AdjustStepNewXp(arg0, arg1, arg2);
    switch (*(int *)(arg0 + 0x18C8)) {
    case 8:
        func_0019E9C8(arg0 + 0xF50, arg1, arg2);
        break;
    case 7:
        if (*(int *)(arg1 + 0x9C) == 0xE && *(int *)(arg0 + 0x4C8) == 3 && *(int *)(*(char **)(arg0 + 0x4D4) + 0x1BC) != 0) {
            *(int *)(arg1 + 0x98) = 0;
            if (*(int *)(arg0 + 0x4CC) == 0) {
                *(float *)(arg1 + 0x94) = 0.0f;
            } else {
                QW velocity = *(QW *)(arg1 + 0x80);
                float length = LaneX(SqrtX(SquaredLengthXy(velocity)));
                float low = 0.5f, high = 1.5f;
                float scale = length / *(float *)(arg1 + 0x88) + low;
                if (scale < low)
                    scale = low;
                else if (high < scale)
                    scale = high;
                *(float *)(arg1 + 0x94) = scale;
            }
        }
        break;
    case 4:
        AdjustJtZapNewXp(arg0 + 0xDF0, arg1, arg2);
        break;
    case 6:
        func_001374E0(arg0 + 0x1FF0, arg1, arg2);
        break;
    case 24:
        *(float *)(arg1 + 0x94) = 0.0f;
        *(int *)(arg1 + 0x98) = 0;
        break;
    case 5:
        if ((unsigned)(*(int *)(arg0 + 0x18D0) - 8) < 2U && g_2dded0 - *(float *)(arg0 + 0x18D4) < D_002BF298)
            *(float *)(arg1 + 0x94) = D_002BF29C;
        break;
    }
}
