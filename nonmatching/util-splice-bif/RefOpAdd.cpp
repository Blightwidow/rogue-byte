#include "m2c_macros.h"
extern "C" {

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CRef_SetF32(void *, s32, f32);              /* extern */
M2C_UNK CRef_SetMatrixPtr(void *, s32);             /* extern */
M2C_UNK CRef_SetS32(void *, M2C_UNK, f32);          /* extern */
M2C_UNK CRef_SetVectorPtr(void *, s32);             /* extern */

s32 RefOpAdd(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x10];
    M2C_UNK sp4;
    s32 temp_a1;
    s32 var_f0;
    s32 var_f12;
    s32 var_v1;
    void *temp_v1;
    void *var_s0;

    temp_a1 = M2C_FIELD(arg2, s32 *, 0);
    var_s0 = NULL;
    if (M2C_FIELD(arg2, s32 *, 8) != 0) {
        var_s0 = M2C_FIELD(arg2, void **, 0xC);
    }
    switch (temp_a1) {                              /* irregular */
    case 22:
        var_f12 = M2C_FIELD(arg2, s32 *, 4);
        var_v1 = 0;
block_13:
        if (var_s0 != NULL) {
            do {
                if (M2C_FIELD(var_s0, s32 *, 8) != 0x15) {
                    var_f0 = M2C_FIELD(var_s0, s32 *, 0xC);
                    var_v1 = 0;
                } else {
                    var_f0 = M2C_BITWISE(s32, (f32) M2C_FIELD(var_s0, s32 *, 0xC));
                }
                var_f12 = M2C_BITWISE(s32, (M2C_BITWISE(f32, var_f12) + M2C_BITWISE(f32, var_f0)));
                var_s0 = M2C_FIELD(var_s0, void **, 0x10);
            } while (var_s0 != NULL);
        }
        if (var_v1 != 0) {
            CRef_SetS32(sp, M2C_ERROR(/* Read from unset register $f0 */), M2C_BITWISE(f32, var_f12));
        } else {
            CRef_SetF32(sp, temp_a1, M2C_BITWISE(f32, var_f12));
        }
        break;
    case 21:
        var_f12 = M2C_BITWISE(s32, (f32) M2C_FIELD(arg2, s32 *, 4));
        var_v1 = 1;
        goto block_13;
    case 26:
        CRef_SetVectorPtr(sp, M2C_FIELD(arg2, s32 *, 4));
        if (var_s0 != NULL) {
loop_26:
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
            var_s0 = M2C_FIELD(var_s0, void **, 0x10);
            if (var_s0 != NULL) {
                goto loop_26;
            }
        }
        break;
    case 27:
        CRef_SetMatrixPtr(sp, M2C_FIELD(arg2, s32 *, 4));
        if (var_s0 != NULL) {
            do {
                temp_v1 = M2C_FIELD(var_s0, void **, 0xC);
                M2C_FIELD(sp4, f32 *, 0) = (f32) (M2C_FIELD(sp4, f32 *, 0) + M2C_FIELD(temp_v1, f32 *, 0));
                M2C_FIELD(sp4, f32 *, 4) = (f32) (M2C_FIELD(sp4, f32 *, 4) + M2C_FIELD(temp_v1, f32 *, 4));
                M2C_FIELD(sp4, f32 *, 8) = (f32) (M2C_FIELD(sp4, f32 *, 8) + M2C_FIELD(temp_v1, f32 *, 8));
                M2C_FIELD(sp4, f32 *, 0xC) = (f32) (M2C_FIELD(sp4, f32 *, 0xC) + M2C_FIELD(temp_v1, f32 *, 0xC));
                M2C_FIELD(sp4, f32 *, 0x10) = (f32) (M2C_FIELD(sp4, f32 *, 0x10) + M2C_FIELD(temp_v1, f32 *, 0x10));
                M2C_FIELD(sp4, f32 *, 0x14) = (f32) (M2C_FIELD(sp4, f32 *, 0x14) + M2C_FIELD(temp_v1, f32 *, 0x14));
                M2C_FIELD(sp4, f32 *, 0x18) = (f32) (M2C_FIELD(sp4, f32 *, 0x18) + M2C_FIELD(temp_v1, f32 *, 0x18));
                M2C_FIELD(sp4, f32 *, 0x1C) = (f32) (M2C_FIELD(sp4, f32 *, 0x1C) + M2C_FIELD(temp_v1, f32 *, 0x1C));
                M2C_FIELD(sp4, f32 *, 0x20) = (f32) (M2C_FIELD(sp4, f32 *, 0x20) + M2C_FIELD(temp_v1, f32 *, 0x20));
                M2C_FIELD(sp4, f32 *, 0x24) = (f32) (M2C_FIELD(sp4, f32 *, 0x24) + M2C_FIELD(temp_v1, f32 *, 0x24));
                M2C_FIELD(sp4, f32 *, 0x28) = (f32) (M2C_FIELD(sp4, f32 *, 0x28) + M2C_FIELD(temp_v1, f32 *, 0x28));
                M2C_FIELD(sp4, f32 *, 0x2C) = (f32) (M2C_FIELD(sp4, f32 *, 0x2C) + M2C_FIELD(temp_v1, f32 *, 0x2C));
                M2C_FIELD(sp4, f32 *, 0x30) = (f32) (M2C_FIELD(sp4, f32 *, 0x30) + M2C_FIELD(temp_v1, f32 *, 0x30));
                M2C_FIELD(sp4, f32 *, 0x34) = (f32) (M2C_FIELD(sp4, f32 *, 0x34) + M2C_FIELD(temp_v1, f32 *, 0x34));
                M2C_FIELD(sp4, f32 *, 0x38) = (f32) (M2C_FIELD(sp4, f32 *, 0x38) + M2C_FIELD(temp_v1, f32 *, 0x38));
                M2C_FIELD(sp4, f32 *, 0x3C) = (f32) (M2C_FIELD(sp4, f32 *, 0x3C) + M2C_FIELD(temp_v1, f32 *, 0x3C));
                var_s0 = M2C_FIELD(var_s0, void **, 0x10);
            } while (var_s0 != NULL);
        }
        break;
    }
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
