#include "m2c_macros.h"

s32 FIsDlEmpty__FP2DL(s32 *);                       /* extern */
M2C_UNK Obstacle_AddToPathzone(s32);                /* extern */
M2C_UNK RemoveDlEntry(s32 *, s32);                  /* extern */
extern s32 B_003E1A4C;

void AssignObstaclesToPathzones(void) {
    s32 temp_s0;

loop_2:
    if (FIsDlEmpty__FP2DL(&B_003E1A4C) == 0) {
        temp_s0 = B_003E1A4C;
        RemoveDlEntry(&B_003E1A4C, temp_s0);
        Obstacle_AddToPathzone(temp_s0);
        goto loop_2;
    }
}
