#include "m2c_macros.h"

M2C_UNK AppendDlEntry(void *, void *);              /* extern */
M2C_UNK EnforceDzgDz__FP3DZGP2DZ(void *, void *);   /* extern */
M2C_UNK FillDzgDz(void *, s32, void *, s32);        /* extern */
M2C_UNK RemoveDlEntry(void *, void *);              /* extern */
s32 func_00158958(void *, void *);                  /* extern */
extern void *g_2dd2fc;

void SolveDzg__FP3DZGiiPP2XPPiPPP2SO(void *arg0, s32 arg1) {
    char sp[0x400];
    void **sp4;
    s32 sp8;
    void *spC;
    f32 temp_f0;
    f32 var_f1;
    s32 temp_v0;
    void **temp_v1;
    void *temp_a0;
    void *temp_a1;
    void *temp_v1_2;
    void *var_s0;
    void *var_s0_2;
    void *var_v0;

    temp_v1 = arg0 + 0x30;
    sp4 = temp_v1;
    temp_a1 = g_2dd2fc;
    temp_v0 = M2C_FIELD(temp_v1, s32 *, 8);
    g_2dd2fc = sp;
    spC = temp_a1;
    temp_v1_2 = M2C_FIELD(arg0, void **, 0x30);
    sp8 = temp_v0;
    var_s0 = temp_v1_2;
    sp4 = temp_v1_2 + temp_v0;
    if (var_s0 != NULL) {
        do {
            if (M2C_FIELD(var_s0, s32 *, 0) == 1) {
                if (M2C_FIELD(var_s0, s32 *, 0x18) == 0) {
                    FillDzgDz(arg0, arg1, var_s0, func_00158958(arg0, var_s0));
                }
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
loop_8:
    var_v0 = M2C_FIELD(arg0, void **, 0x30);
    var_f1 = -0.01f;
    var_s0_2 = NULL;
    if (var_v0 != NULL) {
        do {
            temp_f0 = M2C_FIELD(var_v0, f32 *, 0x10);
            if (temp_f0 < var_f1) {
                var_f1 = temp_f0;
                var_s0_2 = var_v0;
            }
            var_v0 = M2C_FIELD(var_v0, void **, 0x20);
        } while (var_v0 != NULL);
    }
    if (var_s0_2 != NULL) {
        if (M2C_FIELD(var_s0_2, s32 *, 0x18) == 0) {
            FillDzgDz(arg0, arg1, var_s0_2, func_00158958(arg0, var_s0_2));
        }
        EnforceDzgDz__FP3DZGP2DZ(arg0, var_s0_2);
        goto loop_8;
    }
}
