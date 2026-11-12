typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00235930 {
    /* 0x00 */ char pad0[0x80];
};                                                  /* size = 0x80 */
s32 __fixunsdfdi(s32);                              /* extern */
s32 __muldf3(s32, s64);                             /* extern */
s32 __subdf3(M2C_UNK, s32);                         /* extern */
s32 dpcmp(s32, s64);                                /* extern */
M2C_UNK func_002358A0(s32);                         /* extern */
s32 func_002368C8(M2C_UNK (*)(s32, s32 *, M2C_UNK), s32, s32 *, M2C_UNK *); /* extern */
s32 func_0023DAB0(s32, s64);                        /* extern */
extern s64 RO_002AA828;
extern s64 RO_002AA830;
extern s64 RO_002AA838;
s32 func_00235930(M2C_UNK (*arg0)(s32, s32 *, M2C_UNK), s32 arg1, s32 *arg2, s32 arg3) {
    M2C_UNK *var_a3;
    s32 temp_s4;
    s32 var_s0;
    s32 var_s2;
    s32 var_s4;
    var_s4 = 0;
    var_s2 = 0;
    var_s0 = arg3;
    if (*arg2 == 0) {
        return 0;
    }
    if (dpcmp(var_s0, 0) < 0) {
        var_s4 = 1;
        var_s0 = __subdf3(0, var_s0);
        arg0(arg1, arg2, 0x2D);
        *arg2 -= 1;
    }
    if (dpcmp(var_s0, RO_002AA828) < 0) {
loop_7:
        if (dpcmp(var_s0, RO_002AA830) < 0) {
            var_s2 -= 1;
            var_s0 = __muldf3(var_s0, 0x8048 << 0x2F);
            goto loop_7;
        }
    } else if (dpcmp(var_s0, 0xFFC0 << 0x2E) >= 0) {
loop_13:
        if (dpcmp(var_s0, 0xFFC0 << 0x2E) >= 0) {
            var_s2 += 1;
            var_s0 = func_0023DAB0(var_s0, 0x8048 << 0x2F);
            goto loop_13;
        }
    }
    func_002358A0(__fixunsdfdi(__muldf3(var_s0, RO_002AA838)));
    temp_s4 = var_s4 + func_002368C8(arg0, arg1, arg2, (M2C_UNK *)("0.%d"));
    if (var_s2 >= 0) {
        var_a3 = (M2C_UNK *)("e+%d");
    } else {
        var_a3 = (M2C_UNK *)("e%d");
    }
    return temp_s4 + func_002368C8(arg0, arg1, arg2, var_a3);
}
}
