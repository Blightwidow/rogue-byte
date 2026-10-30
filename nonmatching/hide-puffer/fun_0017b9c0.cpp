typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0017B9C0 {
    /* 0x000 */ f32 sp0;                            /* inferred */
    /* 0x004 */ f32 sp4;                            /* inferred */
    /* 0x008 */ f32 sp8;                            /* inferred */
    /* 0x00C */ f32 spC;                            /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ char pad30[0xE0];
};                                                  /* size = 0x110 */
#define sp0 (*(f32 *)(sp + 0x000))
#define sp20 (*(s128 *)(sp + 0x020))
M2C_UNK ClosestPointOnLine(M2C_UNK, s128, s128, M2C_UNK); /* extern */
f32 GRandInRange(f32, f32);                         /* extern */
s128 PosLoWorld(...);                       /* extern */
extern M2C_UNK D_FLT_002BE710;
extern M2C_UNK D_FLT_002BE720;
extern M2C_UNK D_FLT_002BE730;
extern M2C_UNK D_FLT_002BE740;
extern f32 g_2dded0;
void func_0017B9C0(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    f32 sp4;
    f32 sp8;
    f32 spC;
    s128 sp10;
    f32 temp_f20;
    f32 temp_v0;
    f32 var_f20;
    f32 var_f21;
    f32 var_f23;
    f32 var_f3;
    s32 var_a1;
    s32 var_s0;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s8 *temp_s0;
    s8 *temp_s2;
    s8 *var_fp;
    s8 *var_s3;
    s8 *var_v0_3;
    temp_f20 = g_2dded0;
    if (!(temp_f20 < M2C_FIELD(arg0, f32 *, 0x44))) {
        asm volatile("vsub.xyzw vf1, vf0, vf0");
        asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
        var_fp = NULL;
        M2C_FIELD(arg0, f32 *, 0x44) = (f32) (temp_f20 + GRandInRange(M2C_FIELD(&D_FLT_002BE710, f32 *, 0), M2C_FIELD(&D_FLT_002BE710, f32 *, 4)));
        sp10 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10));
        var_a1 = 0;
        var_f23 = 3.4028235e38f;
        if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xF94) > 0) {
            var_v1 = 0 * 4;
            do {
                temp_s2 = M2C_FIELD((M2C_FIELD(arg0, s8 **, 0x10) + var_v1), s8 **, 0xF98);
                if ((int)((u64) M2C_FIELD(temp_s2, u64 *, 0x28) >> 0x3C) & 1) {
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s2, var_a1)));
                    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                    asm volatile("vsub.xyzw vf1, vf2, vf3");
                    asm volatile("vmul.xyz vf1, vf1, vf1");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_1;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                    var_f20 = vu_1;
                    if (temp_s2 == M2C_FIELD(arg0, s8 **, 0x38)) {
                        var_f20 = M2C_FIELD(&D_FLT_002BE720, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002BE720, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002BE720, f32 *, 8))));
                    }
                    var_s0 = 0;
                    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xFA8) > 0) {
                        var_v0 = 0 * 4;
                        do {
                            asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(sp));
                            asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
                            s32 vu_2;
                            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
                            s64 vu_3;
                            asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(PosLoWorld(M2C_FIELD((M2C_FIELD(arg0, s8 **, 0x10) + var_v0), s8 **, 0xFAC))));
                            ClosestPointOnLine(vu_3, sp10, vu_2, 0);
                            asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
                            if (!(sp0 < 0.0f) && !(sp0 > 1.0f)) {
                                var_f3 = M2C_FIELD(&D_FLT_002BE730, f32 *, 0) + (sp4 * (M2C_FIELD(&D_FLT_002BE730, f32 *, 4) + (sp4 * M2C_FIELD(&D_FLT_002BE730, f32 *, 8))));
                                if (var_f3 < M2C_FIELD(&D_FLT_002BE740, f32 *, 0)) {
                                    var_f3 = M2C_FIELD(&D_FLT_002BE740, f32 *, 0);
                                } else if (M2C_FIELD(&D_FLT_002BE740, f32 *, 4) < var_f3) {
                                    var_f3 = M2C_FIELD(&D_FLT_002BE740, f32 *, 4);
                                }
                                var_f20 += var_f3;
                            }
                            var_s0 += 1;
                            var_v0 = var_s0 * 4;
                        } while (var_s0 < M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xFA8));
                    }
                    if (var_f20 < var_f23) {
                        asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
                        var_f23 = var_f20;
                        var_fp = temp_s2;
                    }
                }
                var_a1 += 1;
                var_v1 = var_a1 * 4;
            } while (var_a1 < M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xF94));
        }
        M2C_FIELD(arg0, s8 **, 0x38) = var_fp;
        var_s2 = 0;
        var_f21 = 800.0f;
        var_s3 = NULL;
        if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xFA8) > 0) {
            var_v0_2 = 0 * 4;
            do {
                temp_s0 = M2C_FIELD((M2C_FIELD(arg0, s8 **, 0x10) + var_v0_2), s8 **, 0xFAC);
                asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s0)));
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf1, vf3, vf2");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_4;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
                temp_v0 = vu_4;
                s32 vu_5;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_5));
                if (!(var_f21 < temp_v0) && ((var_fp == NULL) || ((ClosestPointOnLine(vu_5, sp10, sp20, 0), !(sp8 < 0.0f)) && !(sp8 > 1.0f) && !(spC > 500.0f)))) {
                    var_s3 = temp_s0;
                    var_f21 = temp_v0;
                }
                var_s2 += 1;
                var_v0_2 = var_s2 * 4;
            } while (var_s2 < M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xFA8));
        }
        var_v0_3 = var_s3;
        M2C_FIELD(arg0, s8 **, 0x3C) = var_s3;
        if (var_v0_3 == NULL) {
            var_v0_3 = M2C_FIELD(arg0, s8 **, 0x38);
        }
        M2C_FIELD(arg0, s8 **, 0x40) = var_v0_3;
    }
}
}
