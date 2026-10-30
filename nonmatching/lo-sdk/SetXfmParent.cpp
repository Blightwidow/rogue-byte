typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetXfmParent {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ s128 sp60;                           /* inferred */
    /* 0x70 */ s128 sp70;                           /* inferred */
    /* 0x80 */ char pad80[0x60];
};                                                  /* size = 0xE0 */
#define sp50 (*(s128 *)(sp + 0x50))
#define sp60 (*(s128 *)(sp + 0x60))
#define sp70 (*(s128 *)(sp + 0x70))
void SetLoParent(s8 *, s8 *, s8 *, s32);
s32 __ml__FRC7MATRIX4T0(s128 *, s8 *, s8 *);
void SetXfmParent(s8 *arg0, s8 *arg1, s8 *arg2, s32 arg3) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s128 sp30;
    s128 sp40;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    s8 *var_a1;
    s8 *var_s0;
    if (arg3 & 3) {
        if (!(((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1)) {
            var_s0 = M2C_FIELD(arg0, s8 **, 0x50);
            sp30 = M2C_FIELD(arg0, s128 *, 0x90);
            if (var_s0 != NULL) {
                var_a1 = var_s0;
                do {
                    __ml__FRC7MATRIX4T0(&sp40, var_a1, sp);
                    sp30 = sp70;
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0xA0);
                    var_a1 = var_s0;
                } while (var_s0 != NULL);
            }
        } else {
            temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
            sp30 = M2C_FIELD(M2C_FIELD(temp_v1, s8 *(**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8)), s128 *, 0x30);
        }
    }
    if (arg2 != NULL) {
        M2C_FIELD(arg0, s8 **, 0x50) = arg2;
    } else if (arg1 == NULL) {
        M2C_FIELD(arg0, s8 **, 0x50) = NULL;
    } else {
        M2C_FIELD(arg0, s8 **, 0x50) = (s8 *) M2C_FIELD(arg1, s8 **, 0x60);
    }
    SetLoParent(arg0, arg1, arg2, arg3);
    if (arg3 & 1) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s128), 0xEC)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xE8), sp30);
    }
    if (arg3 & 2) {
        temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *), 0xF4)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0xF0), sp);
    }
}
}
