#include "m2c_macros.h"

M2C_UNK SetAmbGrf(void *, M2C_UNK, M2C_UNK);        /* extern */

void UpdateAmb(void *arg0) {
    void *sp0;
    M2C_UNK (*temp_a1)(void *, M2C_UNK);
    M2C_UNK var_a1;
    u16 temp_v1;
    u16 temp_v1_2;
    void *temp_v0;
    void *temp_v0_10;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_3;

    sp0 = arg0;
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
    if (!(M2C_FIELD(arg0, u16 *, 0x50) & 0x200)) {
        M2C_FIELD(arg0, f32 *, 0x44) = (f32) M2C_FIELD(arg0, f32 *, 0x10);
    } else {
        temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x84)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x80));
    }
    temp_v1 = M2C_FIELD(arg0, u16 *, 0x50);
    if (!(temp_v1 & 1)) {
        if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
            if (temp_v1 & 8) {
                temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *), 0x54)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x50));
                M2C_FIELD(arg0, s32 *, 0x40) = 0;
                var_a1 = 0x1DFF;
                goto block_23;
            }
            if (temp_v1 & 0x1C00) {
                temp_v0_4 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *), 0x74)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x70));
            }
            if (M2C_FIELD(arg0, u16 *, 0x52) != 0) {
                temp_v0_5 = M2C_FIELD(sp0, void **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, void *), 0x14)(sp0 + M2C_FIELD(temp_v0_5, s16 *, 0x10), sp0);
                return;
            }
            if (M2C_FIELD(arg0, u16 *, 0x50) & 0x1F0) {
                temp_v0_6 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, void *), 0x6C)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 0x68), sp0);
                SetAmbGrf(arg0, 0x1F0, 0);
            }
            temp_v1_2 = M2C_FIELD(arg0, u16 *, 0x50);
            if (temp_v1_2 & 2) {
                temp_v0_7 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *), 0x5C)(arg0 + M2C_FIELD(temp_v0_7, s16 *, 0x58));
                var_a1 = 2;
                goto block_23;
            }
            if (temp_v1_2 & 4) {
                temp_v0_8 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, void *), 0x64)(arg0 + M2C_FIELD(temp_v0_8, s16 *, 0x60), sp0);
                var_a1 = 4;
block_23:
                SetAmbGrf(arg0, var_a1, 0);
            }
            goto block_28;
        }
        if ((M2C_FIELD(arg0, u16 *, 0x52) == 0) && !(temp_v1 & 0x200)) {
            SetAmbGrf(arg0, 0x1FFF, 0);
        }
        goto block_28;
    }
    temp_v0_9 = M2C_FIELD(arg0, void **, 0xC);
    temp_a1 = M2C_FIELD(temp_v0_9, M2C_UNK (**)(void *, M2C_UNK), 0x4C);
    temp_a1(arg0 + M2C_FIELD(temp_v0_9, s16 *, 0x48), temp_a1);
    temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
    if (M2C_FIELD(temp_v1_3, s32 (**)(void *), 0x44)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x40)) == 1) {
        SetAmbGrf(arg0, 0x400, 0x400);
    }
block_28:
    temp_v0_10 = M2C_FIELD(sp0, void **, 0xC);
    M2C_FIELD(temp_v0_10, M2C_UNK (**)(void *, void *), 0x14)(sp0 + M2C_FIELD(temp_v0_10, s16 *, 0x10), sp0);
}
