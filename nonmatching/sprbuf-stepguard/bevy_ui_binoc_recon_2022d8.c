#include "m2c_macros.h"

s32 bevy_ui_binoc_recon_2022d8(void *arg0) {
    s32 temp_v0;
    s32 var_a1;
    void **var_a0;
    void *temp_v0_2;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0xB8) == 0) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x30);
        var_a1 = 0;
        if (temp_v0 > 0) {
            var_a0 = arg0 + 0x34;
loop_6:
            temp_v1 = *var_a0;
            if (((u64) M2C_FIELD(temp_v1, u64 *, 0x28) >> 0x3C) & 1) {
                temp_v0_2 = M2C_FIELD(temp_v1, void **, 0x100);
                if (temp_v0_2 != NULL) {
                    if (((u64) M2C_FIELD(temp_v0_2, u64 *, 0x28) >> 0x3C) & 1) {
                        goto block_11;
                    }
                    /* Duplicate return node #3. Try simplifying control flow for better match */
                    return 1;
                }
                /* Duplicate return node #3. Try simplifying control flow for better match */
                return 1;
            }
block_11:
            var_a1 += 1;
            var_a0 += 4;
            if (var_a1 >= temp_v0) {
                /* Duplicate return node #12. Try simplifying control flow for better match */
                return 0;
            }
            goto loop_6;
        }
        return 0;
    }
    return 1;
}
