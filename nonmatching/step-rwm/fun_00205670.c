#include "m2c_macros.h"

s32 FIntersectRayTriangle(s128, s128, s128, s128);  /* extern */
M2C_UNK func_002057E8(void *);                      /* extern */
extern s128 g_2a2dc0;

s32 func_00205670(void *arg0, s128 arg1, s128 arg2, s32 arg3) {
    char sp[0x400];
    M2C_UNK sp20;
    s128 sp60;
    f32 sp80;
    s128 sp90;
    s128 spA0;
    M2C_UNK *var_s0;
    s32 temp_v0;
    void *var_s1;

    spA0 = arg1;
    sp90 = arg2;
    if (M2C_FIELD(arg0, s32 *, 0x208) != 0) {
        func_002057E8(sp);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */) < 0.0001f) {
            sp60 = g_2a2dc0;
        } else {
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x60($sp) */);
        }
        var_s0 = &sp20;
        var_s1 = sp;
loop_6:
        temp_v0 = FIntersectRayTriangle(sp60, spA0, M2C_FIELD(var_s0, s128 *, -0x20), M2C_FIELD(var_s0, s128 *, -0x10)) & 1;
        if (!(sp80 <= M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */)) || (temp_v0 == 0)) {
            var_s1 += 0x30;
            var_s0 += 0x30;
            if ((u32) var_s1 >= (u32) &sp60) {
                goto block_9;
            }
            goto loop_6;
        }
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s4) */);
        return 1;
    }
block_9:
    return 0;
}
