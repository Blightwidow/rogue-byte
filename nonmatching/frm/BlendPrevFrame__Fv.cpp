typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BlendPrevFrame__Fv {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ M2C_UNK sp30;                       /* inferred */
    /* 0x030 */ char pad30[0x690];
};                                                  /* size = 0x6C0 */
s32 AddDmaCnt__4DMAS(s8 *);
void AddDmaEnd__4DMAS(s8 *);
void AddPrimEnd__4GIFS(s8 *);
void AddPrimPack__4GIFSiiUl(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void AllocStatic__4DMASiP2QW(s8 *, M2C_UNK, M2C_UNK *);
void EndDmaCnt__4DMAS(s8 *);
void PackAD__4GIFSll(...);
void PackUV__4GIFSii(s8 *, s32, s32);
void PackXYZF__4GIFSiiii(s8 *, s32, M2C_UNK, M2C_UNK, M2C_UNK);
void SendDmaSyncGsFinish__FP10sceDmaChanP2QW(s32, M2C_UNK *);
void __4GIFS(s8 *);
extern u64 B_002DEBE0;
extern s32 B_003E12C8;
extern s32 g_2de598;
extern s32 g_2deb24;
extern u64 g_2decd0;
extern s32 g_2dedb0;
extern s32 g_2dedb8;
void BlendPrevFrame__Fv(void) {
    s8 sp[0x30] __attribute__((aligned(16)));
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
            PackXYZF__4GIFSiiii(sp, (var_s1 + 0x700) * 0x10, 0x7900, 0, 0);
            PackUV__4GIFSii(sp, (temp_s0 * 0x10) | 8, temp_s2 + 0xE00);
            PackXYZF__4GIFSiiii(sp, (var_s1 + 0x720) * 0x10, 0x8700, 0, 0);
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
}
