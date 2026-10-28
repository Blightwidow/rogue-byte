#include "m2c_macros.h"

M2C_UNK AppendDlEntry(s32 **, void *);              /* extern */
M2C_UNK ClearDle__FP3DLE(void *, f32 *, s128, s128); /* extern */
s32 GrficFromAlo(void *, s32);                      /* extern */
void *PvAllocSlotheapImpl(M2C_UNK *);               /* extern */
void *func_001A5BF0(s32);                           /* extern */
extern M2C_UNK B_003E15A8;
extern s32 *B_003E15C0;
extern f32 g_2dded0;

void *PaloAbsorbWkr(void **arg0) {
    void *sp10;
    void *sp14;
    void **sp18;
    void **sp20;
    void **sp24;
    void *sp30;
    s128 temp_a2;
    s128 temp_a3;
    s32 *var_a0;
    s32 var_v0;
    void **var_v0_2;
    void *temp_a3_2;
    void *temp_t2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v1;
    void *temp_v1_2;
    void *var_v1;

    temp_v0 = func_001A5BF0(M2C_FIELD(arg0, s32 *, 8));
    sp30 = temp_v0;
    if (temp_v0 != NULL) {
loop_2:
        var_a0 = B_003E15C0;
        if (var_a0 != NULL) {
            var_v0 = *var_a0;
loop_4:
            if ((var_v0 != M2C_FIELD(arg0, void **, 0)) || (M2C_FIELD(var_a0, s32 *, 4) != M2C_FIELD(arg0, s32 *, 4)) || (M2C_FIELD(var_a0, s32 *, 0xC) != M2C_FIELD(arg0, s32 *, 0xC)) || (M2C_FIELD(var_a0, s32 *, 0x48) != sp30)) {
                var_a0 = M2C_FIELD(var_a0, s32 **, 0x50);
                if (var_a0 != NULL) {
                    var_v0 = *var_a0;
                    goto loop_4;
                }
                goto block_11;
            }
            /* Duplicate return node #19. Try simplifying control flow for better match */
            return NULL;
        }
block_11:
        M2C_FIELD(arg0, s32 *, 0x44) = GrficFromAlo(sp30, M2C_FIELD(arg0, s32 *, 0xC));
        temp_v1 = M2C_FIELD(sp30, void **, 0xC);
        if (M2C_FIELD(temp_v1, s32 (**)(void *, void **, void *), 0x25C)(sp30 + M2C_FIELD(temp_v1, s16 *, 0x258), arg0, sp30) != 0) {
            M2C_FIELD(arg0, void **, 0x48) = sp30;
            temp_v0_2 = PvAllocSlotheapImpl(&B_003E15A8);
            var_v1 = temp_v0_2;
            var_v0_2 = arg0;
            do {
                temp_a2 = M2C_FIELD(var_v0_2, s128 *, 0);
                temp_a3 = M2C_FIELD(var_v0_2, s128 *, 0x10);
                M2C_FIELD(var_v1, s128 *, 0) = temp_a2;
                M2C_FIELD(var_v1, s128 *, 0x10) = temp_a3;
                var_v0_2 += 0x20;
                var_v1 += 0x20;
            } while (var_v0_2 != (arg0 + 0x60));
            M2C_FIELD(temp_v0_2, f32 *, 0x4C) = (f32) g_2dded0;
            ClearDle__FP3DLE(temp_v0_2 + 0x50, &g_2dded0, temp_a2, temp_a3);
            AppendDlEntry(&B_003E15C0, temp_v0_2);
            if (M2C_FIELD(arg0, s32 *, 0x44) & 0xF8) {
                sp10 = sp30;
                sp14 = M2C_FIELD(arg0, void **, 0);
                sp18 = arg0;
                temp_v0_3 = M2C_FIELD(sp30, void **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, void **, void *), 0x24)(sp30 + M2C_FIELD(temp_v0_3, s16 *, 0x20), 0xB, &sp10, sp30);
                temp_a3_2 = M2C_FIELD(arg0, void **, 0);
                temp_v0_4 = M2C_FIELD(temp_a3_2, void **, 0xC);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK, void **, void *), 0x24)(temp_a3_2 + M2C_FIELD(temp_v0_4, s16 *, 0x20), 0xB, &sp10, temp_a3_2);
                sp20 = &sp30;
                sp24 = arg0 + 0xC;
                temp_t2 = M2C_FIELD(arg0, void **, 0);
                temp_v0_5 = M2C_FIELD(temp_t2, void **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_t2 + M2C_FIELD(temp_v0_5, s16 *, 0x18), 0xA, 1, 2);
                sp20 = arg0;
                temp_v0_6 = M2C_FIELD(sp30, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(sp30 + M2C_FIELD(temp_v0_6, s16 *, 0x18), 0xB, 1, 2);
            }
            return sp30;
        }
        temp_v1_2 = M2C_FIELD(sp30, void **, 0x10);
        sp30 = temp_v1_2;
        if (temp_v1_2 == NULL) {
            goto block_18;
        }
        goto loop_2;
    }
block_18:
    return NULL;
}
