#include "m2c_macros.h"

f32 GRandInRange(M2C_UNK, f32);                     /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK, s128); /* extern */
extern s128 g_2a2dc0;
extern f32 g_2be8c4;

void AttachCyl_GetRandomPos(void *arg0, s32 arg1, s128 *arg2) {
    f32 temp_f20;
    f32 temp_f21;

    temp_f21 = GRandInRange(0xC0490FDB, 3.1415927f);
    temp_f20 = GRandInRange(0, g_2be8c4) + M2C_FIELD(arg0, f32 *, 0x10C);
    SetVectorCylind__FP6VECTORfff(temp_f21, temp_f20, 0, PosLoWorld(arg0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s1) */);
    *arg2 = g_2a2dc0;
}
