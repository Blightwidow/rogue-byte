#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK GetLaserBeamPoints(void *, void *, void *, f32 *); /* extern */
f32 fmodf(s32, f32, f32);                           /* extern */
extern M2C_UNK B_003E11C4;
extern M2C_UNK g_2dded0;

void AdvanceLaserBeams(void *arg0) {
    char sp[0x400];
    f32 sp20;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f2;
    s32 temp_hi;
    s32 var_a0;
    s32 var_a0_2;
    s64 temp_v1;
    void *temp_a1;
    void *temp_s3;
    void *var_s0;
    void *var_v0;

    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x198) > 0) {
        do {
            var_a0_2 = 0;
            temp_s3 = M2C_FIELD(arg0, s32 *, 0x19C) + (var_a0 * 0x150);
            var_s0 = temp_s3;
loop_3:
            if (M2C_FIELD(var_s0, s32 *, 4) == 1) {
                var_v0 = var_s0 + ((M2C_FIELD(var_s0, s32 *, 0x94) * 0x14) + 0x1C);
                temp_f13 = M2C_FIELD(var_v0, f32 *, 0xC);
                temp_f12 = M2C_FIELD(var_v0, f32 *, 0x10) + (M2C_FIELD(arg0, f32 *, 0x1C0) * M2C_FIELD(&g_2dded0, f32 *, 4));
                M2C_FIELD(var_v0, f32 *, 0x10) = temp_f12;
                if (temp_f13 < temp_f12) {
                    temp_f0 = fmodf(var_a0_2, temp_f12, temp_f13);
                    temp_hi = (s32) (M2C_FIELD(var_s0, s32 *, 0x94) + 1) % (s32) M2C_FIELD(var_s0, s32 *, 0x18);
                    M2C_FIELD(var_s0, s32 *, 0x94) = temp_hi;
                    var_v0 = var_s0 + ((temp_hi * 0x14) + 0x1C);
                    M2C_FIELD(var_v0, f32 *, 0x10) = temp_f0;
                }
                temp_f2 = M2C_FIELD(var_v0, f32 *, 0x10);
                M2C_FIELD(var_s0, f32 *, 0x14) = (f32) (M2C_FIELD(var_v0, f32 *, 0) + (M2C_FIELD(var_v0, f32 *, 4) * temp_f2) + (M2C_FIELD(var_v0, f32 *, 8) * temp_f2 * temp_f2 * 0.5f));
                temp_a1 = M2C_FIELD(arg0, void **, 0xEC);
                temp_v1 = M2C_FIELD(temp_a1, s64 *, 0x70);
                if (!(temp_v1 & 2)) {
                    M2C_FIELD(temp_a1, s64 *, 0x70) = (s64) (temp_v1 | 2);
                    AppendDlEntry(&B_003E11C4, M2C_FIELD(arg0, void **, 0xEC));
                }
                var_a0_2 = 1;
            }
            var_s0 += 0xA0;
            if ((u32) var_s0 < (u32) (temp_s3 + 0x140)) {
                goto loop_3;
            }
            if ((var_a0_2 != 0) && (M2C_FIELD(temp_s3, s32 *, 0x148) == 0)) {
                GetLaserBeamPoints(arg0, temp_s3, sp, &sp20);
                M2C_FIELD(temp_s3, f32 *, 0x140) = sp20;
                M2C_FIELD(temp_s3, f32 *, 0x144) = sp20;
            }
            var_a0 += 1;
        } while (var_a0 < M2C_FIELD(arg0, s32 *, 0x198));
    }
}
