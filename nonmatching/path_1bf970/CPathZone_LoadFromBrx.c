#include "m2c_macros.h"

f32 F32Read__18CBinaryInputStream(s32);             /* extern */
M2C_UNK HookupCg__FP2CG(void *);                    /* extern */
M2C_UNK LoadXfmFromBrx();                           /* extern */
s32 PvAllocSwClearImpl__Fi(void *, s32, s32);       /* extern */
s32 PvAllocSwImpl__Fi(void *, s32, s32);            /* extern */
M2C_UNK ReadVector__18CBinaryInputStreamP6VECTOR(s32, void *); /* extern */
s32 U16Read__18CBinaryInputStream(s32);             /* extern */
s32 U8Read__18CBinaryInputStream(s32);              /* extern */
extern M2C_UNK B_003DD490;

void LoadPathzoneFromBrx__FP8PATHZONEP18CBinaryInputStream(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 *temp_s0;
    s32 *var_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 var_a0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s2;
    s32 var_v1;
    void *temp_s0_2;
    void *temp_s1;

    var_s1 = 0;
    LoadXfmFromBrx();
    temp_v0 = U16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0xE0) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0xE4) = PvAllocSwClearImpl__Fi(sp, temp_v0 << 5, 0x10);
    temp_v0_2 = U16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0xE8) = temp_v0_2;
    M2C_FIELD(arg0, s32 *, 0xEC) = PvAllocSwClearImpl__Fi(sp, temp_v0_2 * 0xC, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
loop_2:
        temp_s1 = M2C_FIELD(arg0, s32 *, 0xE4) + (var_s1 << 5);
        var_s2 = 0;
        ReadVector__18CBinaryInputStreamP6VECTOR(arg1, temp_s1);
        temp_v0_3 = U8Read__18CBinaryInputStream(arg1);
        M2C_FIELD(temp_s1, s32 *, 0x10) = temp_v0_3;
        M2C_FIELD(temp_s1, s32 *, 0x14) = PvAllocSwImpl__Fi(sp, (temp_v0_3 * 8) + 8, 0x10);
        if (M2C_FIELD(temp_s1, s32 *, 0x10) > 0) {
            do {
                temp_v0_4 = var_s2 * 8;
                var_s2 += 1;
                temp_s0 = M2C_FIELD(temp_s1, s32 *, 0x14) + temp_v0_4;
                *temp_s0 = M2C_FIELD(arg0, s32 *, 0xE4) + (U16Read__18CBinaryInputStream(arg1) << 5);
            } while (var_s2 < M2C_FIELD(temp_s1, s32 *, 0x10));
        }
        var_s1 += 1;
        if (var_s1 < M2C_FIELD(arg0, s32 *, 0xE0)) {
            goto loop_2;
        }
    }
    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
        var_v1 = 0 * 0xC;
        do {
            var_s1_2 = 2;
            var_s0 = M2C_FIELD(arg0, s32 *, 0xEC) + var_v1;
loop_10:
            var_s1_2 -= 1;
            *var_s0 = M2C_FIELD(arg0, s32 *, 0xE4) + (U16Read__18CBinaryInputStream(arg1) << 5);
            var_s0 += 4;
            if (var_s1_2 >= 0) {
                goto loop_10;
            }
            var_a0 += 1;
            var_v1 = var_a0 * 0xC;
        } while (var_a0 < M2C_FIELD(arg0, s32 *, 0xE8));
    }
    var_s1_3 = 0;
    temp_v0_5 = U16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0xF0) = temp_v0_5;
    M2C_FIELD(arg0, s32 *, 0xF4) = PvAllocSwClearImpl__Fi(sp, temp_v0_5 * 0x10, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0xF0) > 0) {
        do {
            temp_v0_6 = var_s1_3 * 0x10;
            var_s1_3 += 1;
            temp_s0_2 = M2C_FIELD(arg0, s32 *, 0xF4) + temp_v0_6;
            M2C_FIELD(temp_s0_2, f32 *, 0) = F32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0_2, f32 *, 4) = F32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0_2, f32 *, 8) = F32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0_2, s16 *, 0xC) = U16Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0_2, s16 *, 0xE) = U16Read__18CBinaryInputStream(arg1);
        } while (var_s1_3 < M2C_FIELD(arg0, s32 *, 0xF0));
    }
    HookupCg__FP2CG(arg0 + 0xE0);
    if (M2C_FIELD(arg0, s32 *, 0x18) == 0x2CA) {
        M2C_FIELD(&B_003DD490, void **, 0x45C8) = arg0;
    }
    temp_v0_7 = M2C_FIELD(&B_003DD490, s32 *, 0x3D70) + 1;
    M2C_FIELD(&B_003DD490, s32 *, 0x3D70) = temp_v0_7;
    M2C_FIELD(arg0, s32 *, 0x114) = temp_v0_7;
}
