#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaEnd__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRefs__4DMASiP2QW(M2C_UNK *, M2C_UNK, s32 *); /* extern */
M2C_UNK AddPrimEnd__4GIFS(M2C_UNK *);               /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(M2C_UNK *, M2C_UNK, M2C_UNK *); /* extern */
s64 AllocZpr(s32, M2C_UNK, s32, s32);               /* extern */
M2C_UNK BuildImageGifs__FiiiiiiP4GIFS(s64, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
f32 ConvertUserHsvToUserRgb__FP6VECTORT0(M2C_UNK *, f32 *); /* extern */
M2C_UNK Detach__4DMASPiPP2QW(M2C_UNK *, M2C_UNK, s32 *); /* extern */
M2C_UNK PackAD__4GIFSll(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SendDmaSyncGsFinish__FP10sceDmaChanP2QW(s32, s32); /* extern */
M2C_UNK __4GIFS(M2C_UNK *);                         /* extern */
extern M2C_UNK B_003E1300;
extern M2C_UNK D_002C3680;
extern s32 g_2de598;

void func_001EA9F0(void *arg0, s32 arg1) {
    M2C_UNK sp14;
    M2C_UNK sp18;
    M2C_UNK sp24;
    s32 sp10;
    f32 sp20;
    s32 sp30;
    M2C_UNK sp430;
    M2C_UNK sp460;
    s32 spC60;
    M2C_UNK *spC64;
    s32 *spC68;
    M2C_UNK *var_s3;
    f32 *var_s2;
    f32 temp_f0;
    f32 temp_f0_2;
    s32 *temp_v0;
    s32 *var_a1;
    s32 *var_s0;
    s32 temp_a0;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a3;
    s32 var_s1;
    s32 var_t2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;

    if ((arg1 != 0) || (M2C_FIELD(arg0, u64 *, 0x3EA0) & (0xFFFC << 0x23))) {
        spC64 = &sp460;
        spC68 = &spC60;
        var_v0 = 1;
        do {
            var_v0 -= 1;
        } while (var_v0 != -1);
        var_s0 = &sp10;
        var_s3 = &B_003E1300;
        var_s2 = &B_003E1300 - 0xC;
        var_s1 = 2;
        do {
            temp_f0 = ConvertUserHsvToUserRgb__FP6VECTORT0(var_s3, &sp20);
            var_s3 += 0x10;
            var_s1 -= 1;
            temp_f0_2 = *var_s2;
            var_s2 += 4;
            M2C_FIELD(var_s0, f32 *, -0x10) = (f32) (temp_f0_2 * 0.003921569f);
            M2C_FIELD(var_s0, s32 *, 0) = sp24 | (M2C_BITWISE(s32, temp_f0) << 8) | (sp24 << 0x10);
            var_s0 += 4;
        } while (var_s1 >= 0);
        var_v0_2 = 0xFE;
        do {
            var_v0_2 -= 1;
        } while (var_v0_2 != -1);
        var_a1 = &sp30;
        var_a3 = 0;
        var_t2 = 0x20;
        do {
            var_a2 = 0;
loop_10:
            var_a2_2 = 7;
loop_11:
            temp_a0 = var_a3 & 0x81;
            switch (temp_a0) {                      /* irregular */
            case 0x81:
                var_v1 = sp18;
block_20:
                var_a1 += 4;
                *var_a1 = var_v1 | (M2C_BITWISE(s32, M2C_ERROR(/* unknown instruction: max.s $f1, $f0, $f3 */)) << 0x18);
                break;
            case 0x80:
                var_v1 = sp10;
                goto block_20;
            case 0x1:
                var_v1 = sp14;
                goto block_20;
            case 0x0:
                *var_a1 = 0;
                var_a1 += 4;
                break;
            }
            var_a3 += 1;
            var_a2_2 -= 1;
            if (var_a2_2 >= 0) {
                goto loop_11;
            }
            temp_v0 = (var_a2 * 4) + &D_002C3680;
            var_a2 += 1;
            var_a3 += *temp_v0;
            if (var_a2 < 4) {
                goto loop_10;
            }
            var_t2 += 0x20;
        } while (var_t2 < 0x100);
        if (arg1 != 0) {
            M2C_FIELD(arg0, u64 *, 0x3EA0) = (u64) ((AllocZpr(arg1, 4, var_a2, var_a3) << 0x25) | (((0x8000 << 0x25) | 0xD800) << 9));
        }
        __4GIFS(&sp430);
        AllocStatic__4DMASiP2QW(&sp430, 0x80, spC64);
        AddDmaCnt__4DMAS(&sp430);
        BuildImageGifs__FiiiiiiP4GIFS((s64) ((((u64) M2C_FIELD(arg0, u64 *, 0x3EA0) >> 0x25) & 0x3FFF) << 0x20) >> 0x20, 1, 0, 0x10);
        AddDmaRefs__4DMASiP2QW(&sp430, 0x40, &sp30);
        AddPrimPack__4GIFSiiUl(&sp430, 0, 1, 0xE);
        PackAD__4GIFSll(&sp430, 0x3F, 0);
        PackAD__4GIFSll(&sp430, 0x61, 0);
        AddPrimEnd__4GIFS(&sp430);
        AddDmaEnd__4DMAS(&sp430);
        Detach__4DMASPiPP2QW(&sp430, 0, spC68);
        SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de598, spC60);
    }
}
