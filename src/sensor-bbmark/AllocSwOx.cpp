typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *PvAllocSlotheapImpl(s32);                     /* extern */

s8 *AllocSwOx(s32 arg0, s8 *arg1, s8 *arg2) {
    s8 *temp_v0;

    temp_v0 = PvAllocSlotheapImpl(arg0 + 0x3CF8);
    M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_FIELD(arg2, s32 *, 0x60);
    M2C_FIELD(temp_v0, s8 **, 4) = (s8 *) M2C_FIELD(arg1, s8 **, 0x64);
    M2C_FIELD(arg1, s8 **, 0x64) = temp_v0;
    return temp_v0;
}

}
