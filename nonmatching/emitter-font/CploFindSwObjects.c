#include "m2c_macros.h"

M2C_UNK MatchSwObject(s32, void *, s32, s32, s32 *, s32 *); /* extern */
void **PdlFromSwOid(s32, s32);                      /* extern */
void **func_0015E3C0(s32, s32);                     /* extern */

s32 CploFindSwObjects(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 sp14;
    s32 sp18;
    void *sp1C;
    s32 sp20;
    s32 *temp_s2;
    s32 *var_v1;
    s32 temp_fp;
    s32 temp_v1;
    s32 var_a0;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_4;
    s8 var_v0_2;
    void *temp_v1_2;
    void *var_s0;
    void *var_s0_2;
    void *var_s0_3;
    void *var_s0_4;

    temp_s2 = M2C_ERROR(/* Read from unset register $t2 */);
    temp_fp = M2C_ERROR(/* Read from unset register $t1 */);
    if ((arg2 == -1) || ((temp_v1 = arg1 & 0xFF, (arg3 == NULL)) && (temp_v1 != 5))) {
        return 0;
    }
    if (M2C_ERROR(/* Read from unset register $t0 */) == 0) {
        if (arg3 != NULL) {

        }
    }
    sp14 = 0;
    if (temp_v1 != 1) {
        if ((temp_v1 != 0) && (temp_v1 < 5)) {
            var_v0 = arg1 & 0x200;
            if (temp_v1 >= 3) {
                goto block_13;
            }
            goto block_18;
        }
        var_v0 = arg1 & 0x200;
block_18:
        sp1C = NULL;
        sp20 = var_v0;
    } else {
block_13:
        var_s0 = arg3;
        sp1C = var_s0;
        sp20 = arg1 & 0x200;
        if (var_s0 != NULL) {
            var_v0_2 = 1;
            do {
                M2C_FIELD(var_s0, s8 *, 0x2C) = var_v0_2;
                var_s0 = M2C_FIELD(var_s0, void **, 0x10);
                var_v0_2 += 1;
            } while (var_s0 != NULL);
        }
        sp18 = 0x7FFFFFFF;
    }
    PdlFromSwOid(arg0, arg2);
    var_s0_2 = *PdlFromSwOid(arg0, arg2);
    if (var_s0_2 != NULL) {
        do {
            if (M2C_FIELD(var_s0_2, s32 *, 0x18) == arg2) {
                MatchSwObject(arg0, var_s0_2, M2C_FIELD(var_s0_2, s32 *, 0x3C), arg1, temp_s2, &sp18);
            }
            var_s0_2 = M2C_FIELD(var_s0_2, void **, 0x1C);
        } while (var_s0_2 != NULL);
    }
    func_0015E3C0(arg0, arg2);
    var_s0_3 = *func_0015E3C0(arg0, arg2);
    if (var_s0_3 != NULL) {
        var_v0_3 = M2C_FIELD(var_s0_3, s32 *, 8);
loop_27:
        if (var_v0_3 == arg2) {
            temp_v1_2 = M2C_FIELD(var_s0_3, void **, 0x10);
            if (temp_v1_2 != NULL) {
                if ((M2C_FIELD(temp_v1_2, s32 *, 0x18) == arg2) && (sp14 > 0)) {
                    var_v0_4 = sp14 > 0;
                    if (*temp_s2 != temp_v1_2) {
                        var_v1 = temp_s2;
                        var_a0 = 1;
loop_33:
                        var_v1 += 4;
                        if (var_a0 < sp14) {
                            if (*var_v1 != temp_v1_2) {
                                var_a0 += 1;
                                goto loop_33;
                            }
                            var_v0_4 = var_a0 < sp14;
                            goto block_38;
                        }
                        goto block_39;
                    }
block_38:
                    if (var_v0_4 == 0) {
                        goto block_39;
                    }
                } else {
block_39:
                    MatchSwObject(arg0, M2C_FIELD(var_s0_3, void **, 0x10), M2C_FIELD(var_s0_3, s32 *, 4), arg1, temp_s2, &sp18);
                }
            }
        }
        var_s0_3 = M2C_FIELD(var_s0_3, void **, 0xC);
        if (var_s0_3 != NULL) {
            var_v0_3 = M2C_FIELD(var_s0_3, s32 *, 8);
            goto loop_27;
        }
    }
    var_s0_4 = sp1C;
    if (var_s0_4 != NULL) {
        M2C_FIELD(var_s0_4, s8 *, 0x2C) = 0;
loop_45:
        var_s0_4 = M2C_FIELD(var_s0_4, void **, 0x10);
        if (var_s0_4 != NULL) {
            M2C_FIELD(var_s0_4, s8 *, 0x2C) = 0;
            goto loop_45;
        }
    }
    if (sp20 == 0) {
        if (temp_fp < sp14) {
            sp14 = temp_fp;
        }
    }
    return sp14;
}
