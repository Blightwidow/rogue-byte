#include "m2c_macros.h"

M2C_UNK ConvertXfVec(M2C_UNK, s32, s128);           /* extern */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
M2C_UNK WakeXf(void *, void *);                     /* extern */
M2C_UNK func_001F4BF8(void *);                      /* extern */
extern s128 g_2a2dd0;

void func_001FA328(void *arg0) {
    s32 var_s3;
    s32 var_s3_2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_s1_2;

    if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
        var_s3 = 0;
        if ((FFloatsNear__Ffff(g_2a2dd0, M2C_FIELD(arg0, s128 *, 0xF0), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), 0x38D1B717) != 0)) {
            var_s3 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), 0x38D1B717) != 0;
        }
        if (var_s3 == 0) {
            temp_s0 = M2C_FIELD(arg0, void **, 0x58);
            temp_s1 = arg0 + 0xF0;
            WakeXf(arg0, temp_s0);
            ConvertXfVec(0, M2C_FIELD(temp_s0, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0xF0));
            M2C_FIELD(temp_s1, s32 *, 4) = 0;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_FIELD(temp_s1, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0xF0) = 0;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s0) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($s0) */);
            func_001F4BF8(arg0);
        }
        var_s3_2 = 0;
        if ((FFloatsNear__Ffff(g_2a2dd0, M2C_FIELD(arg0, s128 *, 0x100), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), 0x38D1B717) != 0)) {
            var_s3_2 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), 0x38D1B717) != 0;
        }
        if (var_s3_2 == 0) {
            temp_s0_2 = M2C_FIELD(arg0, void **, 0x5C);
            temp_s1_2 = arg0 + 0x100;
            WakeXf(arg0, temp_s0_2);
            ConvertXfVec(0, M2C_FIELD(temp_s0_2, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0x100));
            M2C_FIELD(temp_s1_2, s32 *, 4) = 0;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_FIELD(temp_s1_2, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0x100) = 0;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s0) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($s0) */);
            func_001F4BF8(arg0);
        }
    }
}
