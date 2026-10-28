#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, s32 *);             /* extern */
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
M2C_UNK RefEval(s32 *, void *, s32);                /* extern */
M2C_UNK SetTag__4CRef4TAGK(s32 *, M2C_UNK);         /* extern */
M2C_UNK __as__4CRefRC4CRef(s32 *, s32 *);           /* extern */
M2C_UNK bevy_splice_bif_ref_op_eqv(s32 *, M2C_UNK, s32 *, s32); /* extern */

s32 RefEvalCase__FP5CPairP6CFrame(s32 arg0, void *arg1, s32 arg2) {
    char sp[0x400];
    M2C_UNK sp24;
    s32 sp10;
    s32 sp18;
    s32 sp20;
    s32 sp30;
    s32 sp40;
    s32 *sp44;
    s32 *temp_fp;
    s32 *var_s0_2;
    s32 *var_v1;
    s32 var_a0;
    s32 var_s4;
    void *temp_s0;
    void *temp_s1;
    void *var_a1;
    void *var_s0;
    void *var_s1;
    void *var_s3;

    var_v1 = &sp10;
    sp40 = arg0;
    temp_fp = var_v1;
    sp44 = &sp20;
    var_a0 = 1;
    do {
        *var_v1 = -1;
        var_a0 -= 1;
        var_v1 += 8;
    } while (var_a0 != -1);
    sp20 = -1;
    CRef_Destruct(sp);
    SetTag__4CRef4TAGK(sp, 0x24);
    temp_s0 = M2C_FIELD(M2C_FIELD(arg1, void **, 0xC), void **, 0x10);
    RefEval(&sp30, temp_s0, arg2);
    __as__4CRefRC4CRef(temp_fp, &sp30);
    CRef_Destruct(&sp30);
    var_s3 = M2C_FIELD(temp_s0, void **, 0x10);
    if (var_s3 != NULL) {
        do {
            temp_s1 = M2C_FIELD(var_s3, void **, 0xC);
            var_s4 = 1;
            if (M2C_FIELD(temp_s1, s32 *, 8) != 0xB) {
                var_s0 = M2C_FIELD(temp_s1, void **, 0xC);
                var_s4 = 0;
                if (var_s0 != NULL) {
                    do {
                        __as__4CRefRC4CRef(&sp18, var_s0 + 8);
                        bevy_splice_bif_ref_op_eqv(&sp30, 2, temp_fp, arg2);
                        __as__4CRefRC4CRef(sp44, &sp30);
                        CRef_Destruct(&sp30);
                        if (sp20 != 0x17) {
                            var_s0 = M2C_FIELD(var_s0, void **, 0x10);
                        } else if (sp24 == 0) {
                            var_s0 = M2C_FIELD(var_s0, void **, 0x10);
                        } else {
                            var_s4 = 1;
                            var_s0 = NULL;
                        }
                    } while (var_s0 != NULL);
                }
            }
            if (var_s4 == 0) {
                var_s3 = M2C_FIELD(var_s3, void **, 0x10);
            } else {
                var_s1 = M2C_FIELD(temp_s1, void **, 0x10);
                if (var_s1 != NULL) {
                    var_a1 = var_s1;
                    do {
                        RefEval(&sp30, var_a1, arg2);
                        __as__4CRefRC4CRef(sp, &sp30);
                        CRef_Destruct(&sp30);
                        var_s1 = M2C_FIELD(var_s1, void **, 0x10);
                        var_a1 = var_s1;
                    } while (var_s1 != NULL);
                }
                var_s3 = NULL;
            }
        } while (var_s3 != NULL);
    }
    CRef_CopyConstruct(sp40, sp);
    CRef_Destruct(&sp20);
    var_s0_2 = sp44 - 8;
    if (temp_fp != sp44) {
        do {
            CRef_Destruct(var_s0_2);
            var_s0_2 -= 8;
        } while (temp_fp != var_s0_2);
    }
    CRef_Destruct(sp);
    return sp40;
}
