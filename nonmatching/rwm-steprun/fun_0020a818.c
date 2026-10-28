#include "m2c_macros.h"

M2C_UNK DecomposeCylind(); /* extern */
s32 FInsideCmFrustrum(); /* extern */
f32 GetAlertPan();                            /* extern */
s128 PosLoWorld();              /* extern */
f32 RadNormalize__Ff();                          /* extern */
extern M2C_UNK B_002DDF40;

s32 func_0020A818(void *arg0, void *arg1, void **arg2, s32 arg3) {
    f32 sp10;
    f32 sp14;
    s128 sp20;
    s128 sp30;
    s32 temp_t0;
    s32 temp_v1;
    s32 var_a3;
    s32 var_v0;
    void **var_a2;

    var_a2 = arg2;
    var_a3 = arg3;
    if (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        if (M2C_FIELD(arg1, s32 *, 0xF30) == 0) {
            temp_t0 = M2C_FIELD(arg0, s32 *, 0x28);
            var_a3 = 0;
            if (temp_t0 > 0) {
                var_a2 = arg0 + 0x2C;
loop_4:
                var_a3 += 1;
                if (M2C_FIELD(*var_a2, s32 *, 0xF3C) == 0) {
                    var_a2 += 4;
                    if (var_a3 >= temp_t0) {
                        goto block_6;
                    }
                    goto loop_4;
                }
                goto block_15;
            }
        }
block_6:
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x10);
        if (temp_v1 == 0) {
            var_v0 = 1;
            if (M2C_FIELD(arg1, s32 *, 0xF34) == 0) {
                sp20 = PosLoWorld(arg1, var_a2, var_a3);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($a0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
                var_v0 = 0;
                if (FInsideCmFrustrum(&B_002DDF40, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), 0) != 0) {
                    PosLoWorld(M2C_FIELD(arg0, void **, 0xC));
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                    DecomposeCylind(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), &sp10, 0, 0);
                    var_v0 = 1;
                    if (M2C_FIELD(arg0, f32 *, 0x18) < fabsf(RadNormalize__Ff(sp10 - GetAlertPan(arg0)))) {
                        goto block_15;
                    }
                }
            }
            /* Duplicate return node #18. Try simplifying control flow for better match */
            return var_v0;
        }
        if (temp_v1 > 0) {
            if (temp_v1 != 1) {
                return 1;
            }
            sp30 = PosLoWorld(arg1, var_a2, var_a3);
            PosLoWorld(M2C_FIELD(arg0, void **, 0xC));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            DecomposeCylind(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), &sp14, 0, 0);
            var_v0 = 0;
            if (!(M2C_FIELD(arg0, f32 *, 0x18) < fabsf(RadNormalize__Ff(sp14 - GetAlertPan(arg0))))) {
                goto block_17;
            }
            /* Duplicate return node #18. Try simplifying control flow for better match */
            return var_v0;
        }
block_17:
        var_v0 = 1;
        return var_v0;
    }
block_15:
    return 0;
}
