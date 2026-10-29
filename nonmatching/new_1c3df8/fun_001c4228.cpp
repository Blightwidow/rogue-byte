typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void func_001C4228(s8 *arg0, s32 arg1, s32 arg2) {
    s32 sp10;
    s32 sp14;
    s8 *temp_t2;

    temp_t2 = M2C_FIELD(arg0, s8 **, 0xC);
    sp10 = arg1;
    M2C_FIELD(temp_t2, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32 *, s32 *), 0x1C)(arg0 + M2C_FIELD(temp_t2, s16 *, 0x18), 0xC, 0, 2, &sp10, &sp14);
    sp14 = arg2;
}

}
