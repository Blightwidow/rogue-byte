#include "m2c_macros.h"

M2C_UNK ClearDl__FP2DL(void *);                     /* extern */
s32 FIsDlEmpty__FP2DL(void *);                      /* extern */
M2C_UNK FreeSlotheapPv(M2C_UNK *, void *);          /* extern */
M2C_UNK RemoveDlEntry(void *, void *);              /* extern */
extern M2C_UNK B_003E1518;
extern M2C_UNK B_003E1530;
extern void *g_2dd2fc;

void ClearPendingFrame__FP3FRM(void *arg0) {
    char sp[0x400];
    void **sp4;
    s32 sp8;
    void *spC;
    s32 temp_a0;
    s32 temp_a0_2;
    void *temp_a0_3;
    void *temp_a1;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_a0;
    void *var_s0;
    void *var_s0_2;

    temp_s0 = arg0 + 0x34;
    var_a0 = arg0 + 0x40;
    if (FIsDlEmpty__FP2DL(temp_s0) == 0) {
        temp_a0 = M2C_FIELD(temp_s0, s32 *, 8);
        temp_v1 = g_2dd2fc;
        g_2dd2fc = sp;
        spC = temp_v1;
        temp_v0 = M2C_FIELD(arg0, void **, 0x34);
        var_s0 = temp_v0;
        sp4 = temp_v0 + temp_a0;
        sp8 = temp_a0;
        if (var_s0 != NULL) {
            do {
                RemoveDlEntry(temp_s0, var_s0);
                temp_v0_2 = M2C_FIELD(var_s0, void **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x14)(var_s0 + M2C_FIELD(temp_v0_2, s16 *, 0x10));
                temp_v1_2 = *sp4;
                var_s0 = temp_v1_2;
                sp4 = temp_v1_2 + sp8;
            } while (var_s0 != NULL);
        }
        ClearDl__FP2DL(temp_s0);
        g_2dd2fc = spC;
        var_a0 = arg0 + 0x40;
    }
    if (FIsDlEmpty__FP2DL(var_a0) == 0) {
        temp_a0_2 = M2C_FIELD(var_a0, s32 *, 8);
        temp_v1_3 = g_2dd2fc;
        g_2dd2fc = sp;
        spC = temp_v1_3;
        temp_v0_3 = M2C_FIELD(arg0, void **, 0x40);
        var_s0_2 = temp_v0_3;
        sp4 = temp_v0_3 + temp_a0_2;
        sp8 = temp_a0_2;
        if (var_s0_2 != NULL) {
            do {
                temp_a1 = M2C_FIELD(var_s0_2, void **, 0x1088);
                if (temp_a1 != NULL) {
                    FreeSlotheapPv(&B_003E1530, temp_a1);
                }
                RemoveDlEntry(var_a0, var_s0_2);
                FreeSlotheapPv(&B_003E1518, var_s0_2);
                temp_a0_3 = *sp4;
                var_s0_2 = temp_a0_3;
                sp4 = temp_a0_3 + sp8;
            } while (var_s0_2 != NULL);
        }
        ClearDl__FP2DL(var_a0);
        g_2dd2fc = spC;
    }
}
