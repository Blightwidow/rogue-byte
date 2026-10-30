typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefOpSetCarOrCdr {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK PairHandle_Assign(s32, s32);                /* extern */
M2C_UNK SetTag__4CRef4TAGK(s32, M2C_UNK);           /* extern */
M2C_UNK __as__4CRefRC4CRef(s32, s8 *);            /* extern */
s32 RefOpSetCarOrCdr(s32 arg0, s32 arg1, s8 *arg2, s32 arg3, s32 arg4) {
    s32 temp_a0;
    temp_a0 = M2C_FIELD(arg2, s32 *, 4);
    if (arg4 == 0x23) {
        __as__4CRefRC4CRef(temp_a0 + 8, arg2 + 8);
    } else if (M2C_FIELD(arg2, s32 *, 8) == 0x1F) {
        PairHandle_Assign(temp_a0 + 0x10, M2C_FIELD(arg2, s32 *, 0xC));
    } else {
        PairHandle_Assign(temp_a0 + 0x10, 0);
    }
    SetTag__4CRef4TAGK(arg0, 0x24);
    return arg0;
}
}
