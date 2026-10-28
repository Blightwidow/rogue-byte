#include "m2c_macros.h"

s32 FFloatsNear__Ffff(); /* extern */
s32 func_0012C0E0();                             /* extern */
extern s128 g_2a2dd0;

void bevy_anim_keys_axis_segment(void *arg0, void *arg1, s32 arg2) {
    M2C_UNK32 *var_a2_2;
    M2C_UNK32 *var_t0;
    f32 *var_a0;
    f32 *var_a1;
    f32 *var_a3;
    s16 var_v0;
    s32 *var_t1;
    s32 temp_t2;
    u8 *temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s5;
    u32 var_t3;
    void *temp_v0;
    void *temp_v1_3;

    var_a2 = arg2;
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        var_a2 = func_0012C0E0(*M2C_FIELD(arg1, f32 **, 0x88));
        temp_v1 = var_a2 * 4;
        M2C_FIELD(arg1, M2C_UNK32 *, 0x80) = (M2C_UNK32) M2C_FIELD((temp_v1 + M2C_FIELD(arg0, s32 *, 8)), M2C_UNK32 *, -4);
        M2C_FIELD(arg1, f32 *, 0x84) = (f32) *(temp_v1 + M2C_FIELD(arg0, s32 *, 8));
    } else {
        M2C_FIELD(arg1, f32 **, 0x88) = (f32 *) (arg1 + 0x80);
        M2C_FIELD(arg1, f32 *, 0x84) = 1.0f;
        M2C_FIELD(arg1, void **, 0x8C) = (void *) (arg1 + 0x84);
        M2C_FIELD(arg1, M2C_UNK32 *, 0x80) = 0;
    }
    var_t1 = arg0 + 0xC;
    temp_t2 = var_a2 * 0xC;
    var_t3 = 0;
    var_t0 = arg1 + 0xF0;
    var_a3 = arg1 + 0xE0;
    var_a2_2 = arg1 + 0xD0;
    var_a1 = arg1 + 0xC0;
    var_a0 = arg0 + 0x20;
    do {
        temp_v1_2 = *var_t1;
        temp_v0 = temp_v1_2 + (temp_t2 - 0xC);
        if (temp_v1_2 != 0) {
            temp_v1_3 = temp_v1_2 + temp_t2;
            *var_a1 = M2C_FIELD(temp_v0, f32 *, 0);
            *var_a2_2 = M2C_FIELD(temp_v0, M2C_UNK32 *, 8);
            *var_a3 = M2C_FIELD(temp_v1_3, f32 *, 0);
            *var_t0 = M2C_FIELD(temp_v1_3, M2C_UNK32 *, 4);
        } else {
            *var_a1 = *var_a0;
            *var_a2_2 = 0;
            *var_a3 = *var_a0;
            *var_t0 = 0;
        }
        var_t3 += 1;
        var_t0 += 4;
        var_a3 += 4;
        var_a2_2 += 4;
        var_a1 += 4;
        var_a0 += 4;
        var_t1 += 4;
    } while (var_t3 < 3U);
    var_s5 = 0;
    var_s3 = 0;
    if ((FFloatsNear__Ffff(var_a0, var_a1, var_a2_2, var_a3, M2C_FIELD(arg1, s128 *, 0xC0), M2C_FIELD(arg1, s128 *, 0xE0), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), (M2C_UNK32 *)0x38D1B717) != 0)) {
        var_s3 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), (M2C_UNK32 *)0x38D1B717) != 0;
    }
    if (var_s3 != 0) {
        var_s3_2 = 0;
        if ((FFloatsNear__Ffff((f32 *) g_2a2dd0, (f32 *) M2C_FIELD(arg1, s128 *, 0xD0), (M2C_UNK32 *)0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), (M2C_UNK32 *)0x38D1B717) != 0)) {
            var_s3_2 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), (M2C_UNK32 *)0x38D1B717) != 0;
        }
        if (var_s3_2 != 0) {
            var_s5 = 0;
            if ((FFloatsNear__Ffff((f32 *) g_2a2dd0, (f32 *) M2C_FIELD(arg1, s128 *, 0xF0), (M2C_UNK32 *)0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), (M2C_UNK32 *)0x38D1B717) != 0)) {
                var_s5 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), (M2C_UNK32 *)0x38D1B717) != 0;
            }
        }
    }
    var_v0 = 1;
    if (var_s5 != 0) {
        var_v0 = 2;
    }
    M2C_FIELD(arg1, s16 *, 0x9A) = var_v0;
}
