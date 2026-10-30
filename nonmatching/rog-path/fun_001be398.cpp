typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001BE398 {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ M2C_UNK sp30;                       /* inferred */
    /* 0x030 */ char pad30[0x4A0];
};                                                  /* size = 0x4D0 */
M2C_UNK AddPrimEnd__4GIFS(s8 *);                  /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(...); /* extern */
s32 AllocZpr(s8 *, M2C_UNK);                      /* extern */
M2C_UNK DMAS_DetachCopyPermanent(s8 *, s8 *, M2C_UNK, s8 *); /* extern */
s32 NLog2__FUi(...);              /* extern */
M2C_UNK PackAD__4GIFSll(s8 *, M2C_UNK, s64);      /* extern */
M2C_UNK PackXYZ__4GIFSiii(s8 *, s32, s32, M2C_UNK); /* extern */
M2C_UNK __4GIFS(s8 *, s64);                       /* extern */
void func_001BE398(s8 *arg0, s8 *arg1) {
    s8 sp[0x4D0] __attribute__((aligned(16)));
    M2C_UNK sp30;
    s32 temp_s0;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 var_s4;
    s64 temp_a1;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 temp_v1;
    u32 temp_v1_2;
    M2C_FIELD(arg0, u32 *, 4) = 0x80U;
    M2C_FIELD(arg0, u32 *, 0) = 0x80U;
    temp_v0 = AllocZpr(arg1, 0x100);
    M2C_FIELD(arg0, s64 *, 8) = (s64) (((((M2C_FIELD(arg0, s64 *, 8) & ~0x3FFF) | (temp_v0 & 0x3FFF)) & (s64)(s32)0xFFF03FFF) | 0x8000) & (s64)(s32)0xFC0FFFFF);
    M2C_FIELD(arg0, s64 *, 8) = (s64) ((M2C_FIELD(arg0, s64 *, 8) & (s64)(s32)0xC3FFFFFF) | ((NLog2__FUi(M2C_FIELD(arg0, u32 *, 0), 0xFFF03FFF, 0xFC0FFFFF) & 0xF) << 0x1A));
    temp_a1 = 0x8000 << 0x13;
    M2C_FIELD(arg0, s64 *, 8) = (s64) ((M2C_FIELD(arg0, s64 *, 8) & ((0x87FFFFFF * 8) | 7)) | ((NLog2__FUi(M2C_FIELD(arg0, u32 *, 4)) & 0xF) << 0x1E) | temp_a1);
    temp_s0 = (s32) (M2C_FIELD(arg1, s32 *, 8) - 0x100) >> 5;
    __4GIFS(sp, temp_a1);
    temp_v1 = M2C_FIELD(arg0, u32 *, 0);
    temp_v0_2 = M2C_FIELD(arg0, u32 *, 4);
    temp_s7 = 0x800 - ((s32) (temp_v1 + (temp_v1 >> 0x1F)) >> 1);
    temp_s6 = 0x800 - ((s32) (temp_v0_2 + (temp_v0_2 >> 0x1F)) >> 1);
    var_s4 = temp_s7;
    AllocStatic__4DMASiP2QW(sp, 0x40, &sp30, 0x800);
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    temp_v1_2 = M2C_FIELD(arg0, u32 *, 0);
    temp_v0_3 = ((s32) temp_v1_2 > 0x40) ? temp_v1_2 : 0x40U;
    PackAD__4GIFSll(sp, 0x4C, (temp_v0 >> 5) | ((s64) ((s32) (((s32) temp_v0_3 > -1) ? temp_v0_3 : (temp_v0_3 + 0x3F)) >> 6) << 0x10));
    PackAD__4GIFSll(sp, 0x4E, temp_s0 | 0x30000000);
    PackAD__4GIFSll(sp, 0x18, (temp_s7 * 0x10) | ((temp_s6 * 0x10) << 0x20));
    PackAD__4GIFSll(sp, 0x40, ((M2C_FIELD(arg0, u32 *, 0) - 1) << 0x10) | ((M2C_FIELD(arg0, u32 *, 4) - 1) << 0x30));
    PackAD__4GIFSll(sp, 0x47, 0x30000);
    PackAD__4GIFSll(sp, 1, 0);
    AddPrimPack__4GIFSiiUl(sp, 6, 1, 5);
    if (var_s4 < (var_s4 + M2C_FIELD(arg0, u32 *, 0))) {
        do {
            PackXYZ__4GIFSiii(sp, var_s4 * 0x10, temp_s6 * 0x10, 0);
            temp_v0_4 = var_s4 + 0x20;
            var_s4 = temp_v0_4;
            PackXYZ__4GIFSiii(sp, temp_v0_4 * 0x10, (temp_s6 + M2C_FIELD(arg0, u32 *, 4)) * 0x10, 0);
        } while (var_s4 < (temp_s7 + M2C_FIELD(arg0, u32 *, 0)));
    }
    AddPrimEnd__4GIFS(sp);
    DMAS_DetachCopyPermanent(sp, arg0 + 0x10, 0, arg0 + 0x14);
    AllocStatic__4DMASiP2QW(sp, 0x40, &sp30);
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    PackAD__4GIFSll(sp, 6, M2C_FIELD(arg0, s64 *, 8));
    PackAD__4GIFSll(sp, 0x14, 0x60);
    PackAD__4GIFSll(sp, 8, 5);
    AddPrimEnd__4GIFS(sp);
    DMAS_DetachCopyPermanent(sp, arg0 + 0x18, 0, arg0 + 0x1C);
}
}
