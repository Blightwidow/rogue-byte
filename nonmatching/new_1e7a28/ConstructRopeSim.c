#include "m2c_macros.h"

s128 *PvAllocSwClearImpl__Fi(void *, s32, s32);     /* extern */
M2C_UNK RemeasureRopeSim(void *, void *, s32);      /* extern */
extern M2C_UNK D_002C44F0;

void *ConstructRopeSim(void *arg0, void *arg1) {
    char sp[0x400];
    s128 *temp_a0_2;
    s128 *temp_v0;
    s16 temp_a1;
    s32 temp_a2;
    s32 var_a1;
    void *temp_a0;
    void *temp_a1_2;
    void *temp_v1;

    M2C_FIELD(arg0, void **, 0x48) = arg1;
    M2C_FIELD(arg0, s32 *, 0x4C) = -1;
    M2C_FIELD(arg0, s128 **, 0x54) = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(arg1, s32 *, 0xE8) * 0x10, 0x10);
    M2C_FIELD(arg0, s128 **, 0x58) = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(arg1, s32 *, 0xE8) * 0x10, 0x10);
    temp_v0 = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(arg1, s32 *, 0xE8) * 4, 0x10);
    M2C_FIELD(arg0, f32 *, 8) = -1750.0f;
    M2C_FIELD(arg0, s128 **, 0x5C) = temp_v0;
    M2C_FIELD(arg0, f32 *, 0x60) = 3.0f;
    M2C_FIELD(arg0, f32 *, 0x6C) = 500.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    temp_a0 = M2C_FIELD(arg0, void **, 0x48);
    M2C_FIELD(arg0, f32 *, 0x88) = 300.0f;
    M2C_FIELD(arg0, s32 *, 0x84) = (s32) M2C_FIELD(temp_a0, s32 *, 0xE8);
    temp_v1 = M2C_FIELD(temp_a0, void **, 0xC);
    temp_a1 = M2C_FIELD(temp_v1, s16 *, 0xF8);
    temp_a2 = M2C_FIELD(temp_v1, s32 (**)(void *, s16), 0xFC)(temp_a0 + temp_a1, temp_a1);
    var_a1 = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), s32 *, 0xE8) > 0) {
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($a2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($a2) */);
            var_a1 += 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($a2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($a2) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf5z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($v1) */);
        } while (var_a1 < M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), s32 *, 0xE8));
    }
    temp_a1_2 = M2C_FIELD(arg0, void **, 0x48);
    M2C_FIELD(arg0, M2C_UNK **, 0x40) = &D_002C44F0;
    M2C_FIELD(arg0, M2C_UNK **, 0x44) = &D_002C44F0;
    if (M2C_FIELD(temp_a1_2, s32 *, 0xE8) > 0) {
        temp_a0_2 = M2C_FIELD(arg0, s128 **, 0x54);
        M2C_FIELD(arg0, s128 *, 0x20) = (s128) *temp_a0_2;
        M2C_FIELD(arg0, s128 *, 0x30) = (s128) M2C_FIELD(&temp_a0_2[M2C_FIELD(temp_a1_2, s32 *, 0xE8)], s128 *, -0x10);
    }
    RemeasureRopeSim(arg0, temp_a1_2, temp_a2);
    return arg0;
}
