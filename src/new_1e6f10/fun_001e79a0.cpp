typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *PattachCrv(s8 *, M2C_UNK);                          /* extern */

f32 func_001E79A0(s8 *arg0) {
    f32 result;
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
        { result = M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0xE8) * 4) + M2C_FIELD(PattachCrv(arg0, 0), s32 *, 0x5C)), f32 *, -4); goto done; }
    }
    { result = 0.0f; goto done; }
done:
    return result;
}

}
