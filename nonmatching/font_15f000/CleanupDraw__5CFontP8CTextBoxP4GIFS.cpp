typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK AddPrimPack__4GIFSiiUl(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PackAD__4GIFSll(s32, M2C_UNK, s64);         /* extern */

void CleanupDraw__5CFontP8CTextBoxP4GIFS(s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        AddPrimPack__4GIFSiiUl(arg2, 0, 1, 0xE);
        PackAD__4GIFSll(arg2, 0x40, ((0xDF00L << 0x1F) | 0xFF80) << 9);
    }
}

}
