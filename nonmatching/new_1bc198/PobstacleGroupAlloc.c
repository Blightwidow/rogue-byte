#include "m2c_macros.h"

M2C_UNK AppendDlEntry(void **, void *);             /* extern */
void *PloNew(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
s32 PvAllocSwImpl__Fi(void *, s32, s32);            /* extern */
M2C_UNK RemoveDlEntry(void **, void *);             /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern void *B_003E1A40;

void *PobstacleGroupAlloc(void) {
    char sp[0x400];
    f32 *temp_v0_2;
    f32 temp_f0;
    s32 var_a0;
    s32 var_s0;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v1;

    temp_s0 = B_003E1A40;
    if (temp_s0 == NULL) {
        var_s0 = 0;
        do {
            temp_v0 = PloNew(0xE, 0, 0x2CD, -1);
            temp_s0_2 = temp_v0 + 0x60;
            M2C_FIELD(temp_v0, s32 *, 0xE0) = 0;
            M2C_FIELD(temp_v0, s32 *, 0xE4) = 1;
            M2C_FIELD(temp_v0, s32 *, 0x1C0) = 1;
            memset(temp_s0_2, 0, 0x40);
            M2C_FIELD(temp_s0_2, f32 *, 0x14) = 1.0f;
            M2C_FIELD(temp_s0_2, f32 *, 0x3C) = 1.0f;
            M2C_FIELD(temp_s0_2, f32 *, 0x28) = 1.0f;
            M2C_FIELD(temp_v0, f32 *, 0x60) = 1.0f;
            M2C_FIELD(temp_v0, s32 *, 0xEC) = PvAllocSwImpl__Fi(sp, 0x80, 0x10);
            var_a0 = 0;
loop_3:
            temp_f0 = (f32) var_a0;
            temp_v0_2 = (var_a0 * 4) + M2C_FIELD(temp_v0, s32 *, 0xEC);
            var_a0 += 1;
            *temp_v0_2 = temp_f0;
            if (var_a0 < 0x20) {
                goto loop_3;
            }
            var_s0 += 1;
            M2C_FIELD(temp_v0, s32 *, 0xF0) = PvAllocSwImpl__Fi(sp, 0x80, 0x10);
            M2C_FIELD(temp_v0, s32 *, 0xF4) = PvAllocSwImpl__Fi(sp, 0x200, 0x10);
            M2C_FIELD(temp_v0, s32 *, 0x1EC) = PvAllocSwImpl__Fi(sp, 0x1F0, 0x10);
            temp_v0_3 = M2C_FIELD(temp_v0, void **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *), 0x4C)(temp_v0 + M2C_FIELD(temp_v0_3, s16 *, 0x48));
            AppendDlEntry(&B_003E1A40, temp_v0);
        } while (var_s0 < 0x10);
    }
    RemoveDlEntry(&B_003E1A40, temp_s0);
    temp_v1 = M2C_FIELD(temp_s0, void **, 0xC);
    M2C_FIELD(temp_s0, s32 *, 0x1E8) = -1;
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x44)(temp_s0 + M2C_FIELD(temp_v1, s16 *, 0x40));
    M2C_FIELD(temp_s0, s32 *, 0x1D8) = 0;
    return temp_s0;
}
