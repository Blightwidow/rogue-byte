typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RecalcSwXpAll {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s8 *sp10[];                       /* inferred */
    /* 0x010 */ char pad10[0xC90];
};                                                  /* size = 0xCA0 */
#define sp10 ((s8 * *)(sp + 0x010))
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
M2C_UNK FreeSwMqList__FP2SWP2MQ(s8 *, s32);       /* extern */
s32 PxpMarkSwContactsRoot(s8 *, s8 *, s8 *);  /* extern */
M2C_UNK RemoveDlEntry(s8 *, s8 *);              /* extern */
M2C_UNK UpdateSwAaox__FP2SW(s8 *);                /* extern */
M2C_UNK func_00133E30();                            /* extern */
M2C_UNK func_001F5078(s8 *);                      /* extern */
void RecalcSwXpAll(s8 *arg0) {
    s8 sp[0xCA0] __attribute__((aligned(16)));
    s16 temp_a1;
    s16 temp_a1_2;
    s32 temp_s0;
    s32 temp_v0_3;
    s32 var_s2;
    s32 var_s6;
    s64 temp_v1;
    s64 temp_v1_2;
    s64 temp_v1_3;
    s8 **var_s0;
    s8 **var_s5;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a1_3;
    s8 *temp_a1_4;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a2_3;
    s8 *temp_s2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_4;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    s8 *temp_v1_7;
    s8 *var_s1;
    s8 *var_s1_2;
    s8 *var_s3;
    var_s6 = 0;
    func_00133E30();
    UpdateSwAaox__FP2SW(arg0);
    CStackFrame_Construct(sp);
    var_s1 = M2C_FIELD(arg0, s8 **, 0x3D34);
    if (var_s1 != NULL) {
        do {
            temp_v1 = M2C_FIELD(var_s1, s64 *, 0x70);
            if (!(temp_v1 & 4)) {
                temp_v1_2 = temp_v1 | 0x10;
                M2C_FIELD(var_s1, s64 *, 0x70) = temp_v1_2;
                if (!(temp_v1_2 & 8)) {
                    M2C_FIELD(var_s1, s64 *, 0x70) = (s64) (temp_v1_2 | 8);
                    (&sp10[0])[var_s6] = var_s1;
                    var_s6 += 1;
                }
                var_s3 = M2C_FIELD(var_s1, s8 **, 0x64);
                if (var_s3 != NULL) {
                    var_s5 = &(&sp10[0])[var_s6];
                    do {
                        temp_s2 = M2C_FIELD(M2C_FIELD(var_s3, s8 **, 0xC), s8 **, 0xEC);
                        temp_v1_3 = M2C_FIELD(temp_s2, s64 *, 0x70);
                        if (!(temp_v1_3 & 0x10) && !(temp_v1_3 & 4)) {
                            if (!(temp_v1_3 & 8)) {
                                var_s6 += 1;
                                M2C_FIELD(temp_s2, s64 *, 0x70) = (s64) (temp_v1_3 | 8);
                                *var_s5 = temp_s2;
                                var_s5 += 4;
                            }
                            temp_a2 = M2C_FIELD(var_s1, s8 **, 0x60);
                            temp_v0 = M2C_FIELD(temp_a2, s8 **, 0xC);
                            M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *, s8 *), 0x1B4)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x1B0), M2C_FIELD(temp_s2, s8 **, 0x60), temp_a2);
                            temp_a2_2 = M2C_FIELD(temp_s2, s8 **, 0x60);
                            temp_v0_2 = M2C_FIELD(temp_a2_2, s8 **, 0xC);
                            M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *, s8 *), 0x1B4)(temp_a2_2 + M2C_FIELD(temp_v0_2, s16 *, 0x1B0), M2C_FIELD(var_s1, s8 **, 0x60), temp_a2_2);
                            temp_s0 = M2C_FIELD(var_s3, s32 *, 0);
                            FreeSwMqList__FP2SWP2MQ(arg0, temp_s0);
                            temp_v0_3 = PxpMarkSwContactsRoot(arg0, var_s1, temp_s2);
                            M2C_FIELD(var_s3, s32 *, 0) = temp_v0_3;
                            *M2C_FIELD(var_s3, s32 **, 8) = temp_v0_3;
                            if ((temp_s0 != 0) || (M2C_FIELD(var_s3, s32 *, 0) != 0)) {
                                temp_a0 = M2C_FIELD(var_s1, s8 **, 0x60);
                                temp_v1_4 = M2C_FIELD(temp_a0, s8 **, 0xC);
                                temp_a1 = M2C_FIELD(temp_v1_4, s16 *, 0x1F0);
                                if (M2C_FIELD(temp_v1_4, s32 (**)(s8 *, s16), 0x1F4)(temp_a0 + temp_a1, temp_a1) == 0) {
                                    func_001F5078(M2C_FIELD(var_s1, s8 **, 0x60));
                                }
                                temp_a0_2 = M2C_FIELD(temp_s2, s8 **, 0x60);
                                temp_v1_5 = M2C_FIELD(temp_a0_2, s8 **, 0xC);
                                temp_a1_2 = M2C_FIELD(temp_v1_5, s16 *, 0x1F0);
                                if (M2C_FIELD(temp_v1_5, s32 (**)(s8 *, s16), 0x1F4)(temp_a0_2 + temp_a1_2, temp_a1_2) == 0) {
                                    func_001F5078(M2C_FIELD(temp_s2, s8 **, 0x60));
                                }
                            }
                        }
                        var_s3 = M2C_FIELD(var_s3, s8 **, 4);
                    } while (var_s3 != NULL);
                }
            }
            var_s1 = M2C_FIELD(var_s1, s8 **, 0x58);
        } while (var_s1 != NULL);
        if (M2C_FIELD(arg0, s8 **, 0x3D34) != NULL) {
            do {
                temp_a2_3 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x3D34), s8 **, 0x60);
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x3D34), s64 *, 0x70) = (s64) (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x3D34), s64 *, 0x70) & ~0x10);
                temp_v1_6 = M2C_FIELD(temp_a2_3, s8 **, 0xC);
                M2C_FIELD(temp_v1_6, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x1B4)(temp_a2_3 + M2C_FIELD(temp_v1_6, s16 *, 0x1B0), 0, temp_a2_3);
                FreeSwMqList__FP2SWP2MQ(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x3D34), s32 *, 0x68));
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x3D34), s32 *, 0x68) = 0;
                temp_a1_3 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x3D34), s8 **, 0x60);
                temp_v0_4 = M2C_FIELD(temp_a1_3, s8 **, 0xC);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, s8 *), 0x1DC)(temp_a1_3 + M2C_FIELD(temp_v0_4, s16 *, 0x1D8), temp_a1_3);
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x3D34), s64 *, 0x70) = (s64) (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x3D34), s64 *, 0x70) & ~2);
                RemoveDlEntry(arg0 + 0x3D34, M2C_FIELD(arg0, s8 **, 0x3D34));
            } while (M2C_FIELD(arg0, s8 **, 0x3D34) != NULL);
        }
    }
    var_s2 = var_s6;
    if (var_s6 > 0) {
        var_s0 = &sp10[0];
        var_s1_2 = *var_s0;
loop_24:
        var_s2 -= 1;
        var_s0 += 4;
        temp_a1_4 = M2C_FIELD(var_s1_2, s8 **, 0x60);
        M2C_FIELD(var_s1_2, s64 *, 0x70) = (s64) (M2C_FIELD(var_s1_2, s64 *, 0x70) & ~8);
        temp_v1_7 = M2C_FIELD(temp_a1_4, s8 **, 0xC);
        M2C_FIELD(temp_v1_7, M2C_UNK (**)(s8 *, s8 *), 0x1D4)(temp_a1_4 + M2C_FIELD(temp_v1_7, s16 *, 0x1D0), temp_a1_4);
        if (var_s2 != 0) {
            var_s1_2 = *var_s0;
            goto loop_24;
        }
    }
    CStackFrame_Destructor(sp, 2);
}
}
