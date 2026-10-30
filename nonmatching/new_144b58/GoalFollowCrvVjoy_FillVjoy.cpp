typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GoalFollowCrvVjoy_FillVjoy {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
M2C_UNK Goal_FillVjoy();                            /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK UpdateVjoyPressTimes(s8 *, s8 *, s32);  /* extern */
f32 atan2f(M2C_UNK *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK D_FLT_002BD2E0;
extern f32 D_FLT_002BD2F0;
extern M2C_UNK g_2a2dc0;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded0;
void GoalFollowCrvVjoy_FillVjoy(s8 *arg0, s8 *arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    M2C_UNK temp_f12;
    M2C_UNK temp_v0;
    f32 temp_f0;
    f32 temp_v1_2;
    f32 var_f3;
    s32 temp_a2;
    s32 temp_v1;
    s32 var_s3;
    s32 var_v0;
    s8 *temp_a1;
    s8 *temp_s1;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    Goal_FillVjoy();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x4C);
    if ((temp_v1 < 2) && (temp_v1 >= 0)) {
        asm volatile("lqc2 vf3, 0x80(%0)" : : "r"(arg0));
        asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10))));
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf3, vf3, vf1");
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("vmul.xyz vf2, vf3, vf1");
        asm volatile("vaddw.x vf4, vf0, vf0w");
        asm volatile("vadday.x ACC, vf2, vf2y");
        asm volatile("vmaddz.x vf2, vf4, vf2z");
        asm volatile("vmulx.xyzw vf2, vf1, vf2x");
        asm volatile("vsub.xyzw vf2, vf3, vf2");
        asm volatile("vmul.xy vf1, vf2, vf2");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_v1_2 = vu_1;
        temp_f0 = M2C_FIELD(&D_FLT_002BD2E0, f32 *, 0) + (temp_v1_2 * (M2C_FIELD(&D_FLT_002BD2E0, f32 *, 4) + (temp_v1_2 * M2C_FIELD(&D_FLT_002BD2E0, f32 *, 8))));
        if (temp_f0 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f3 = temp_f0;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f0) {
                var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
        temp_v0 = vu_2;
        if (var_f3 > 0.0f) {
            s64 vu_3;
            asm volatile("prot3w %0, %0" : "=r"(vu_3) : "r"(temp_v0));
            temp_f12 = vu_3;
            M2C_FIELD(arg1, f32 *, 0x1C) = (f32) (var_f3 * M2C_FIELD(arg0, f32 *, 0xD0));
            M2C_FIELD(arg1, f32 *, 0x18) = atan2f(&D_FLT_002BD2E0, temp_f12, temp_v0);
        }
        if (M2C_FIELD(arg0, s32 *, 0xCC) != 0) {
            M2C_FIELD(arg1, s32 *, 0x30) = (s32) (M2C_FIELD(arg1, s32 *, 0x30) | 8);
        }
        temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC0);
        if (temp_v1_3 != NULL) {
            var_s3 = 1;
            if (M2C_FIELD(arg0, f32 *, 0xC8) < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x50))) {
                temp_s1 = M2C_FIELD(temp_v1_3, s8 **, 0x7C);
                asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10))));
                asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(temp_s1)));
                asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf1, vf1, vf2");
                asm volatile("vmul.xy vf1, vf1, vf1");
                asm volatile("vaddy.x vf1, vf1, vf1y");
                var_v0 = 1;
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_4;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
                if (!(D_FLT_002BD2F0 < vu_4)) {
                    var_v0 = 0;
                }
                if (var_v0 != 0) {
                    M2C_FIELD(arg1, s32 *, 0x30) = (s32) (M2C_FIELD(arg1, s32 *, 0x30) | 8);
                }
                if (FIsBasicDerivedFrom(temp_s1, 0x34) != 0) {
                    temp_v1_4 = M2C_FIELD(temp_s1, s8 **, 0xC);
                    var_s3 = M2C_FIELD(temp_v1_4, s32 (**)(s8 *), 0x2CC)(temp_s1 + M2C_FIELD(temp_v1_4, s16 *, 0x2C8)) != 0;
                }
                if (var_s3 != 0) {
                    temp_a1 = M2C_FIELD(arg0, s8 **, 0xC0);
                    temp_a2 = M2C_FIELD(arg0, s32 *, 0xC4);
                    M2C_FIELD(arg1, s32 *, 0x30) = (s32) (M2C_FIELD(arg1, s32 *, 0x30) | (M2C_FIELD(temp_a1, s32 *, 0x30) & temp_a2));
                    UpdateVjoyPressTimes(arg1, temp_a1, temp_a2);
                }
            }
        }
    }
}
}
