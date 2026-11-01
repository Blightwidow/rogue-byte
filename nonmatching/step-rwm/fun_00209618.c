#include "m2c_macros.h"

M2C_UNK UpdateJumper(void *);                       /* extern */
s128 func_00204E38(void *, void *, f32);            /* extern */
M2C_UNK func_00204ED8(void *, void *, f32);         /* extern */
extern s128 g_2a2dd0;

s32 func_00209618(void *arg0, void *arg1) {
    s128 sp10;
    s128 var_s2;
    s128 var_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    void *temp_a0;
    void *temp_a1;
    void *var_s0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0);
    sp10 = g_2a2dd0;
    var_s2 = sp10;
    switch (temp_v1) {                              /* irregular */
    case 3:
        var_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0x10);
block_19:
        sp10 = var_v0;
        break;
    case 0:
        var_s0 = M2C_FIELD(arg0, void **, 8);
block_12:
        if (var_s0 != NULL) {
            sp10 = func_00204E38(arg1, var_s0, M2C_FIELD(var_s0, f32 *, 0x1C));
            func_00204ED8(arg1, var_s0, M2C_FIELD(var_s0, f32 *, 0x1C));
            var_s2 = M2C_ERROR(/* unknown instruction: por $s2, $zero, $v0 */);
        }
        break;
    case 1:
        var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0x30);
        goto block_12;
    case 2:
        UpdateJumper(M2C_FIELD(arg0, void **, 8));
        temp_a0 = M2C_FIELD(arg0, void **, 8);
        temp_v1_2 = (s32) M2C_FIELD(temp_a0, s128 *, 0x10);
        if ((temp_v1_2 <= 0) || ((temp_v1_2 >= 3) && (temp_v1_2 != 4))) {
            temp_a1 = M2C_FIELD(temp_a0, void **, 0x38);
            var_v0 = func_00204E38(arg1, temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C));
            goto block_19;
        }
        break;
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
    if (M2C_FIELD(arg1, void **, 0xFC4) != NULL) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    }
    M2C_FIELD(arg1, s128 *, 0x1E0) = var_s2;
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
}
