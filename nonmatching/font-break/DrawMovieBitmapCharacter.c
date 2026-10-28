#include "m2c_macros.h"

M2C_UNK CopyAqw__FPvT0i(s32 *, s32, s32, void *);   /* extern */
void *OnGameLoad__FP4GAME(s32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK g_2dea28;

void DrawMovieBitmapCharacter(void *arg0, void *arg1, void *arg2) {
    char sp[0x400];
    s32 *temp_s3;
    s32 *temp_v0;
    s32 *temp_v0_2;
    s32 *temp_v0_3;
    s32 *temp_v0_4;
    s32 *temp_v0_5;
    s32 *temp_v0_6;
    s32 *temp_v1_2;
    s32 *var_a0;
    s32 *var_a0_2;
    s32 *var_a0_3;
    s32 *var_a2;
    s32 *var_a2_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_a1;
    s32 var_t0;
    s32 var_t0_2;
    void *temp_v0_7;
    void *temp_v1_5;
    void *var_a3;
    void *var_a3_2;
    void *var_s1;
    void *var_v0;
    void *var_v0_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    switch (temp_v1) {                              /* irregular */
    case 7:
        var_v0 = M2C_FIELD(arg0, void **, 0x1C);
block_6:
        if (var_v0 != NULL) {
            memset(sp, 0, 0x40);
            var_a3 = sp;
            M2C_FIELD(arg2, s32 *, 0xC) = 0x7FFF;
            M2C_FIELD(arg2, s32 *, 4) = 0;
            temp_s3 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
            M2C_FIELD(temp_s3, s64 *, 0) = 0x10000000;
            temp_v1_2 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (temp_v1_2 + 0x10);
            M2C_FIELD(temp_v1_2, s32 *, 0x10) = 0x6C04C000;
            temp_v0 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
            var_a2 = temp_v0;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0;
            var_t0 = 0xC;
            do {
                var_t0 -= 4;
                temp_v1_3 = M2C_FIELD(var_a3, s32 *, 4);
                temp_a0 = M2C_FIELD(var_a3, s32 *, 8);
                temp_a1 = M2C_FIELD(var_a3, s32 *, 0xC);
                M2C_FIELD(var_a2, s32 *, 0) = M2C_FIELD(var_a3, s32 *, 0);
                var_a3 += 0x10;
                M2C_FIELD(var_a2, s32 *, 4) = temp_v1_3;
                M2C_FIELD(var_a2, s32 *, 8) = temp_a0;
                M2C_FIELD(var_a2, s32 *, 0xC) = temp_a1;
                var_a2 += 0x10;
            } while (var_t0 >= 0);
            var_a3_2 = arg2;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x40);
            M2C_FIELD(M2C_FIELD(&g_2dea28, s32 **, 0xC), s64 *, 0) = 0x6C03C004;
            temp_v0_2 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
            var_a2_2 = temp_v0_2;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0_2;
            var_t0_2 = 8;
            do {
                var_t0_2 -= 4;
                temp_v1_4 = M2C_FIELD(var_a3_2, s32 *, 4);
                temp_a0_2 = M2C_FIELD(var_a3_2, s32 *, 8);
                temp_a1_2 = M2C_FIELD(var_a3_2, s32 *, 0xC);
                M2C_FIELD(var_a2_2, s32 *, 0) = M2C_FIELD(var_a3_2, s32 *, 0);
                var_a3_2 += 0x10;
                M2C_FIELD(var_a2_2, s32 *, 4) = temp_v1_4;
                M2C_FIELD(var_a2_2, s32 *, 8) = temp_a0_2;
                M2C_FIELD(var_a2_2, s32 *, 0xC) = temp_a1_2;
                var_a2_2 += 0x10;
            } while (var_t0_2 >= 0);
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x30);
            if (M2C_FIELD(arg0, s32 *, 4) == 6) {
                temp_v1_5 = M2C_FIELD(arg0, void **, 0x14);
                var_a0 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
                var_a1 = M2C_FIELD(temp_v1_5, s32 *, 0x1C);
                var_s1 = M2C_FIELD(temp_v1_5, void **, 0x18);
                if (((s32) var_a0 & 0xF) != 0xC) {
                    do {
                        *var_a0 = 0;
                        temp_v0_3 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                        var_a0 = temp_v0_3;
                        M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0_3;
                    } while (((s32) var_a0 & 0xF) != 0xC);
                }
            } else {
                var_s1 = M2C_FIELD(arg0, void **, 0x1C);
                var_a0_2 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
                var_a1 = M2C_FIELD(arg0, s32 *, 0x20);
                if (((s32) var_a0_2 & 0xF) != 0xC) {
                    do {
                        *var_a0_2 = 0;
                        temp_v0_4 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                        var_a0_2 = temp_v0_4;
                        M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0_4;
                    } while (((s32) var_a0_2 & 0xF) != 0xC);
                }
            }
            M2C_FIELD(M2C_FIELD(&g_2dea28, s32 **, 0xC), s64 *, 0) = (s32) var_s1 | 0x50000000;
            temp_v0_5 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0_5;
            CopyAqw__FPvT0i(temp_v0_5, var_a1, (s32) var_s1, var_a3_2);
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + ((s32) var_s1 * 0x10));
            var_a0_3 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
            if ((s32) var_a0_3 & 0xF) {
                do {
                    *var_a0_3 = 0;
                    temp_v0_6 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                    var_a0_3 = temp_v0_6;
                    M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0_6;
                } while ((s32) var_a0_3 & 0xF);
            }
            temp_a0_3 = M2C_FIELD(temp_s3, s32 *, 0) | (((s32) (M2C_FIELD(&g_2dea28, s32 **, 0xC) - temp_s3) >> 4) - 1);
            M2C_FIELD(temp_s3, s32 *, 0) = temp_a0_3;
            M2C_FIELD(M2C_FIELD(&g_2dea28, s32 **, 0xC), s64 *, 0) = 0x60000000;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x10);
            temp_v0_7 = OnGameLoad__FP4GAME(temp_a0_3, &g_2dea28, 0x60000000);
            M2C_FIELD(temp_v0_7, s32 *, 0) = 0x15;
            M2C_FIELD(temp_v0_7, s32 *, 8) = (s32) ((s32) temp_s3 & 0x0FFFFFFF);
            M2C_FIELD(temp_v0_7, f32 *, 4) = (f32) (M2C_FIELD(arg2, f32 *, 8) + (f32) (M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0xA4) << 0x12));
            if (M2C_FIELD(arg0, s32 *, 4) != 6) {
                var_v0_2 = M2C_FIELD(arg0, void **, 0x18);
            } else {
                var_v0_2 = M2C_FIELD(arg0, void **, 0x1C);
            }
            M2C_FIELD(temp_v0_7, void **, 0xC) = var_v0_2;
        }
        return;
    case 6:
        var_v0 = M2C_FIELD(arg0, void **, 0x14);
        goto block_6;
    }
}
