#include "m2c_macros.h"

s32 FFloatsNear__Ffff(); /* extern */
s32 IkeyFindAcrb();                              /* extern */
extern s128 g_2a2dd0;

void func_0012B738(void *arg0, void *arg1) {
    s16 var_v0;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v0;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;

    var_s4 = 0;
    var_s5 = 0;
    temp_v0 = IkeyFindAcrb(*M2C_FIELD(arg1, f32 **, 0x88)) * 0x30;
    M2C_FIELD(arg1, f32 *, 0x80) = (f32) M2C_FIELD((temp_v0 + M2C_FIELD(arg0, s32 *, 8)), f32 *, -0x24);
    M2C_ERROR(/* unknown instruction: ldl $a0, -0x29($v1) */);
    M2C_ERROR(/* unknown instruction: ldr $a0, -0x30($v1) */);
    M2C_ERROR(/* unknown instruction: sdl $a0, 0xc7($s3) */);
    M2C_ERROR(/* unknown instruction: sdr $a0, 0xc0($s3) */);
    M2C_FIELD(arg1, s32 *, 0xC8) = (s32) M2C_FIELD((temp_v0 + M2C_FIELD(arg0, s32 *, 8)), s32 *, -0x28);
    M2C_FIELD(arg1, s128 *, 0xD0) = (s128) M2C_FIELD((temp_v0 + M2C_FIELD(arg0, s32 *, 8)), s128 *, -0x10);
    M2C_FIELD(arg1, f32 *, 0x84) = (f32) M2C_FIELD((temp_v0 + M2C_FIELD(arg0, s32 *, 8)), f32 *, 0xC);
    M2C_ERROR(/* unknown instruction: ldl $a0, 0x7($v1) */);
    M2C_ERROR(/* unknown instruction: ldr $a0, ($v1) */);
    temp_a1 = M2C_FIELD((temp_v0 + M2C_FIELD(arg0, s32 *, 8)), s32 *, 8);
    M2C_ERROR(/* unknown instruction: sdl $a0, 0xe7($s3) */);
    M2C_ERROR(/* unknown instruction: sdr $a0, 0xe0($s3) */);
    M2C_FIELD(arg1, s32 *, 0xE8) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg1, s128 *, 0xF0) = (s128) M2C_FIELD((temp_v0 + temp_a0), s128 *, 0x10);
    if (FFloatsNear__Ffff(temp_a0, temp_a1, M2C_FIELD(arg1, s128 *, 0xC0), M2C_FIELD(arg1, s128 *, 0xE0), 0x38D1B717) != 0) {
        temp_a0_2 = M2C_ERROR(/* unknown instruction: prot3w $a0, $s2 */);
        if (FFloatsNear__Ffff(temp_a0_2, M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), (s128) temp_a0_2, 0x38D1B717) != 0) {
            var_s4 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $a1, $zero, $s1 */), M2C_ERROR(/* unknown instruction: pextuw $a2, $zero, $s2 */), 0x38D1B717) != 0;
        }
    }
    if (var_s4 != 0) {
        var_s2 = 0;
        if ((FFloatsNear__Ffff((s32) g_2a2dd0, (s32) M2C_FIELD(arg1, s128 *, 0xD0), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $a3, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), 0x38D1B717) != 0)) {
            temp_a0_3 = M2C_ERROR(/* unknown instruction: pextuw $a0, $zero, $s0 */);
            temp_a1_2 = M2C_ERROR(/* unknown instruction: pextuw $a1, $zero, $s1 */);
            var_s2 = FFloatsNear__Ffff(temp_a0_3, temp_a1_2, (s128) temp_a0_3, (s128) temp_a1_2, 0x38D1B717) != 0;
        }
        if (var_s2 != 0) {
            var_s5 = 0;
            if ((FFloatsNear__Ffff((s32) g_2a2dd0, (s32) M2C_FIELD(arg1, s128 *, 0xF0), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $a2, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $a3, $s1 */), 0x38D1B717) != 0)) {
                temp_a0_4 = M2C_ERROR(/* unknown instruction: pextuw $a0, $zero, $s1 */);
                var_s5 = FFloatsNear__Ffff(temp_a0_4, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), (s128) temp_a0_4, 0x38D1B717) != 0;
            }
        }
    }
    var_v0 = 1;
    if (var_s5 != 0) {
        var_v0 = 2;
    }
    M2C_FIELD(arg1, s16 *, 0x9A) = var_v0;
}
