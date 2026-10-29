typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FIgnoreSoIntersection {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
s32 FIgnoreSoIntersection(s8 *arg0, s8 *arg1) {
    s32 var_v0;
    s8 *temp_v1;
    s8 *temp_v1_2;
    if ((!(M2C_FIELD(arg0, s64 *, 0x148) & 0x04000000) && (temp_v1 = M2C_FIELD(arg0, s8 **, 0xC), (M2C_FIELD(temp_v1, s32 (**)(s8 *, s8 *), 0x1F4)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x1F0), arg0) == 0))) || (temp_v1_2 = M2C_FIELD(arg1, s8 **, 0xC), var_v0 = 1, (M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0x1F4)(arg1 + M2C_FIELD(temp_v1_2, s16 *, 0x1F0)) == 0))) {
        var_v0 = 0;
    }
    return var_v0;
}
}
