typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_logf {
    /* 0x00 */ char pad0[0x18];
    /* 0x18 */ s64 sp18;                            /* inferred */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0x6C];
};                                                  /* size = 0x90 */
s64 __ieee754_log10();                              /* extern */
s64 __subdf3(M2C_UNK, s64);                         /* extern */
s32 dpcmp(s64, M2C_UNK);                            /* extern */
s32 *func_002401C8();                               /* extern */
s32 func_00249C80(s64);                             /* extern */
s32 matherr(s8 *);                                /* extern */
extern s64 RO_002AB8C8;
extern s64 RO_002AC130;
extern s32 RO_002AC138;
s64 logf(s64 arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s64 sp18;
    s32 sp20;
    s32 *var_v0_3;
    s32 temp_s2;
    s32 var_v1;
    s64 temp_v0;
    s64 var_v0;
    s64 var_v0_2;
    temp_v0 = __ieee754_log10();
    temp_s2 = RO_002AC138;
    var_v0 = temp_v0;
    if (temp_s2 != -1) {
        var_v0 = temp_v0;
        if (func_00249C80(arg0) == 0) {
            var_v0 = temp_v0;
            if (dpcmp(arg0, 0) <= 0) {
                sp20 = 0;
                if (temp_s2 == 0) {
                    var_v0_2 = RO_002AB8C8;
                } else {
                    var_v0_2 = __subdf3(0, RO_002AC130);
                }
                sp18 = var_v0_2;
                if (dpcmp(arg0, 0) == 0) {
                    if (RO_002AC138 == 2) {
                        var_v0_3 = func_002401C8();
                        var_v1 = 0x22;
                        goto block_12;
                    }
                    goto block_10;
                }
                if (RO_002AC138 != 2) {
block_10:
                    if (matherr(sp) == 0) {
                        goto block_11;
                    }
                } else {
block_11:
                    var_v0_3 = func_002401C8();
                    var_v1 = 0x21;
block_12:
                    *var_v0_3 = var_v1;
                }
                if (sp20 != 0) {
                    *func_002401C8() = sp20;
                }
                var_v0 = sp18;
            }
        }
    }
    return var_v0;
}
}
