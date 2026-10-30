typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ChooseSmaTransition {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
M2C_UNK ApplyAseg(s8 *, s32, s32, s8 *, f32, f32); /* extern */
s32 FSmaRetracted(...);                          /* extern */
M2C_UNK NotifySmaSpliceOnEnterState(s8 *, s32, s32); /* extern */
s8 *PsmtChooseSmAny(s8 *, s32, s32, M2C_UNK);   /* extern */
s8 *PsmtChooseSmTowards(s8 *, s32, s32, s32);   /* extern */
M2C_UNK RetractAsega(s32);                          /* extern */
M2C_UNK SubscribeLoObject(s32, s8 *);             /* extern */
void ChooseSmaTransition(s8 *arg0, s32 arg1) {
    f32 var_f12;
    f32 var_f13;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    s8 *temp_a0;
    s8 *var_s0;
    var_s3 = arg1;
    if (FSmaRetracted() == 0) {
loop_32:
        temp_a2 = M2C_FIELD(arg0, s32 *, 0x34);
        temp_a3 = M2C_FIELD(arg0, s32 *, 0x3C);
        if (temp_a2 != temp_a3) {
            var_s0 = PsmtChooseSmTowards(M2C_FIELD(arg0, s8 **, 0x24), M2C_FIELD(arg0, s32 *, 0x48), temp_a2, temp_a3);
            goto block_9;
        }
        temp_a0 = M2C_FIELD(arg0, s8 **, 0x24);
        temp_v0 = M2C_FIELD((M2C_FIELD(temp_a0, s32 *, 0x54) + (temp_a2 * 8)), s32 *, 4);
        if (temp_v0 == -1) {
        } else {
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x48);
            if (temp_v0 == -2) {
                var_s0 = PsmtChooseSmAny(temp_a0, temp_a1, temp_a2, 0);
                var_s3 = 0;
                if (var_s0 != NULL) {
                    temp_v0_2 = M2C_FIELD(var_s0, s32 *, 4);
                    var_a0 = temp_v0_2;
                    if (temp_v0_2 == M2C_FIELD(arg0, s32 *, 0x34)) {
                        var_a0 = M2C_FIELD(var_s0, s32 *, 8);
                    }
                    M2C_FIELD(arg0, s32 *, 0x3C) = var_a0;
                    goto block_8;
                }
            } else {
                M2C_FIELD(arg0, s32 *, 0x3C) = temp_v0;
                var_s0 = PsmtChooseSmTowards(temp_a0, temp_a1, temp_a2, temp_v0);
block_8:
                var_s3 = 0;
            }
block_9:
            M2C_FIELD(arg0, s8 **, 0x40) = var_s0;
            if (var_s0 != NULL) {
                var_s1 = 0;
                if (M2C_FIELD(var_s0, s8 **, 0) != NULL) {
                    temp_v1 = M2C_FIELD(var_s0, s32 *, 4);
                    if (temp_v1 != M2C_FIELD(arg0, s32 *, 0x34)) {
                        M2C_FIELD(arg0, s32 *, 0x38) = temp_v1;
                        var_f13 = -M2C_FIELD(arg0, f32 *, 0x44);
                        var_f12 = M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0), f32 *, 0x74);
                    } else {
                        var_f12 = 0.0f;
                        M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(var_s0, s32 *, 8);
                        var_f13 = M2C_FIELD(arg0, f32 *, 0x44);
                    }
                    var_a2 = M2C_FIELD(arg0, s32 *, 0x2C);
                    if (var_s3 == 1) {
                        var_a2 = (var_a2 | 2) & ~1;
                        var_s1 = 1;
                        var_f12 = M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0), f32 *, 0x74) - var_f12;
                    } else if (M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0), f32 *, 0x74) == 0.0f) {
                        var_s1 = 1;
                    }
                    ApplyAseg(M2C_FIELD(var_s0, s8 **, 0), M2C_FIELD(arg0, s32 *, 0x28), var_a2, arg0 + 0x30, var_f12, var_f13);
                }
                temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x30);
                if (temp_a0_2 == 0) {
                    var_a1 = M2C_FIELD(arg0, s32 *, 0x34);
                    var_v0 = M2C_FIELD(var_s0, s32 *, 4);
                    if (var_v0 == var_a1) {
                        var_v0 = M2C_FIELD(var_s0, s32 *, 8);
                    }
                    var_a2_2 = var_v0;
                    M2C_FIELD(arg0, s32 *, 0x34) = var_v0;
                    goto block_30;
                }
                if (var_s1 != 0) {
                    temp_s1 = M2C_FIELD(arg0, s32 *, 0x38);
                    temp_s0 = M2C_FIELD(arg0, s32 *, 0x34);
                    M2C_FIELD(arg0, s32 *, 0x34) = temp_s1;
                    M2C_FIELD(arg0, s32 *, 0x38) = -1;
                    RetractAsega(temp_a0_2);
                    M2C_FIELD(arg0, s32 *, 0x30) = 0;
                    var_a1 = temp_s0;
                    var_a2_2 = temp_s1;
block_30:
                    NotifySmaSpliceOnEnterState(arg0, var_a1, var_a2_2);
                    if (FSmaRetracted(arg0) == 0) {
                        if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
                            goto loop_32;
                        }
                    }
                } else {
                    SubscribeLoObject(temp_a0_2, arg0);
                }
            }
        }
    }
}
}
