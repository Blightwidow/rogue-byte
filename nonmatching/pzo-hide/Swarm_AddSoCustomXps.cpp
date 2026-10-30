typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Swarm_AddSoCustomXps {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x018 */ s32 sp18;                           /* overlap; inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x028 */ f32 sp28;                           /* overlap; inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0xD0];
    /* 0x110 */ M2C_UNK sp110;                      /* inferred */
    /* 0x110 */ char pad110[0x10];
    /* 0x120 */ M2C_UNK sp120;                      /* inferred */
    /* 0x120 */ char pad120[0x10];
    /* 0x130 */ s128 sp130;                         /* inferred */
    /* 0x140 */ s128 sp140;                         /* inferred */
    /* 0x150 */ char pad150[0xD0];
};                                                  /* size = 0x220 */
#define sp20 (*(s128 *)(sp + 0x020))
#define sp140 (*(s128 *)(sp + 0x140))
s32 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(s128, s128, s128, M2C_UNK, f32);
void PxpAdd(M2C_UNK *, s32, s8 *, s128, f32);
void func_001F5990();
s32 func_002564B8(M2C_UNK *);
extern M2C_UNK B_003DD490;
extern s128 g_2a2da0;
void Swarm_AddSoCustomXps(s8 *arg0, s8 *arg1) {
    s32 unksp38;
    s8 sp[0x160] __attribute__((aligned(16)));
    s128 sp10;
    s32 sp18;
    f32 sp28;
    s128 sp30;
    M2C_UNK sp40;
    M2C_UNK sp110;
    M2C_UNK sp120;
    s128 sp130;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_v0_2;
    f32 var_f12;
    s128 var_a3;
    s32 temp_a0;
    s32 var_a0;
    s32 var_a1;
    s32 var_s0;
    s8 *temp_s2;
    s8 *temp_v0;
    s8 *var_s3;
    func_001F5990();
    if (M2C_FIELD(arg1, s64 *, 0x10) & (0x8000L << 0x22)) {
        var_a0 = 0;
        sp130 = M2C_FIELD(M2C_FIELD(arg1, s8 **, 0), s128 *, 0x70);
        if (M2C_FIELD(arg0, s32 *, 0x1C8) > 0) {
            do {
                temp_v0 = arg0 + ((var_a0 * 0x30) + 0x1CC);
                var_s3 = M2C_FIELD(temp_v0, s8 **, 0x10);
                temp_f20 = M2C_FIELD(arg1, f32 *, 8) + M2C_FIELD(temp_v0, f32 *, 0x20);
                if (var_s3 != NULL) {
                    do {
                        asm volatile("lqc2 vf1, (%0)" : : "r"(var_s3));
                        asm volatile("lqc2 vf2, 0x130(%0)" : : "r"(sp));
                        asm volatile("vsub.xyzw vf1, vf1, vf2");
                        asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                        sp18 = 0;
                        asm volatile("qmtc2.ni %0, vf3" : : "r"(sp10));
                        asm volatile("vmul.xyz vf1, vf3, vf3");
                        asm volatile("vaddw.x vf2, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf2, vf1z");
                        asm volatile("vsqrt Q, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf2, vf0, Q");
                        s32 vu_1;
                        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
                        if (vu_1 < 0.0001f) {
                            sp10 = g_2a2da0;
                        } else {
                            asm volatile("vdiv Q, vf0w, vf2x");
                            asm volatile("vwaitq");
                            asm volatile("vmulq.xyzw vf1, vf3, Q");
                            asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                        }
                        s32 vu_2;
                        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
                        temp_v0_2 = vu_2;
                        if (temp_v0_2 < temp_f20) {
                            var_f12 = temp_v0_2 - temp_f20;
                            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                            asm volatile("lqc2 vf3, 0x130(%0)" : : "r"(sp));
                            s32 vu_3;
                            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
                            vu_3;
                            asm volatile("qmtc2.ni %0, vf1" : : "r"(-M2C_FIELD(arg1, f32 *, 8)));
                            asm volatile("vadda.xyzw ACC, vf0, vf3");
                            asm volatile("vmaddx.xyzw vf3, vf2, vf1x");
                            s32 vu_4;
                            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_4));
                            var_a3 = vu_4;
                            var_a1 = M2C_FIELD(arg0, s32 *, 0xE4) + ((M2C_FIELD(arg0, s32 *, 0xE0) * 0xB0) - 0xB0);
                            asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
                            goto block_11;
                        }
                        var_s0 = M2C_FIELD(arg1, s32 *, 0x1C);
                        if (var_s0 < M2C_FIELD(arg1, s32 *, 0x90)) {
                            temp_s2 = arg1 + 0x20;
loop_14:
                            temp_a0 = var_s0 * 0x10;
                            asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(temp_s2));
                            asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(temp_s2));
                            asm volatile("lqc2 vf3, (%0)" : : "r"(temp_a0 + M2C_FIELD(arg1, s32 *, 0x7C)));
                            asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(temp_s2));
                            asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg1));
                            asm volatile("vmulax.xyz ACC, vf1, vf3x");
                            asm volatile("vmadday.xyz ACC, vf5, vf3y");
                            asm volatile("vmaddaz.xyz ACC, vf4, vf3z");
                            asm volatile("vmaddw.xyz vf1, vf2, vf0w");
                            asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
                            sp30 = *(s32 *)(temp_a0 + M2C_FIELD(arg1, s32 *, 0x94));
                            temp_f0 = M2C_FIELD(var_s3, f32 *, 8);
                            sp28 = temp_f0;
                            unksp38 = temp_f0;
                            var_s0 += 1;
                            if (ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_FIELD(var_s3, s128 *, 0), sp20, sp30, 2, temp_f20) <= 0) {
                                if (var_s0 < M2C_FIELD(arg1, s32 *, 0x90)) {
                                    goto loop_14;
                                }
                            } else {
                                asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
                                asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
                                asm volatile("qmtc2.ni %0, vf1" : : "r"(M2C_FIELD(arg1, f32 *, 8)));
                                asm volatile("vadda.xyzw ACC, vf0, vf2");
                                asm volatile("vmaddx.xyzw vf4, vf3, vf1x");
                                asm volatile("sqc2 vf1, 0x100(%0)" : : "r"(sp));
                                asm volatile("sqc2 vf3, 0x160(%0)" : : "r"(sp));
                                asm volatile("sqc2 vf2, 0x150(%0)" : : "r"(sp));
                                asm volatile("sqc2 vf4, 0x140(%0)" : : "r"(sp));
                                func_002564B8(&sp110);
                                func_002564B8(&sp120);
                                asm volatile("lqc2 vf3, 0x160(%0)" : : "r"(sp));
                                asm volatile("lqc2 vf2, 0x150(%0)" : : "r"(sp));
                                asm volatile("vmul.xyz vf2, vf3, vf2");
                                asm volatile("vaddw.x vf1, vf0, vf0w");
                                asm volatile("vadday.x ACC, vf2, vf2y");
                                asm volatile("vmaddaz.x ACC, vf1, vf2z");
                                asm volatile("vmsubw.x vf2, vf1, vf3w");
                                var_a3 = sp140;
                                s32 vu_5;
                                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_5));
                                vu_5;
                                s32 vu_6;
                                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_6));
                                var_f12 = vu_6 - M2C_FIELD(arg1, f32 *, 8);
                                asm volatile("sqc2 vf1, 0x120(%0)" : : "r"(sp));
                                asm volatile("sqc2 vf2, 0x110(%0)" : : "r"(sp));
                                var_a1 = M2C_FIELD(arg0, s32 *, 0xE4) + ((M2C_FIELD(arg0, s32 *, 0xE0) * 0xB0) - 0xB0);
block_11:
                                PxpAdd(&B_003DD490, var_a1, arg1, var_a3, var_f12);
                            }
                        }
                        var_s3 = M2C_FIELD(var_s3, s8 **, 0x60);
                    } while (var_s3 != NULL);
                }
                var_a0 += 1;
            } while (var_a0 < M2C_FIELD(arg0, s32 *, 0x1C8));
        }
    }
}
}
