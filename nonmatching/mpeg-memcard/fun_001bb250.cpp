typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001BB250 {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s32 FIsBasicDerivedFrom(s8 *, s32);
s32 FStgSwitchDone(s8 *);
void FreeSwMqList__FP2SWP2MQ(M2C_UNK *, s32);
void SetStgSwitchHitter(s8 *, s8 *, M2C_UNK);
void func_001F4F10();
extern M2C_UNK B_003DD490;
void func_001BB250(s8 *arg0) {
    s32 var_s0;
    s32 var_s1;
    s8 *temp_a2;
    s8 *temp_s0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *var_s2;
    func_001F4F10();
    if (FStgSwitchDone(arg0) == 0) {
        var_s2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 **, 0x64);
        if (var_s2 != NULL) {
            do {
                if (*M2C_FIELD(var_s2, s32 **, 8) != 0) {
                    var_s0 = 0;
                    if (M2C_FIELD(arg0, s32 *, 0x150) > 0) {
loop_5:
                        temp_v0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x154) + (var_s0 * 8));
                        if (M2C_FIELD(temp_v0, s32 *, 4) == 0) {
                            goto block_22;
                        }
                        if (FIsBasicDerivedFrom(M2C_FIELD(var_s2, s8 **, 0xC), M2C_FIELD(temp_v0, s32 *, 0)) == 0) {
block_22:
                            var_s0 += 1;
                            if (var_s0 < M2C_FIELD(arg0, s32 *, 0x150)) {
                                goto loop_5;
                            }
                        } else {
                            if (!(M2C_FIELD(arg0, s64 *, 0x148) & 0x03000000)) {
                                SetStgSwitchHitter(arg0, M2C_FIELD(var_s2, s8 **, 0xC), 0);
                            }
                            if (FIsBasicDerivedFrom(M2C_FIELD(var_s2, s8 **, 0xC), 0x62) != 0) {
                                temp_s0 = M2C_FIELD(var_s2, s8 **, 0xC);
                                var_s1 = 0;
loop_17:
                                if (var_s1 < M2C_FIELD(temp_s0, s32 *, 0x150)) {
                                    temp_v0_2 = (s8 *)(M2C_FIELD(temp_s0, s32 *, 0x154) + (var_s1 * 8));
                                    if ((M2C_FIELD(temp_v0_2, s32 *, 4) != 0) && (FIsBasicDerivedFrom(arg0, M2C_FIELD(temp_v0_2, s32 *, 0)) != 0)) {
                                        SetStgSwitchHitter(temp_s0, arg0, 0);
                                    } else {
                                        var_s1 += 1;
                                        goto loop_17;
                                    }
                                }
                            }
                            temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
                            M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *), 0x1B4)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x1B0), M2C_FIELD(var_s2, s8 **, 0xC));
                            temp_a2 = M2C_FIELD(var_s2, s8 **, 0xC);
                            temp_v0_4 = M2C_FIELD(temp_a2, s8 **, 0xC);
                            M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, s8 *, s8 *), 0x1B4)(temp_a2 + M2C_FIELD(temp_v0_4, s16 *, 0x1B0), arg0, temp_a2);
                            FreeSwMqList__FP2SWP2MQ(&B_003DD490, M2C_FIELD(var_s2, s32 *, 0));
                            *M2C_FIELD(var_s2, s32 **, 8) = 0;
                            M2C_FIELD(var_s2, s32 *, 0) = 0;
                        }
                    }
                }
                var_s2 = M2C_FIELD(var_s2, s8 **, 4);
            } while (var_s2 != NULL);
        }
    }
}
}
