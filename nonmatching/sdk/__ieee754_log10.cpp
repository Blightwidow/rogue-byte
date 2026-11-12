typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack___ieee754_log10 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s64 __adddf3(s64, s64);                             /* extern */
s64 __floatsidf(s32);                               /* extern */
s64 __ieee754_log(s32);                             /* extern */
s64 __muldf3(s64, s64);                             /* extern */
s32 __subdf3(s64, s64);                             /* extern */
s64 func_0023DAB0(s32, M2C_UNK);                    /* extern */
extern s64 RO_002AB970;
extern s64 RO_002AB978;
extern s64 RO_002AB980;
extern s64 RO_002AB988;
s64 __ieee754_log10(s64 arg0) {
    s32 var_s2;
    s64 temp_s0;
    s64 temp_s0_2;
    s64 temp_s1;
    s64 temp_s2_2;
    s64 temp_v0;
    s64 var_a0;
    s64 var_a1;
    s64 var_s0;
    s64 var_s1;
    u32 temp_a0;
    u32 temp_s2;
    var_s1 = arg0;
    var_s0 = var_s1 >> 0x20;
    var_s2 = 0;
    if (var_s0 <= 0xFFFFF) {
        if (((var_s0 & 0x7FFFFFFF) | ((s64) (var_s1 << 0x20) >> 0x20)) == 0) {
            return RO_002AB970;
        }
        if (var_s0 < 0) {
            return func_0023DAB0(__subdf3(var_s1, var_s1), 0);
        }
        var_s2 = -0x36;
        temp_v0 = __muldf3(var_s1, 0x86A0L << 0x2F);
        var_s1 = temp_v0;
        var_s0 = temp_v0 >> 0x20;
        goto block_7;
    }
block_7:
    if (var_s0 > 0x7FEFFFFF) {
        var_a0 = var_s1;
        var_a1 = var_a0;
    } else {
        temp_s2 = var_s2 - 0x3FF + (var_s0 >> 0x14);
        temp_a0 = temp_s2 >> 0x1F;
        temp_s2_2 = __floatsidf(temp_s2 + temp_a0);
        temp_s1 = __ieee754_log((var_s1 & (0xFFFF0000U >> 0x20)) | (((var_s0 & 0xFFFFF) | ((0x3FF - temp_a0) << 0x14)) << 0x20));
        temp_s0 = __muldf3(temp_s2_2, RO_002AB978);
        temp_s0_2 = __adddf3(temp_s0, __muldf3(temp_s1, RO_002AB980));
        var_a0 = temp_s0_2;
        var_a1 = __muldf3(temp_s2_2, RO_002AB988);
    }
    return __adddf3(var_a0, var_a1);
}
}
