typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 SMaxCrv(s8 *);                                /* extern */
f32 SMinCrv(s8 *);                                /* extern */

s32 func_001C3BB0(s8 *arg0, s8 *arg1) {
    s32 result;
    if (M2C_FIELD(arg0, s32 *, 0xE4) == 0) {
        { result = 0; goto done; }
    }
    M2C_FIELD(arg1, f32 *, 0) = SMinCrv(arg0);
    M2C_FIELD(arg1, f32 *, 4) = SMaxCrv(arg0);
    { result = 1; goto done; }
done:
    return result;
}

}
