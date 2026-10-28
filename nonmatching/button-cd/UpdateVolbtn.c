#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK CopyAb__FPvT0Ui(s32 *, s32 *, s32);         /* extern */
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
s32 FIsLoInWorld(s32);                              /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK SetVolbtnButtons(void *, M2C_UNK);          /* extern */
M2C_UNK UpdateLo();                                 /* extern */
s32 func_00227C90(void *, M2C_UNK);                 /* extern */
M2C_UNK qsort(s32 *, s32, M2C_UNK, M2C_UNK *);      /* extern */
extern M2C_UNK B_003DD490;
extern s32 B_003E134C;
extern M2C_UNK func_00149420;
extern f32 g_2dded0;

void UpdateVolbtn(void *arg0) {
    char sp[0x400];
    s32 sp100;
    M2C_UNK sp200;
    M2C_UNK var_s7;
    f32 temp_f2;
    s32 *temp_s0;
    s32 *temp_v0_2;
    s32 *var_s0;
    s32 *var_s3_2;
    s32 *var_s4;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s5;
    s32 var_s6;
    void *temp_v0_3;

    UpdateLo();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C0);
    if (temp_v1 == 2) {
        temp_f2 = M2C_FIELD(arg0, f32 *, 0x1C8);
        if ((temp_f2 >= 0.0f) && (temp_f2 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x1C4)))) {
            SetVolbtnButtons(arg0, 1);
        }
    } else if ((temp_v1 < 3) && (temp_v1 >= 0)) {
        var_s3 = 0;
        var_s7 = 0;
        CStackFrame_Construct(&sp200);
        CopyAb__FPvT0Ui(sp, arg0 + 0x28C, M2C_FIELD(arg0, s32 *, 0x288) * 4);
        var_s2 = M2C_FIELD(arg0, s32 *, 0x288);
        if (M2C_FIELD(arg0, s32 *, 0x2AC) > 0) {
            var_s0 = arg0 + 0x2B0;
            do {
                var_s3 += 1;
                temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 0x505, *var_s0, 0);
                var_s0 += 4;
                var_s2 += temp_v0;
            } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x2AC));
        }
        if ((M2C_FIELD(arg0, s32 *, 0x288) == 0) && (M2C_FIELD(arg0, s32 *, 0x2AC) == 0)) {
            temp_s0 = &B_003E134C - 0x3EBC;
            CopyAb__FPvT0Ui(&sp[var_s2], &B_003E134C, M2C_FIELD(temp_s0, s32 *, 0x3EB8) * 4);
            var_s2 += M2C_FIELD(temp_s0, s32 *, 0x3EB8);
        }
        M2C_FIELD(arg0, s32 *, 0x1D8) = 0;
        var_s6 = 0;
        var_s5 = 0;
        if (var_s2 > 0) {
            var_s4 = sp;
            var_s3_2 = &sp100;
loop_14:
            temp_s0_2 = *var_s4;
            if ((temp_s0_2 != 0) && (FIsLoInWorld(temp_s0_2) != 0) && (PosLoWorld(temp_s0_2), (func_00227C90(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */)) != 0))) {
                var_s7 = 1;
                if (M2C_FIELD(arg0, s32 *, 0x1D8) == 0) {
                    M2C_FIELD(arg0, s32 *, 0x1D8) = temp_s0_2;
                }
                var_s5 += 1;
                if (M2C_FIELD(arg0, s32 *, 0x2C8) != 0) {
                    *var_s3_2 = temp_s0_2;
                    var_s3_2 += 4;
                    goto block_21;
                }
            } else {
block_21:
                var_s6 += 1;
                var_s4 += 4;
                if (var_s6 >= var_s2) {
                    goto block_22;
                }
                goto loop_14;
            }
        } else {
block_22:
            if (M2C_FIELD(arg0, s32 *, 0x2C8) != 0) {
                var_s0_2 = 0;
                qsort(sp, var_s2, 4, &func_00149420);
                if (M2C_FIELD(arg0, s32 *, 0x2C0) == var_s5) {
                    if (var_s5 > 0) {
                        temp_v0_2 = M2C_FIELD(arg0, s32 **, 0x2C4);
                        if (sp100 == *temp_v0_2) {
                            var_a2 = 1;
loop_27:
                            if (var_a2 < var_s5) {
                                var_a2 += 1;
                                if (M2C_FIELD(&sp[var_a2], s32 *, 0x100) != *((var_a2 * 4) + temp_v0_2)) {
                                    goto block_29;
                                }
                                goto loop_27;
                            }
                        } else {
                            goto block_29;
                        }
                    }
                } else {
block_29:
                    var_s0_2 = 1;
                }
                if (var_s0_2 != 0) {
                    M2C_FIELD(arg0, s32 *, 0x2C0) = var_s5;
                    CopyAb__FPvT0Ui(M2C_FIELD(arg0, s32 **, 0x2C4), &sp100, var_s5 * 4);
                    temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x18), 9, 0, 0);
                }
            }
        }
        SetVolbtnButtons(arg0, var_s7);
        CStackFrame_Destructor(&sp200, 2);
    }
}
