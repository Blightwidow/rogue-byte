#include "m2c_macros.h"

M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */
extern M2C_UNK D_002BBB10;
extern M2C_UNK D_002BBB20;

s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(void *arg0, u32 arg1, s128 arg2, s32 *arg3, f32 fparg0) {
    char sp[0x400];
    M2C_UNK sp10;
    s128 sp20;
    f32 temp_v0;
    s32 var_a2;
    s32 var_s0;
    s32 var_v0;
    u32 temp_v1;
    u32 var_a0;
    u32 var_s2;
    u32 var_v1;
    void **temp_s4;
    void *temp_a1;
    void *var_s1;

    var_s1 = arg0;
    temp_s4 = M2C_ERROR(/* Read from unset register $t0 */);
    sp20 = arg2;
    if (var_s1 != NULL) {
loop_2:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
        func_002564B8(sp);
        func_002564B8(&sp10);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vmsubw.x $vf1, $vf2, $vf1w */);
        temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        if (fparg0 < temp_v0) {
            var_v1 = M2C_FIELD(var_s1, u32 *, 4);
            goto block_5;
        }
        var_v1 = M2C_FIELD(var_s1, u32 *, 0);
        if (temp_v0 < -fparg0) {
block_5:
            var_s1 = (void *) ((var_v1 < arg1) ? var_v1 : 0U);
            if (var_s1 == NULL) {
                goto block_40;
            }
            goto loop_2;
        }
        var_s2 = (var_v1 < arg1) ? var_v1 : 0U;
        if (var_s2 != 0) {
            var_s0 = PruneBsp__FP3BSPP6VECTORfPP3BSP(var_s2, arg1, sp20, arg3, fparg0);
            var_s2 = *temp_s4 - 0xC;
        } else {
            var_s0 = 0;
        }
        temp_v1 = M2C_FIELD(var_s1, u32 *, 4);
        var_a0 = (temp_v1 < arg1) ? temp_v1 : 0U;
        if (var_a0 != 0) {
            var_a2 = PruneBsp__FP3BSPP6VECTORfPP3BSP(var_a0, arg1, sp20, arg3, fparg0);
            var_a0 = *temp_s4 - 0xC;
        } else {
            var_a2 = 1;
        }
        if ((var_s0 != var_a2) || (var_v0 = var_a2, (var_a2 == 2))) {
            if (*arg3 > 0) {
                temp_a1 = *temp_s4;
                *temp_s4 = temp_a1 + 0xC;
                *arg3 -= 1;
                M2C_FIELD(temp_a1, s32 *, 8) = (s32) M2C_FIELD(var_s1, s32 *, 8);
                switch (var_s0) {                   /* irregular */
                case 0:
                    M2C_FIELD(temp_a1, u32 *, 0) = 0U;
                    break;
                case 2:
                    M2C_FIELD(temp_a1, u32 *, 0) = var_s2;
                    break;
                case 1:
                    M2C_FIELD(temp_a1, u32 *, 0) = (u32) &D_002BBB10;
                    break;
                }
                if (var_a2 != 1) {
                    if (var_a2 < 2) {
                        if (var_a2 != 0) {
                            return 2;
                        }
                        M2C_FIELD(temp_a1, M2C_UNK **, 4) = &D_002BBB20;
                        goto block_38;
                    }
                    if (var_a2 != 2) {
                        return 2;
                    }
                    M2C_FIELD(temp_a1, M2C_UNK **, 4) = (M2C_UNK *) var_a0;
                    goto block_38;
                }
                M2C_FIELD(temp_a1, M2C_UNK **, 4) = NULL;
block_38:
                return 2;
            }
            return 1;
        }
        /* Duplicate return node #42. Try simplifying control flow for better match */
        return var_v0;
    }
block_40:
    var_v0 = 1;
    if (!(M2C_ERROR(/* Read from unset register $f1 */) > 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
