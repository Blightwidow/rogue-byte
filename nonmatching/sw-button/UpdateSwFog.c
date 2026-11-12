#include "m2c_macros.h"

M2C_UNK ConvertHsvToRgb__FP6VECTORT0(void *, M2C_UNK *, f32, s32, s32); /* extern */
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
M2C_UNK GreyColor_1ed2d8(s8 *, M2C_UNK *);                /* extern */
extern M2C_UNK g_2bbb60;

void UpdateSwFog(void *arg0) {
    char sp[0x10];
    M2C_UNK sp18;
    M2C_UNK sp10;
    f32 temp_f0;

    ConvertHsvToRgb__FP6VECTORT0(sp, &sp10, M2C_FIELD(arg0, f32 *, 0x3E10), M2C_FIELD(arg0, f32 *, 0x3E14) * 0.003921569f, M2C_FIELD(arg0, f32 *, 0x3E18) * 0.003921569f);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    GreyColor_1ed2d8(arg0, &sp10);
    M2C_ERROR(/* unknown instruction: ldl $v1, 0x17($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0x3e2f($s1) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, 0x3e28($s1) */);
    M2C_FIELD(arg0, s32 *, 0x3E30) = sp18;
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x3E24) * 0.003921569f;
    M2C_FIELD(arg0, f32 *, 0x3E34) = temp_f0;
    if (M2C_FIELD(arg0, s32 *, 0x3E38) != 0) {
        M2C_FIELD(arg0, f32 *, 0x3E34) = GLimitLm__FP2LMf(&g_2bbb60, temp_f0 + 0.3f);
    }
    M2C_FIELD(arg0, s32 *, 0x3D5C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3D5C) + 1);
}
