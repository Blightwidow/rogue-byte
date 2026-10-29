typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_HandleBombMessage__FP4BOMB5MSGIDPv {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
void HandleLoMessage();
f32 PrimeBomb__FP4BOMBf(s8 *, M2C_UNK);
void HandleBombMessage__FP4BOMB5MSGIDPv(s32 arg0, s32 arg1, s8 *arg2) {
    s8 *temp_a0;
    HandleLoMessage();
    if (arg1 == 4) {
        temp_a0 = M2C_FIELD(arg2, s8 **, 4);
        if (((s32)temp_a0 == arg0) && (M2C_FIELD(temp_a0, s32 *, 0x150) == 0)) {
            PrimeBomb__FP4BOMBf(temp_a0, 0);
        }
    }
}
}
