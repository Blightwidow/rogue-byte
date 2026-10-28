#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefGetGameSaveValue(void *, s32, s32);      /* extern */
s32 SymidFindSymtab(s32, M2C_UNK *);                /* extern */
extern M2C_UNK B_003DD490;
extern s32 D_002C2DC0;

s32 NPercentCompleteSaveData(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp4;
    s32 *var_s4;
    s32 *var_s5;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_s1;
    s32 temp_s6;
    s32 temp_t4;
    s32 temp_t5;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s6;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;
    u8 *temp_t0;
    u8 temp_a0_2;
    u8 temp_v1;
    void *temp_a0;

    var_s2 = 0;
    var_s4 = &B_003DD490 + 0x3B7C;
    var_s5 = &D_002C2DC0;
    var_s6 = 0;
    var_s3 = 8;
    do {
        temp_s1 = *var_s5;
        temp_a1 = *var_s4;
        var_s6 += temp_s1 * 0x64;
        if (temp_a1 != 0) {
            RefGetGameSaveValue(sp, temp_a1, arg1);
            CRef_Destruct(sp);
            var_s2 += sp4 * temp_s1;
        }
        var_s5 += 4;
        var_s3 -= 1;
        var_s4 += 4;
    } while (var_s3 >= 0);
    temp_s6 = var_s6 + 0xD0;
    temp_t5 = SymidFindSymtab(arg0 + 8, "fVault");
    var_v1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0) > 0) {
        var_v0_2 = 0 * 0xA;
loop_6:
        temp_t4 = var_v1 + 1;
        temp_a0 = var_v0_2 + M2C_FIELD(arg0, s32 *, 4);
        if (M2C_FIELD(temp_a0, s8 *, 2) == 4) {
            var_v1 = temp_t4;
            if (M2C_FIELD(temp_a0, s16 *, 0) == temp_t5) {
                temp_v1 = M2C_FIELD(temp_a0, u8 *, 3);
                temp_t0 = arg1 + M2C_FIELD(temp_a0, u16 *, 4);
                if (temp_v1 != 0) {
                    var_a2 = 0;
                    if (temp_v1 != 0) {
                        do {
                            temp_v0 = (s32) ((var_a2 > -1) ? var_a2 : (var_a2 + 7)) >> 3;
                            temp_a0_2 = *(temp_t0 + temp_v0);
                            temp_v1_2 = (1 << (var_a2 - (temp_v0 * 8))) & 0xFF;
                            var_a2 += 1;
                            var_s2 = (temp_a0_2 & temp_v1_2) ? (var_s2 + 0x1A) : var_s2;
                        } while (var_a2 < (s32) temp_v1);
                    }
                } else {
                    var_s2 = (*temp_t0 != 0) ? (var_s2 + 0x1A) : var_s2;
                }
                goto block_14;
            }
        } else {
block_14:
            var_v1 = temp_t4;
        }
        if (var_v1 < M2C_FIELD(arg0, s32 *, 0)) {
            var_v0_2 = var_v1 * 0xA;
            goto loop_6;
        }
    }
    var_v0 = 0;
    if (var_s2 != 0) {
        var_v0 = 0x64;
        if (var_s2 != temp_s6) {
            temp_lo = (s32) (var_s2 * 0x64) / temp_s6;
            var_v1_2 = 1;
            if (temp_lo > 0) {
                var_v1_2 = (temp_lo <= 0x63) ? temp_lo : 0x63;
            }
            var_v0 = var_v1_2;
        }
    }
    return var_v0;
}
