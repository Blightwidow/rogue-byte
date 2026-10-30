typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0017F1D0 {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s32 ApplyConstrLocal(s8 *, s32, M2C_UNK);         /* extern */
s32 LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32);  /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
extern s128 g_2a2da0;
extern M2C_UNK g_2a2dc0;
s32 func_0017F1D0(s8 *arg0, s8 *arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f20;
    s32 temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    if (!(M2C_FIELD(arg1, s32 *, 0x44) & 8)) {
        return 0;
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x184) + M2C_FIELD(arg1, s32 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0x184) = temp_v0;
    if (temp_v0 <= 0) {
        temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK), 0x294)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x290), 0);
    } else {
        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xE8);
        if (temp_v0_3 != NULL) {
            if (M2C_FIELD(temp_v0_3, s32 *, 0xC0) != 3) {
                asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(arg0)));
                asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(arg1));
                asm volatile("vsub.xyzw vf3, vf1, vf2");
                asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
                asm volatile("vmul.xyz vf2, vf3, vf1");
                asm volatile("vaddw.x vf4, vf0, vf0w");
                asm volatile("vadday.x ACC, vf2, vf2y");
                asm volatile("vmaddz.x vf2, vf4, vf2z");
                asm volatile("vmulx.xyzw vf2, vf1, vf2x");
                asm volatile("vsub.xyzw vf3, vf3, vf2");
                asm volatile("vmul.xyz vf1, vf3, vf3");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                if (vu_1 < 0.0001f) {
                    asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
                } else {
                    asm volatile("vdiv Q, vf0w, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf1, vf3, Q");
                }
                temp_v1 = arg0 + 0x1A0;
                asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                temp_f0 = (f32) -M2C_FIELD(arg1, s32 *, 0x10);
                temp_f4 = M2C_FIELD(arg0, f32 *, 0x1B0);
                temp_f3 = M2C_FIELD(arg0, f32 *, 0x1A0) + (temp_f0 * (M2C_FIELD(temp_v1, f32 *, 4) + (temp_f0 * M2C_FIELD(temp_v1, f32 *, 8))));
                temp_f5 = M2C_FIELD(arg0, f32 *, 0x1B4);
                if (temp_f3 < temp_f4) {
                    var_f20 = temp_f4;
                } else {
                    var_f20 = temp_f3;
                    if (temp_f5 < temp_f3) {
                        var_f20 = temp_f5;
                    }
                }
                temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x108))));
                asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f20));
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                asm volatile("vadda.xyzw ACC, vf0, vf2");
                asm volatile("vmaddx.xyzw vf2, vf3, vf1x");
                asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
                s64 vu_3;
                asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(LimitVectorLength__FP6VECTORfT0(vu_2, M2C_FIELD(arg0, f32 *, 0x1B4))));
                s64 vu_4;
                asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(ApplyConstrLocal(M2C_FIELD(arg0, s8 **, 0xE8) + 0xB0, M2C_FIELD(arg0, s32 *, 0x58), vu_3)));
                M2C_FIELD(temp_v1_3, M2C_UNK (**)(s8 *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x118), vu_4);
            }
        }
    }
    return 1;
}
}
