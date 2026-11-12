typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack___ieee754_log {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
s64 __adddf3(...);                        /* extern */
s64 __floatsidf(s32);                               /* extern */
s64 __muldf3(...);                        /* extern */
s64 __subdf3(...);                        /* extern */
s32 dpcmp(s64, M2C_UNK);                            /* extern */
s64 func_0023DAB0(s64, s64);                        /* extern */
extern s64 RO_002AC1E8;
extern s64 RO_002AC1F0;
extern s64 RO_002AC1F8;
extern s64 RO_002AC200;
extern s64 RO_002AC208;
extern s64 RO_002AC210;
extern s64 RO_002AC218;
extern s64 RO_002AC220;
extern s64 RO_002AC228;
extern s64 RO_002AC230;
extern s64 RO_002AC238;
extern s64 RO_002AC240;
extern s64 RO_002AC248;
extern s64 RO_002AC250;
extern s64 RO_002AC258;
extern s64 RO_002AC260;
extern s64 RO_002AC268;
s64 __ieee754_log(s64 arg0) {
    s32 temp_fp;
    s32 temp_s3;
    s32 temp_s4;
    s32 var_fp;
    s64 temp_a2;
    s64 temp_s0;
    s64 temp_s0_2;
    s64 temp_s0_3;
    s64 temp_s0_4;
    s64 temp_s0_5;
    s64 temp_s0_6;
    s64 temp_s2;
    s64 temp_s2_2;
    s64 temp_s3_2;
    s64 temp_s5;
    s64 temp_s6;
    s64 temp_s7;
    s64 temp_v0;
    s64 temp_v0_2;
    s64 temp_v0_3;
    s64 temp_v0_4;
    s64 temp_v0_5;
    s64 var_a0;
    s64 var_a0_2;
    s64 var_a1;
    s64 var_a2;
    s64 var_s1;
    s64 var_s3;
    s64 var_v0;
    s64 var_v0_2;
    s64 var_v0_3;
    var_a2 = arg0;
    var_s3 = var_a2 >> 0x20;
    var_fp = 0;
    if (var_s3 <= 0xFFFFF) {
        if (((var_s3 & 0x7FFFFFFF) | ((s64) (var_a2 << 0x20) >> 0x20)) == 0) {
            return RO_002AC1E8;
        }
        if (var_s3 < 0) {
            return func_0023DAB0(__subdf3(var_a2, var_a2, var_a2), 0);
        }
        var_fp = -0x36;
        temp_v0_2 = __muldf3(var_a2, 0x86A0L << 0x2F, var_a2);
        var_a2 = temp_v0_2;
        var_s3 = temp_v0_2 >> 0x20;
        goto block_7;
    }
block_7:
    if (var_s3 > 0x7FEFFFFF) {
        return __adddf3(var_a2, var_a2, var_a2);
    }
    temp_s3 = var_s3 & 0xFFFFF;
    temp_s4 = (temp_s3 + 0x95F64) & 0x100000;
    temp_a2 = (var_a2 & (0xFFFF0000U >> 0x20)) | (((temp_s4 ^ 0x3FF00000) | temp_s3) << 0x20);
    temp_fp = var_fp - 0x3FF + (var_s3 >> 0x14) + (temp_s4 >> 0x14);
    temp_s5 = __subdf3(temp_a2, 0xFFC0L << 0x2E, temp_a2);
    if (((temp_s3 + 2) & 0xFFFFF) < 3) {
        if (dpcmp(temp_s5, 0) == 0) {
            var_v0 = 0;
            if (temp_fp != 0) {
                temp_v0 = __floatsidf(temp_fp);
                temp_s0 = __muldf3(temp_v0, RO_002AC1F0);
                return __adddf3(temp_s0, __muldf3(temp_v0, RO_002AC1F8));
            }
            /* Duplicate return node #27. Try simplifying control flow for better match */
            return var_v0;
        }
        temp_s0_2 = __muldf3(temp_s5, temp_s5);
        temp_s2 = __muldf3(temp_s0_2, __subdf3(0xFF80L << 0x2E, __muldf3(temp_s5, RO_002AC200)));
        if (temp_fp == 0) {
            var_a0 = temp_s5;
            var_a1 = temp_s2;
        } else {
            temp_v0_3 = __floatsidf(temp_fp);
            temp_s0_3 = __muldf3(temp_v0_3, RO_002AC208);
            var_v0_2 = __subdf3(__subdf3(temp_s2, __muldf3(temp_v0_3, RO_002AC210)), temp_s5);
            var_a0 = temp_s0_3;
            goto block_25;
        }
        goto block_26;
    }
    temp_s7 = func_0023DAB0(temp_s5, __adddf3(temp_s5, 0x8000L << 0x2F));
    temp_s6 = __floatsidf(temp_fp);
    temp_v0_4 = __muldf3(temp_s7, temp_s7);
    temp_v0_5 = __muldf3(temp_v0_4, temp_v0_4);
    temp_s0_4 = __muldf3(temp_v0_5, __adddf3(__muldf3(temp_v0_5, __adddf3(__muldf3(temp_v0_5, RO_002AC218), RO_002AC220)), RO_002AC228));
    temp_s2_2 = __adddf3(__muldf3(temp_v0_4, __adddf3(__muldf3(temp_v0_5, __adddf3(__muldf3(temp_v0_5, __adddf3(__muldf3(temp_v0_5, RO_002AC230), RO_002AC238)), RO_002AC240)), RO_002AC248)), temp_s0_4);
    if (((temp_s3 + 0xFFF9EB86) | (0x6B851 - temp_s3)) > 0) {
        temp_s3_2 = __muldf3(__muldf3(temp_s5, 0xFF80L << 0x2E), temp_s5);
        if (temp_fp == 0) {
            var_v0_2 = __subdf3(temp_s3_2, __muldf3(temp_s7, __adddf3(temp_s3_2, temp_s2_2)));
            var_a0 = temp_s5;
        } else {
            var_s1 = __muldf3(temp_s6, RO_002AC250);
            temp_s0_5 = __muldf3(temp_s7, __adddf3(temp_s3_2, temp_s2_2));
            var_v0_3 = __adddf3(temp_s0_5, __muldf3(temp_s6, RO_002AC258));
            var_a0_2 = temp_s3_2;
            goto block_24;
        }
    } else if (temp_fp == 0) {
        var_v0_2 = __muldf3(temp_s7, __subdf3(temp_s5, temp_s2_2));
        var_a0 = temp_s5;
    } else {
        var_s1 = __muldf3(temp_s6, RO_002AC260);
        temp_s0_6 = __muldf3(temp_s7, __subdf3(temp_s5, temp_s2_2));
        var_v0_3 = __muldf3(temp_s6, RO_002AC268);
        var_a0_2 = temp_s0_6;
block_24:
        var_v0_2 = __subdf3(__subdf3(var_a0_2, var_v0_3), temp_s5);
        var_a0 = var_s1;
    }
block_25:
    var_a1 = var_v0_2;
block_26:
    var_v0 = __subdf3(var_a0, var_a1);
    return var_v0;
}
}
