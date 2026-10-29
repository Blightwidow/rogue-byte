typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PvAllocSlotheapClearImpl__FP8SLOTHEAP {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
void memset(s32, M2C_UNK, s32);                  /* extern */
s32 PvAllocSlotheapClearImpl__FP8SLOTHEAP(s8 *arg0, s32 arg1) {
    s32 temp_v0;
    s8 *temp_a3;
    temp_v0 = M2C_FIELD(temp_a3, s32 (**)(s8 *), 0xC)(arg0 + M2C_FIELD(temp_a3, s16 *, 8));
    temp_a3 = *(s8 **)arg0;
    memset(temp_v0, 0, arg1);
    return temp_v0;
}
}
