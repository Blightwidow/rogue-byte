#include "m2c_macros.h"

f32 GRandInRange(f32, f32);                         /* extern */
M2C_UNK func_001CE9B8();                            /* extern */
extern M2C_UNK g_2bbb60;
extern M2C_UNK g_2c1f78;
extern M2C_UNK g_2c1f80;

void PostShrapnelEmit__FP8SHRAPNELP5EMITB(void *arg0, void *arg1) {
    f32 *var_s0;
    f32 temp_f20;
    f32 temp_v1;
    f32 var_f2;
    s32 var_s1;

    func_001CE9B8();
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s1) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (M2C_FIELD(arg0, f32 *, 0x18) * GRandInRange(M2C_FIELD(&g_2c1f78, f32 *, 0), M2C_FIELD(&g_2c1f78, f32 *, 4)));
    M2C_FIELD(arg0, f32 *, 0xF0) = (f32) M2C_FIELD(arg1, f32 *, 0xF0);
    M2C_FIELD(arg0, f32 *, 0xF4) = (f32) M2C_FIELD(arg1, f32 *, 0xF4);
    M2C_FIELD(arg0, f32 *, 0xF8) = (f32) M2C_FIELD(arg1, f32 *, 0xF8);
    var_f2 = M2C_FIELD(&g_2c1f80, f32 *, 0) + (temp_v1 * (M2C_FIELD(&g_2c1f80, f32 *, 4) + (temp_v1 * M2C_FIELD(&g_2c1f80, f32 *, 8))));
    if (var_f2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
        var_f2 = M2C_FIELD(&g_2bbb60, f32 *, 0);
    } else if (M2C_FIELD(&g_2bbb60, f32 *, 4) < var_f2) {
        var_f2 = M2C_FIELD(&g_2bbb60, f32 *, 4);
    }
    var_s0 = arg0 + 0xD0;
    var_s1 = 2;
    temp_f20 = var_f2 * 10.0f;
    do {
        var_s1 -= 1;
        *var_s0 = GRandInRange(-temp_f20, temp_f20);
        var_s0 += 4;
    } while (var_s1 >= 0);
}
