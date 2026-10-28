#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS();                   /* extern */
M2C_UNK AddDmaEnd__4DMAS();                   /* extern */
M2C_UNK AddPrimEnd__4GIFS();                  /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(); /* extern */
M2C_UNK EndDmaCnt__4DMAS();                   /* extern */
M2C_UNK PackAD__4GIFSll(); /* extern */
M2C_UNK PackUV__4GIFSii();          /* extern */
M2C_UNK PackXYZF__4GIFSiiii(); /* extern */
M2C_UNK SendDmaSyncGsFinish__FP10sceDmaChanP2QW(); /* extern */
M2C_UNK __4GIFS();                            /* extern */
extern u64 B_002DEBE0;
extern s32 B_003E12C8;
extern s32 g_2de598;
extern s32 g_2deb24;
extern u64 g_2decd0;
extern s32 g_2dedb0;
extern s32 g_2dedb8;

void BlendPrevFrame__Fv(void) {
    char sp[0x400];
    M2C_UNK sp30;
    s32 temp_s0;
    s32 temp_s2;
    s32 var_a1;
    s32 var_s1;
    s64 temp_a3;
    u64 *var_v0;
    u64 temp_a2;

    if (g_2deb24 == 0) {
        if (B_003E12C8 == 0) {
            __4GIFS(sp);
            AllocStatic__4DMASiP2QW(sp, 0x64, &sp30);
            AddDmaCnt__4DMAS(sp);
            AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
            PackAD__4GIFSll(sp, 0x3F, 0);
            if (g_2dedb0 & 1) {
                var_v0 = &B_002DEBE0;
            } else {
                var_v0 = &g_2decd0;
            }
            temp_a2 = *var_v0;
            temp_a3 = 0xAA00 << 0x12;
            var_s1 = 0;
            PackAD__4GIFSll(sp, 6, ((temp_a2 & 0x1FF) << 5) | (((temp_a2 >> 0x10) & 0x3F) << 0xE) | (((temp_a2 >> 0x18) & 0x3F) << 0x14) | temp_a3, temp_a3);
            PackAD__4GIFSll(sp, 0x14, 0x61);
            PackAD__4GIFSll(sp, 8, 5);
            PackAD__4GIFSll(sp, 0x47, 0x33001);
            PackAD__4GIFSll(sp, 0x42, (0xC000 << 0x16) | 0x64);
            PackAD__4GIFSll(sp, 1, (((0xFE00 << 0x1E) | 0x8080) << 0x10) | 0x8080);
            PackAD__4GIFSll(sp, 0x40, ((((0xDE00 << 0x17) | 0x80FF) << 0x10) | 0x8000) * 2);
            AddPrimPack__4GIFSiiUl(sp, 0x156, 2, 0x43);
            temp_s2 = (g_2dedb8 & 1) ? 0 : 0x10;
            var_a1 = 0 * 0x10;
loop_6:
            PackUV__4GIFSii(sp, var_a1 | 8, temp_s2);
            temp_s0 = var_s1 + 0x20;
            PackXYZF__4GIFSiiii(sp, (var_s1 + 0x700) * 0x10, 0x7900, 0);
            PackUV__4GIFSii(sp, (temp_s0 * 0x10) | 8, temp_s2 + 0xE00);
            PackXYZF__4GIFSiiii(sp, (var_s1 + 0x720) * 0x10, 0x8700, 0);
            var_s1 = temp_s0;
            if (var_s1 < 0x200) {
                var_a1 = var_s1 * 0x10;
                goto loop_6;
            }
            AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
            PackAD__4GIFSll(sp, 0x40, ((0xDF00 << 0x1F) | 0xFF80) << 9);
            PackAD__4GIFSll(sp, 0x61, 0);
            AddPrimEnd__4GIFS(sp);
            AddDmaEnd__4DMAS(sp);
            EndDmaCnt__4DMAS(sp);
            SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de598, &sp30);
        }
    }
}
