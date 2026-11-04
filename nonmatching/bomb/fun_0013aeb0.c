#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK PrepareBombDetonation(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PrimeBomb__FP4BOMBf(void *, M2C_UNK);       /* extern */
M2C_UNK QueueSwCallback(M2C_UNK *, void *, M2C_UNK, s32); /* extern */
s32 func_0013B1C8(void *, s32);                     /* extern */
s32 func_001C4098(s32);                             /* extern */
M2C_UNK func_001F4F10();                            /* extern */
extern M2C_UNK B_003DD490;

s32 func_0013AEB0(void *arg0) {
    f32 temp_v0;
    f32 var_f21;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 var_s4;
    s32 var_v0;
    void *temp_v1_2;
    void *var_s1;
    void *var_s5;
    void *var_s6;

    func_001F4F10();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    switch (temp_v1) {                              /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        var_v0 = M2C_FIELD(arg0, s32 *, 0x174);
block_10:
        if (var_v0 == 0) {
        default:                                    /* switch 1 */
            var_s6 = NULL;
            var_s5 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void **, 0x64);
            var_f21 = 3.4028235e38f;
            if (var_s5 != NULL) {
                do {
                    var_s1 = M2C_FIELD(var_s5, void **, 0);
                    if (var_s1 != NULL) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                        do {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s1) */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                            M2C_ERROR(/* unknown instruction: vwaitq */);
                            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                            temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                            if (!(var_f21 <= temp_v0)) {
                                temp_s0 = M2C_FIELD(arg0, s32 *, 0x150);
                                var_s4 = 0;
                                switch (temp_s0) {  /* switch 2; irregular */
                                case 0:             /* switch 2 */
                                    var_s4 = 1;
                                    break;
                                case 2:             /* switch 2 */
                                    temp_s0_2 = M2C_FIELD((var_s1 + ((1 - ((s32) arg0 != M2C_FIELD(var_s1, s32 *, 8))) << 6)), s32 *, 8);
                                    if (FIsBasicDerivedFrom(temp_s0_2, 0x32) != 0) {
                                        var_s4 = (func_001C4098(temp_s0_2) != 0) ? 1 : 0;
                                    }
                                    break;
                                case 1:             /* switch 2 */
                                    var_s4 = (func_0013B1C8(arg0, M2C_FIELD((var_s1 + ((temp_s0 - ((s32) arg0 != M2C_FIELD(var_s1, s32 *, 8))) << 6)), s32 *, 0xC)) != 0) ? temp_s0 : 0;
                                    break;
                                }
                                if (var_s4 != 0) {
                                    var_f21 = temp_v0;
                                    var_s6 = var_s1;
                                }
                            }
                            var_s1 = M2C_FIELD(var_s1, void **, 0xAC);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                        } while (var_s1 != NULL);
                    }
                    var_s5 = M2C_FIELD(var_s5, void **, 4);
                } while (var_s5 != NULL);
            }
            if (var_s6 != NULL) {
                temp_a3 = M2C_FIELD(arg0, s32 *, 0x150);
                switch (temp_a3) {                  /* switch 3; irregular */
                case 0:                             /* switch 3 */
                case 2:                             /* switch 3 */
                    temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                    M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x108));
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */);
                    } else {
                        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                    }
                    PrepareBombDetonation(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */));
                    PrimeBomb__FP4BOMBf(arg0, 0);
                    break;
                case 1:                             /* switch 3 */
                    M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A4B17)($v1) */);
                    QueueSwCallback(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A4B10)($v1) */), M2C_FIELD((var_s6 + ((temp_a3 - ((s32) arg0 != M2C_FIELD(var_s6, s32 *, 8))) << 6)), s32 *, 0xC));
                    break;
                }
            }
        } else {
            return;
        }
        break;
    case 2:                                         /* switch 1 */
        var_v0 = M2C_FIELD(arg0, s32 *, 0x174);
        goto block_10;
    case 1:                                         /* switch 1 */
        if (M2C_FIELD(arg0, s32 *, 0x1E4) != 0) {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x1E8);
            goto block_10;
        }
        break;
    }
}
