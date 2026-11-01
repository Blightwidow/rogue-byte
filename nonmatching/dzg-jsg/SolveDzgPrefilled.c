#include "m2c_macros.h"

M2C_UNK AppendDlEntry(void *, s32 *);               /* extern */
M2C_UNK EnforceDzgDz__FP3DZGP2DZ(void *, s32 *);    /* extern */
M2C_UNK RemoveDlEntry(void *, s32 *);               /* extern */
extern void *g_2dd2fc;

void SolveDzgPrefilled(void *arg0) {
    char sp[0x400];
    s32 **sp4;
    s32 sp8;
    void *spC;
    f32 temp_f0;
    f32 var_f1;
    s32 **temp_v0;
    s32 *temp_a0;
    s32 *temp_v0_2;
    s32 *var_a1;
    s32 *var_s0;
    s32 *var_v0;
    s32 temp_v1;
    void *temp_a1;

    temp_v0 = arg0 + 0x30;
    sp4 = temp_v0;
    temp_a1 = g_2dd2fc;
    temp_v1 = M2C_FIELD(temp_v0, s32 *, 8);
    g_2dd2fc = sp;
    spC = temp_a1;
    temp_v0_2 = M2C_FIELD(arg0, s32 **, 0x30);
    sp8 = temp_v1;
    var_s0 = temp_v0_2;
    sp4 = temp_v0_2 + temp_v1;
    if (var_s0 != NULL) {
        do {
            if (*var_s0 == 1) {
                RemoveDlEntry(arg0 + 0x30, var_s0);
                AppendDlEntry(arg0 + 0xC, var_s0);
                M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + 1);
            }
            temp_a0 = *sp4;
            var_s0 = temp_a0;
            sp4 = temp_a0 + sp8;
        } while (var_s0 != NULL);
    }
    EnforceDzgDz__FP3DZGP2DZ(arg0, NULL);
    g_2dd2fc = spC;
    var_v0 = M2C_FIELD(arg0, s32 **, 0x30);
loop_6:
    var_f1 = -0.01f;
    var_a1 = NULL;
    if (var_v0 != NULL) {
        do {
            temp_f0 = M2C_FIELD(var_v0, f32 *, 0x10);
            if (temp_f0 < var_f1) {
                var_f1 = temp_f0;
                var_a1 = var_v0;
            }
            var_v0 = M2C_FIELD(var_v0, s32 **, 0x20);
        } while (var_v0 != NULL);
    }
    if (var_a1 != NULL) {
        EnforceDzgDz__FP3DZGP2DZ(arg0, var_a1);
        var_v0 = M2C_FIELD(arg0, s32 **, 0x30);
        goto loop_6;
    }
}
