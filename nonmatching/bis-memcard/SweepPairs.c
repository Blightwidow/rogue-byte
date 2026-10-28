#include "m2c_macros.h"

M2C_UNK FreeSlotheapPv(M2C_UNK *, void *);          /* extern */
M2C_UNK UnlinkPairNode(void *);                     /* extern */
extern void *B_002DD280;
extern s32 B_002DD288;
extern M2C_UNK B_00452098;
extern M2C_UNK B_004520A8;
extern s32 g_2dd598;

void SweepPairs(void) {
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0_2;
    u32 temp_a0;
    u32 temp_v0;
    u32 temp_v0_2;
    void *var_s0;
    void *var_s1;
    void *var_s2;
    void *var_v0;

    var_s0 = B_002DD280;
    if (var_s0 != B_002DD288) {
        do {
            temp_a0 = M2C_FIELD(var_s0, u32 *, 4);
            if ((temp_a0 >> 0x1F) != g_2dd598) {
                M2C_FIELD(var_s0, u32 *, 4) = (u32) ((temp_a0 & 0x7FFFFFFF) | (g_2dd598 << 0x1F));
            }
            temp_v0 = M2C_FIELD(var_s0, u32 *, 4);
            temp_a0_2 = (temp_v0 >> 0x10) & 0x1FFF;
            temp_v1 = (temp_v0 >> 0x1D) & 3;
            if ((temp_a0_2 != 0) || (var_v0 = NULL, (temp_v1 != 0))) {
                var_v0 = *((temp_v1 * 4) + &B_00452098) + (temp_a0_2 * 0x14);
            }
            var_s0 = var_v0;
        } while (var_s0 != B_002DD288);
    }
    if (var_s0 != NULL) {
        var_s1 = var_s0;
        do {
            temp_v0_2 = M2C_FIELD(var_s1, u32 *, 4);
            temp_a0_3 = (temp_v0_2 >> 0x10) & 0x1FFF;
            temp_v1_2 = (temp_v0_2 >> 0x1D) & 3;
            if (temp_a0_3 == 0) {
                var_v0_2 = temp_v1_2 * 4;
                if (temp_v1_2 == 0) {
                    var_s2 = NULL;
                } else {
                    goto block_14;
                }
            } else {
                var_v0_2 = temp_v1_2 * 4;
block_14:
                var_s2 = *(var_v0_2 + &B_00452098) + (temp_a0_3 * 0x14);
            }
            if (((u32) M2C_FIELD(var_s1, u32 *, 4) >> 0x1F) != g_2dd598) {
                UnlinkPairNode(var_s1);
                FreeSlotheapPv(&B_004520A8, var_s1);
            }
            var_s1 = var_s2;
        } while (var_s2 != NULL);
    }
}
