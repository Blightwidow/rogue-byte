typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSoBounds {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
M2C_UNK func_001F38A8(s8 *);                      /* extern */
M2C_UNK func_001F4BA8(s8 *, s8 *, M2C_UNK);     /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A2DE0;
extern M2C_UNK RO_002A2DF0;
extern M2C_UNK RO_002A2E00;
void UpdateSoBounds(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    f32 temp_a2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_v0_8;
    f32 var_f2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;
    s8 *temp_a1_3;
    s8 *temp_v0_4;
    s8 *temp_v0_7;
    s8 *var_s0;
    s8 *var_s0_2;
    asm volatile("lqc2 vf5, (%0)" : : "r"(&RO_002A2DF0));
    var_s0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 **, 0x34);
    asm volatile("lqc2 vf6, (%0)" : : "r"(&RO_002A2E00));
    if (var_s0 != NULL) {
        do {
            if (!(M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000L << 0x23))) {
                asm volatile("sqc2 vf5, 0x10(%0)" : : "r"(sp));
                asm volatile("sqc2 vf6, 0x20(%0)" : : "r"(sp));
                func_001F38A8(var_s0);
                asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
                asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(sp));
                if (M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000L << 0x22)) {
                    temp_f0 = M2C_FIELD(var_s0, f32 *, 8);
                    temp_v0 = M2C_FIELD(var_s0, s32 *, 0);
                    asm volatile("lqc2 vf3, (%0)" : : "r"(&RO_002A2DE0));
                    asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(temp_v0));
                    asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_f0));
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(-temp_f0));
                    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                    asm volatile("vadda.xyzw ACC, vf0, vf1");
                    asm volatile("vmaddx.xyzw vf1, vf3, vf2x");
                    asm volatile("vmini.xyz vf5, vf5, vf1");
                    asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(temp_v0));
                    asm volatile("vadda.xyzw ACC, vf0, vf2");
                    asm volatile("vmaddx.xyzw vf2, vf3, vf4x");
                    asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
                    asm volatile("vmax.xyz vf6, vf6, vf2");
                } else {
                    temp_v0_2 = M2C_FIELD(var_s0, s32 *, 0x90);
                    if (temp_v0_2 > 0) {
                        var_v0 = M2C_FIELD(var_s0, s32 *, 0x94);
                        var_a1 = temp_v0_2;
                        do {
                            asm volatile("lqc2 vf1, (%0)" : : "r"(var_v0));
                            var_a1 -= 1;
                            asm volatile("vmax.xyz vf6, vf6, vf1");
                            asm volatile("vmini.xyz vf5, vf5, vf1");
                            var_v0 += 0x10;
                        } while (var_a1 != 0);
                    }
                }
                if (M2C_FIELD(var_s0, s32 *, 0xA8) != M2C_FIELD(var_s0, s32 *, 0xAC)) {
                    temp_v0_3 = M2C_FIELD(var_s0, s32 *, 0x90);
                    temp_a1 = M2C_FIELD(var_s0, s32 *, 0x1C);
                    temp_v0_4 = var_s0 + 0x20;
                    if (temp_a1 < temp_v0_3) {
                        asm volatile("lqc2 vf7, 0x30(%0)" : : "r"(temp_v0_4));
                        asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(temp_v0_4));
                        var_v1 = (temp_a1 * 0x10) + M2C_FIELD(var_s0, s32 *, 0x7C);
                        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0_4));
                        var_a1_2 = temp_v0_3 - temp_a1;
                        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(var_s0));
                        asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1));
