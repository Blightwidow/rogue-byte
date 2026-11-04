#include "m2c_macros.h"

s128 PosLoWorld(void *);                            /* extern */
M2C_UNK SetGoalTarget(s32, M2C_UNK *);              /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
f32 atan2f(void *, M2C_UNK, M2C_UNK);               /* extern */
s32 func_001C0B50(s32, M2C_UNK, void *);            /* extern */
M2C_UNK func_001C1EC0(s32, s128);                   /* extern */
M2C_UNK func_002562A8(M2C_UNK *);                   /* extern */
extern f32 D_FLT_002BE770;
extern f32 g_2be76c;
extern f32 g_2dded0;

void func_0017E0E0(void *arg0) {
    char sp[0x400];
    M2C_UNK sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    f32 *var_s1;
    f32 temp_f21;
    f32 temp_v0_2;
    f32 var_f20;
    s128 var_s0;
    s32 temp_s6;
    s32 var_s3;
    u32 var_s2;
    void *temp_v0;
    void *var_a0;

    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) g_2dded0;
    temp_s6 = M2C_FIELD(arg0, s32 *, 0x18);
    sp30 = PosLoWorld(M2C_FIELD(arg0, void **, 0x38));
    sp40 = PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
    var_a0 = NULL;
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xE8);
    if (temp_v0 != NULL) {
        var_a0 = M2C_FIELD(temp_v0, void **, 0xDC);
    }
    var_s3 = 0;
    if (var_a0 != NULL) {
        var_s3 = M2C_FIELD(var_a0, s32 *, 0x10);
    }
    var_s2 = 0;
    var_f20 = 0.0f;
    temp_f21 = atan2f(var_a0, M2C_ERROR(/* unknown instruction: prot3w $v0, $v1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */));
    func_001C1EC0(temp_s6 + 0x40, sp40);
    var_s0 = M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
    var_s1 = &D_FLT_002BE770;
    do {
        SetVectorCylind__FP6VECTORfff(temp_f21 + *var_s1, g_2be76c, 0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
        if (func_001C0B50(var_s3, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), sp) != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            if (var_f20 < temp_v0_2) {
                var_f20 = temp_v0_2;
                var_s0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $s0, $vf2 */);
            }
        }
        var_s2 += 1;
        var_s1 += 4;
    } while (var_s2 < 0x10U);
    func_002562A8(&sp10);
    sp20 = var_s0;
    SetGoalTarget(temp_s6, &sp10);
}
