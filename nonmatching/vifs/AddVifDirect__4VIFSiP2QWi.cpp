typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK AddDmaBulk__4DMASiP2QW(s8 *, s32, s32);   /* extern */
M2C_UNK Align__4VIFSi(s8 *, M2C_UNK);                     /* extern */

void AddVifDirect__4VIFSiP2QWi(s8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_a1;

    Align__4VIFSi(arg0, 3);
    temp_a1 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_a1 + 4);
    *temp_a1 = arg1 | ((arg3 << 0x1F) | 0x50000000);
    AddDmaBulk__4DMASiP2QW(arg0, arg1, arg2);
}

}
