typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetupDraw__8CFontBrxP8CTextBoxP4GIFS {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
M2C_UNK AddPrimList__4GIFSiUl(s32, M2C_UNK, unsigned long); /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 FEnsureLoaded__8CFontBrxP4GIFS(s8 *, s32);    /* extern */
M2C_UNK PackAD__4GIFSll(s32, M2C_UNK, s64);         /* extern */
void SetupDraw__8CFontBrxP8CTextBoxP4GIFS(s8 *arg0, s8 *arg1, s32 arg2) {
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_s0;
    s64 temp_s2;
    s64 var_a2;
    if (arg1 != NULL) {
        temp_f2 = M2C_FIELD(arg1, f32 *, 0);
        temp_f3 = M2C_FIELD(arg1, f32 *, 4);
        temp_s3 = (s32) (temp_f2 * 0.8f);
        temp_s0 = (s32) ((temp_f2 + (M2C_FIELD(arg1, f32 *, 8) * 512.0f)) * 0.0015625f) - 1;
        temp_s1 = (s32) (temp_f3 * 0.45454547f);
        temp_s2 = (s32) ((temp_f3 + M2C_FIELD(arg1, f32 *, 0xC)) * 0.45454547f) - 1;
        AddPrimPack__4GIFSiiUl(arg2, 0, 1, 0xE);
        PackAD__4GIFSll(arg2, 0x40, temp_s3 | ((s64) temp_s0 << 0x10) | ((s64) temp_s1 << 0x20) | (temp_s2 << 0x30));
    }
    temp_s0_2 = FEnsureLoaded__8CFontBrxP4GIFS(arg0, arg2);
    AddPrimPack__4GIFSiiUl(arg2, 6, 1, 0xE);
    if (temp_s0_2 != 0) {
        PackAD__4GIFSll(arg2, 0x3F, 0);
    }
    var_a2 = 0x31001;
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        var_a2 = M2C_FIELD(arg0, s64 *, 0x40);
    }
    PackAD__4GIFSll(arg2, 0x47, var_a2);
    PackAD__4GIFSll(arg2, 0x42, 0x44);
    PackAD__4GIFSll(arg2, 6, M2C_FIELD(arg0, s64 *, 0x50));
    PackAD__4GIFSll(arg2, 0x14, 0x60);
    PackAD__4GIFSll(arg2, 8, 5);
    PackAD__4GIFSll(arg2, 0, 0x1D6);
    AddPrimList__4GIFSiUl(arg2, 5, 0x43431);
}
}
