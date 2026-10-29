typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FGoalAnimDone(s32);                             /* extern */
s32 func_001C1FA0(s8 *, s8 *, f32);         /* extern */

s32 func_0017EAE8(s8 *arg0) {
    if (!(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xFE8) & 1)) {
        goto block_7;
    }
    if (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
block_7:
        return func_001C1FA0(arg0 + 0x30, M2C_FIELD(arg0, s8 **, 0x10), 0x41C80000);
    }
    return 0;
}

}
