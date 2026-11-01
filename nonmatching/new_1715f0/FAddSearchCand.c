#include "m2c_macros.h"

M2C_UNK DecomposeSphere(M2C_UNK, void *, f32 *, f32 *); /* extern */
s32 FCheckLm__FP2LMf(M2C_UNK *, f32);               /* extern */
f32 RadNormalize__Ff(u32, f32);                     /* extern */
extern M2C_UNK RO_002A53C0;
extern M2C_UNK RO_002A53C8;

s32 FAddSearchCand(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    f32 sp4;
    f32 sp8;
    f32 temp_f0;
    s32 var_v0;
    u32 temp_a0;
    u32 temp_a0_2;
    void *temp_s1;

    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x820($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
    DecomposeSphere(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf3 */), sp, &sp4, &sp8);
    if (FCheckLm__FP2LMf(&RO_002A53C0, sp8) != 0) {
        var_v0 = 0;
        if (FCheckLm__FP2LMf(&RO_002A53C8, sp4) != 0) {
            temp_a0 = M2C_FIELD(arg0, u32 *, 0x14);
            if (temp_a0 >= 0x40U) {
                goto block_3;
            }
            temp_a0_2 = temp_a0 + 1;
            temp_s1 = arg0 + ((temp_a0 << 5) + 0x20);
            M2C_FIELD(arg0, u32 *, 0x14) = temp_a0_2;
            M2C_FIELD(temp_s1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0x820);
            temp_f0 = RadNormalize__Ff(temp_a0_2, sp0 - M2C_FIELD(arg0, f32 *, 0x10));
            M2C_FIELD(temp_s1, f32 *, 0x10) = temp_f0;
            if (temp_f0 < 0.0f) {
                M2C_FIELD(temp_s1, f32 *, 0x10) = (f32) (6.2831855f - temp_f0);
            }
            var_v0 = 1;
            /* Duplicate return node #7. Try simplifying control flow for better match */
            return var_v0;
        }
        return var_v0;
    }
block_3:
    return 0;
}
