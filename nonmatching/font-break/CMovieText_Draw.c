#include "m2c_macros.h"

M2C_UNK CMovieText_BuildGsMatrix(void *, M2C_UNK *, f32 *); /* extern */
M2C_UNK CMovieText_DrawGlyphs(void *, M2C_UNK *, M2C_UNK *, s128); /* extern */
M2C_UNK CMovieText_SetBaseColor(void *, void *, M2C_UNK); /* extern */
M2C_UNK CopyAqw__FPvT0i(s64 *, M2C_UNK *, M2C_UNK); /* extern */
void *OnGameLoad__FP4GAME(s32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK memset(f32 *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK B_002DF010;
extern M2C_UNK B_00442210;
extern s128 g_2a2e10;
extern s128 g_2a2e20;
extern M2C_UNK g_2dea28;

void CMovieText_Draw(void *arg0, void *arg1, s32 arg2) {
    char sp[0x400];
    f32 sp10;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    M2C_UNK sp30;
    M2C_UNK sp70;
    f32 sp78;
    s128 sp80;
    s128 sp90;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_a0;
    s64 *temp_s3;
    s64 *temp_v0;
    s64 *temp_v0_2;
    s64 *temp_v0_3;
    s64 *temp_v0_4;
    s64 *temp_v0_5;
    s64 *temp_v1;
    s64 *temp_v1_2;
    s64 *temp_v1_3;
    s64 *var_a0;
    void *temp_v0_6;

    if (arg1 != NULL) {
        M2C_FIELD(arg0, f32 *, 0x6C) = (f32) M2C_FIELD(arg1, f32 *, 0);
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) M2C_FIELD(arg1, f32 *, 4);
        M2C_FIELD(arg0, f32 *, 0x74) = (f32) M2C_FIELD(arg1, f32 *, 8);
        M2C_FIELD(arg0, f32 *, 0x78) = (f32) M2C_FIELD(arg1, f32 *, 0xC);
        M2C_FIELD(arg0, s32 *, 0x90) = (s32) M2C_FIELD(arg1, s32 *, 0x14);
        M2C_FIELD(arg0, s32 *, 0x94) = arg2;
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) M2C_FIELD(arg1, s32 *, 0x18);
        CMovieText_SetBaseColor(sp, arg1, M2C_UNALIGNED32(M2C_FIELD(arg1, M2C_UNK *, 0x10)));
        memset(&sp10, 0, 0x20);
        temp_f3 = M2C_FIELD(arg0, f32 *, 0x80);
        temp_f4 = M2C_FIELD(arg0, f32 *, 0x88);
        sp1C = temp_f3 * temp_f4;
        sp10 = M2C_FIELD(arg0, f32 *, 0x7C) * temp_f4;
        sp20 = M2C_FIELD(arg0, f32 *, 0x6C);
        sp24 = M2C_FIELD(arg0, f32 *, 0x70) + (M2C_FIELD(arg0, f32 *, 0x84) * temp_f3);
        CMovieText_BuildGsMatrix(arg0, &sp30, &sp10);
        sp90 = g_2a2e20;
        sp80 = g_2a2e10;
        sp78 = 16.0f;
        CMovieText_DrawGlyphs(arg0, &sp30, &sp70, g_2a2e10);
        temp_s3 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
        M2C_FIELD(temp_s3, s64 *, 0) = 0x10000000;
        temp_v1 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (temp_v1 + 0x10);
        M2C_FIELD(temp_v1, s32 *, 0x10) = 0x11000000;
        temp_v0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0;
        if (((s32) temp_v0 & 0xF) != 0xC) {
            do {
                M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0;
                temp_v1_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
                M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v1_2;
            } while (((s32) temp_v1_2 & 0xF) != 0xC);
        }
        M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x50000003;
        temp_v0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_2;
        CopyAqw__FPvT0i(temp_v0_2, &B_00442210, 3);
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x30);
        var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
        if (((s32) var_a0 & 0xF) != 0xC) {
            do {
                *var_a0 = 0;
                temp_v0_3 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
                var_a0 = temp_v0_3;
                M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_3;
            } while (((s32) var_a0 & 0xF) != 0xC);
        }
        M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x50000025;
        temp_v0_4 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_4;
        CopyAqw__FPvT0i(temp_v0_4, &B_002DF010, 0x25);
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x250);
        M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x11000000;
        temp_v0_5 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_5;
        if ((s32) temp_v0_5 & 0xF) {
            do {
                M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0;
                temp_v1_3 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
                M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v1_3;
            } while ((s32) temp_v1_3 & 0xF);
        }
        temp_a0 = M2C_FIELD(temp_s3, s32 *, 0) | (((s32) (M2C_FIELD(&g_2dea28, s64 **, 0xC) - temp_s3) >> 4) - 1);
        M2C_FIELD(temp_s3, s32 *, 0) = temp_a0;
        M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x60000000;
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x10);
        temp_v0_6 = OnGameLoad__FP4GAME(temp_a0, &g_2dea28, 0x60000000);
        M2C_FIELD(temp_v0_6, s32 *, 0) = 0x15;
        M2C_FIELD(temp_v0_6, s32 *, 8) = (s32) ((s32) temp_s3 & 0x0FFFFFFF);
        M2C_FIELD(temp_v0_6, s32 *, 0xC) = 0;
        M2C_FIELD(temp_v0_6, f32 *, 4) = (f32) (M2C_FIELD(arg0, s32 *, 0x94) << 0x12);
    }
}