loop_11:
                        var_a1_2 -= 1;
                        asm volatile("vmulax.xyz ACC, vf2, vf1x");
                        asm volatile("vmadday.xyz ACC, vf4, vf1y");
                        asm volatile("vmaddaz.xyz ACC, vf3, vf1z");
                        asm volatile("vmaddw.xyz vf1, vf7, vf0w");
                        var_v1 += 0x10;
                        asm volatile("vmax.xyz vf6, vf6, vf1");
                        asm volatile("vmini.xyz vf5, vf5, vf1");
                        if (var_a1_2 != 0) {
                            asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1));
                            goto loop_11;
                        }
                    }
                }
            }
            var_s0 = M2C_FIELD(var_s0, s8 **, 0x60);
        } while (var_s0 != NULL);
    }
    asm volatile("sqc2 vf5, (%0)" : : "r"(M2C_FIELD(arg0, s8 **, 0xEC)));
    asm volatile("qmtc2.ni %0, vf1" : : "r"(0x3F000000));
    var_f2 = 0.0f;
    asm volatile("vmulax.xyzw ACC, vf5, vf1x");
    asm volatile("vmaddx.xyzw vf8, vf6, vf1x");
    asm volatile("sqc2 vf6, 0x10(%0)" : : "r"(M2C_FIELD(arg0, s8 **, 0xEC)));
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    var_s0_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 **, 0x34);
    asm volatile("vmove.xyzw vf9, vf8");
    if (var_s0_2 != NULL) {
        do {
            if (!(M2C_FIELD(var_s0_2, s64 *, 0x10) & (0x8000L << 0x22))) {
                temp_v0_5 = M2C_FIELD(var_s0_2, s32 *, 0x90);
                if (temp_v0_5 > 0) {
                    var_v0_2 = M2C_FIELD(var_s0_2, s32 *, 0x94);
                    asm volatile("vmove.xyzw vf3, vf8");
                    var_a1_3 = temp_v0_5;
                    do {
                        asm volatile("lqc2 vf1, (%0)" : : "r"(var_v0_2));
                        asm volatile("vsub.xyzw vf1, vf3, vf1");
                        asm volatile("vmul.xyz vf1, vf1, vf1");
                        asm volatile("vaddw.x vf2, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf2, vf1z");
                        asm volatile("vsqrt Q, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf1, vf0, Q");
                        s32 vu_1;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                        temp_a2 = vu_1;
                        if (var_f2 < temp_a2) {
                            var_f2 = temp_a2;
                        }
                        var_a1_3 -= 1;
                        var_v0_2 += 0x10;
                    } while (var_a1_3 != 0);
                }
            } else {
                asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(M2C_FIELD(var_s0_2, s32 *, 0)));
                asm volatile("vsub.xyzw vf1, vf9, vf1");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                temp_f0_2 = vu_2 + M2C_FIELD(var_s0_2, f32 *, 8);
                if (var_f2 < temp_f0_2) {
                    var_f2 = temp_f0_2;
                }
            }
            if (M2C_FIELD(var_s0_2, s32 *, 0xA8) != M2C_FIELD(var_s0_2, s32 *, 0xAC)) {
                temp_v0_6 = M2C_FIELD(var_s0_2, s32 *, 0x90);
                temp_a1_2 = M2C_FIELD(var_s0_2, s32 *, 0x1C);
                temp_v0_7 = var_s0_2 + 0x20;
                if (temp_a1_2 < temp_v0_6) {
                    asm volatile("lqc2 vf7, 0x30(%0)" : : "r"(temp_v0_7));
                    asm volatile("lqc2 vf6, 0x10(%0)" : : "r"(temp_v0_7));
                    var_v1_2 = (temp_a1_2 * 0x10) + M2C_FIELD(var_s0_2, s32 *, 0x7C);
                    asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(temp_v0_7));
                    var_a1_4 = temp_v0_6 - temp_a1_2;
                    asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(var_s0_2));
                    asm volatile("vmove.xyzw vf3, vf8");
                    do {
                        asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1_2));
                        asm volatile("vmulax.xyz ACC, vf4, vf1x");
                        asm volatile("vmadday.xyz ACC, vf6, vf1y");
                        asm volatile("vmaddaz.xyz ACC, vf5, vf1z");
                        asm volatile("vmaddw.xyz vf1, vf7, vf0w");
                        asm volatile("vsub.xyzw vf2, vf3, vf1");
                        asm volatile("vmul.xyz vf2, vf2, vf2");
                        asm volatile("vaddw.x vf1, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf2, vf2y");
                        asm volatile("vmaddz.x vf2, vf1, vf2z");
                        asm volatile("vsqrt Q, vf2x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf2, vf0, Q");
                        s32 vu_3;
                        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
                        temp_v0_8 = vu_3;
                        if (var_f2 < temp_v0_8) {
                            var_f2 = temp_v0_8;
                        }
                        var_a1_4 -= 1;
                        var_v1_2 += 0x10;
                    } while (var_a1_4 != 0);
                }
            }
            var_s0_2 = M2C_FIELD(var_s0_2, s8 **, 0x60);
        } while (var_s0_2 != NULL);
    }
    temp_a1_3 = M2C_FIELD(arg0, s8 **, 0xEC);
    asm volatile("sqc2 vf8, 0x20(%0)" : : "r"(temp_a1_3));
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), f32 *, 0x30) = var_f2;
    M2C_FIELD(&B_003DD490, s32 *, 0x3CCC) = 1;
    func_001F4BA8(arg0, temp_a1_3, 1);
}
}
