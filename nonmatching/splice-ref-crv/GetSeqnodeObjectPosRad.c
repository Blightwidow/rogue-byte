#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK FindCrvClosestPointAll(void *, M2C_UNK, M2C_UNK, void *); /* extern */
s128 PosLoWorld(void *);                            /* extern */
f32 atan2f(f32, f32);                               /* extern */

void GetSeqnodeObjectPosRad(void *arg0, void *arg1, s128 *arg2, f32 *arg3) {
    char sp[0x400];
    M2C_UNK sp14;
    s128 sp0;
    f32 sp10;
    f32 *temp_s0;
    f32 *temp_s0_2;
    f32 var_f0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *var_s1;

    var_s1 = M2C_FIELD(arg0, void **, 0x24);
    if (var_s1 == NULL) {
        var_s1 = M2C_FIELD(arg0, void **, 0x44);
    }
    if (arg1 != NULL) {
        if (FIsBasicDerivedFrom(arg1, 0xA) != 0) {
            PosLoWorld(var_s1);
            FindCrvClosestPointAll(arg1, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), 0, sp);
            var_f0 = atan2f(sp14, sp10);
        } else {
            sp0 = PosLoWorld(arg1);
            temp_v1 = M2C_FIELD(arg1, void **, 0xC);
            temp_v1_2 = M2C_FIELD(arg1, void **, 0xC);
            temp_s0 = M2C_FIELD(temp_v1, f32 *(**)(void *), 0xFC)(arg1 + M2C_FIELD(temp_v1, s16 *, 0xF8));
            var_f0 = atan2f(M2C_FIELD(temp_s0, f32 *, 4), *M2C_FIELD(temp_v1_2, f32 *(**)(void *), 0xFC)(arg1 + M2C_FIELD(temp_v1_2, s16 *, 0xF8)));
        }
    } else {
        sp0 = PosLoWorld(var_s1);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        if (FIsBasicDerivedFrom(var_s1, 0x33) != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x240($s1) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            var_f0 = M2C_FIELD(var_s1, f32 *, 0x1A8);
        } else {
            temp_v1_3 = M2C_FIELD(var_s1, void **, 0xC);
            temp_v1_4 = M2C_FIELD(var_s1, void **, 0xC);
            temp_s0_2 = M2C_FIELD(temp_v1_3, f32 *(**)(void *), 0xFC)(var_s1 + M2C_FIELD(temp_v1_3, s16 *, 0xF8));
            var_f0 = atan2f(M2C_FIELD(temp_s0_2, f32 *, 4), *M2C_FIELD(temp_v1_4, f32 *(**)(void *), 0xFC)(var_s1 + M2C_FIELD(temp_v1_4, s16 *, 0xF8)));
        }
    }
    if (arg2 != NULL) {
        *arg2 = sp0;
    }
    if (arg3 != NULL) {
        *arg3 = var_f0;
    }
}
