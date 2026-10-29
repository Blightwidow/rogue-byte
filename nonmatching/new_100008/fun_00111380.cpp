typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *__builtin_new(M2C_UNK);                       /* extern */
extern M2C_UNK D_002D9D90;
extern M2C_UNK D_002D9DD0;

s8 *func_00111380(void) {
    s8 *temp_v0;

    temp_v0 = __builtin_new(0x110);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002D9DD0;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x100) = &D_002D9D90;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    return temp_v0;
}

}
