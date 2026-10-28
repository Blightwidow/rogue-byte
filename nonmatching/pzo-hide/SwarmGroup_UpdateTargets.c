#include "m2c_macros.h"

f32 SMaxCrv(s32);                                   /* extern */

f32 SwarmGroup_UpdateTargets(s32 arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f7;
    f32 var_f0;
    f32 var_f3;
    f32 var_f5;
    s32 var_a0;
    void *var_v1;

    temp_f0 = SMaxCrv(M2C_FIELD(arg1, s32 *, 0x24));
    var_v1 = M2C_FIELD(arg1, void **, 0x10);
    var_a0 = 0;
    var_f0 = (temp_f0 * 0.5f) / (f32) M2C_FIELD(arg1, s32 *, 0xC);
    temp_f7 = M2C_ERROR(/* unknown instruction: min.s $f7, $f0, $f1 */);
    if (var_v1 != NULL) {
        do {
            temp_f2 = M2C_FIELD(var_v1, f32 *, 0x34);
            var_f5 = (M2C_FIELD(arg1, f32 *, 0x28) - temp_f2) / (M2C_FIELD(var_v1, f32 *, 0x38) - temp_f2);
            if (var_f5 < 0.0f) {
                var_f5 = 0.0f;
            } else if (var_f5 > 1.0f) {
                var_f5 = 1.0f;
            }
            var_f3 = ((1.0f - var_f5) * M2C_FIELD(var_v1, f32 *, 0x2C)) + (var_f5 * M2C_FIELD(var_v1, f32 *, 0x30));
            temp_f1 = ((2.0f * (f32) var_a0) + 1.0f) * temp_f7;
            temp_f0_2 = temp_f0 - (((2.0f * (f32) ((M2C_FIELD(arg1, s32 *, 0xC) - var_a0) - 1)) + 1.0f) * temp_f7);
            if (var_f3 < temp_f1) {
                var_f3 = temp_f1;
            } else if (temp_f0_2 < var_f3) {
                var_f3 = temp_f0_2;
            }
            M2C_FIELD(var_v1, f32 *, 0x44) = var_f3;
            var_f0 = M2C_FIELD(var_v1, f32 *, 0x2C) + M2C_FIELD(var_v1, f32 *, 0x30);
            M2C_FIELD(var_v1, f32 *, 0x48) = (f32) -fabsf((var_f0 * 0.5f) - M2C_FIELD(arg1, f32 *, 0x28));
            var_v1 = M2C_FIELD(var_v1, void **, 0x60);
            var_a0 += 1;
        } while (var_v1 != NULL);
    }
    return var_f0;
}
