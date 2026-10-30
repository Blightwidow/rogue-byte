typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LaunchSoAtTarget {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ char pad50[0x30];                   /* maybe part of sp40[4]? */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ char pad90[0x30];                   /* maybe part of sp80[4]? */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ s128 spF0;                          /* inferred */
    /* 0x100 */ s128 sp100;                         /* inferred */
    /* 0x110 */ char pad110[0x80];
};                                                  /* size = 0x190 */
#define spF0 (*(s128 *)(sp + 0x0F0))
#define sp100 (*(s128 *)(sp + 0x100))
s32 FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(s128, s128, M2C_UNK, f32); /* extern */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
f32 GRandInRange(...);                 /* extern */
s32 GetSoDvGravity(s8 *);                         /* extern */
M2C_UNK InferExpl(s8 *, s8 *);                  /* extern */
M2C_UNK LoadLookAtMatrix(s128 *, s128);             /* extern */
s128 PosLoWorld(s8 *);                            /* extern */
M2C_UNK PredictXfTransform(M2C_UNK *, M2C_UNK, s128 *, M2C_UNK, f32); /* extern */
M2C_UNK RecalcSwOxfFilterForObject(M2C_UNK *, s8 *); /* extern */
M2C_UNK SetSoCnstrForce(s8 *, M2C_UNK);           /* extern */
M2C_UNK SetSoCnstrTorque(s8 *, M2C_UNK);          /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, s128 *, s8 *); /* extern */
M2C_UNK func_001A58D0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_001F4898(s8 *, M2C_UNK);             /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002C44F0;
extern s128 g_2a2da0;
void LaunchSoAtTarget(s8 *arg0, s8 *arg1) {
    s8 sp[0xd0] __attribute__((aligned(16)));
    s128 sp40;
    s128 sp80;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    M2C_UNK *var_s2;
    M2C_UNK temp_a1;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_v0_3;
    f32 temp_v1_2;
    f32 var_f12;
    f32 var_f2;
    s128 temp_v0;
    s128 temp_v0_6;
    s128 temp_v1_5;
    s8 *temp_a2;
    s8 *temp_v0_2;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_7;
    s8 *temp_v1;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_6;
    s8 *temp_v1_7;
    temp_v0 = PosLoWorld(arg1);
    spC0 = temp_v0;
    temp_a2 = M2C_FIELD(arg0, s8 **, 0x60);
    spD0 = temp_v0;
    if (temp_a2 != NULL) {
        temp_v1 = M2C_FIELD(temp_a2, s8 **, 0xC);
        var_s2 = M2C_FIELD(temp_v1, M2C_UNK *(**)(s8 *, s8 *, s8 *), 0x104)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 0x100), sp, temp_a2);
    } else {
        var_s2 = &D_002C44F0;
        memset(sp, 0, 0x40);
    }
    __ml__FRC7MATRIX4T0(&sp40, (s128 *)(var_s2 + 0x40), sp);
    asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
    temp_v0_2 = arg0 + 0x70;
    asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf5, 0x50(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x50(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf2, vf5x");
    asm volatile("vmadday.xyz ACC, vf4, vf5y");
    asm volatile("vmaddaz.xyz ACC, vf3, vf5z");
    asm volatile("vmaddw.xyz vf2, vf1, vf0w");
    asm volatile("lqc2 vf1, 0xc0(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf3, vf2, vf1");
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    temp_f4 = M2C_FIELD(arg0, f32 *, 0x80);
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v0_3 = vu_1;
    temp_f5 = M2C_FIELD(arg0, f32 *, 0x84);
    var_f12 = M2C_FIELD(arg0, f32 *, 0x70) + (temp_v0_3 * (M2C_FIELD(temp_v0_2, f32 *, 4) + (temp_v0_3 * M2C_FIELD(temp_v0_2, f32 *, 8))));
    if (var_f12 < temp_f4) {
        var_f12 = temp_f4;
    } else if (temp_f5 < var_f12) {
        var_f12 = temp_f5;
    }
    if (var_f12 != 0.0f) {
        PredictXfTransform(var_s2, 0, &sp40, 0, var_f12);
        __ml__FRC7MATRIX4T0(&sp80, &sp40, sp);
        asm volatile("lqc2 vf3, 0xa0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, 0x50(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf2, vf5x");
        asm volatile("vmadday.xyz ACC, vf4, vf5y");
        asm volatile("vmaddaz.xyz ACC, vf3, vf5z");
        asm volatile("vmaddw.xyz vf2, vf1, vf0w");
        asm volatile("lqc2 vf1, 0xc0(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf3, vf2, vf1");
    }
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    temp_v0_4 = arg0 + 0x90;
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    temp_v1_2 = vu_2;
    temp_f4_2 = M2C_FIELD(arg0, f32 *, 0xA0);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x90) + (temp_v1_2 * (M2C_FIELD(temp_v0_4, f32 *, 4) + (temp_v1_2 * M2C_FIELD(temp_v0_4, f32 *, 8))));
    temp_f5_2 = M2C_FIELD(arg0, f32 *, 0xA4);
    if (temp_f0 < temp_f4_2) {
        var_f2 = temp_f4_2;
    } else {
        var_f2 = temp_f0;
        if (temp_f5_2 < temp_f0) {
            var_f2 = temp_f5_2;
        }
    }
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("qmtc2.ni %0, vf2" : : "r"(var_f2));
    asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
    if (vu_3 < 0.0001f) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
    } else {
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf3, Q");
    }
    asm volatile("lqc2 vf3, 0xd0(%0)" : : "r"(sp));
    asm volatile("vadda.xyzw ACC, vf0, vf3");
    asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
    asm volatile("sqc2 vf3, 0xf0(%0)" : : "r"(sp));
    s32 vu_4;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_4));
    spE0 = vu_4;
    if (FIsBasicDerivedFrom(arg1, 0x4F) != 0) {
        InferExpl(arg1, arg0);
        RecalcSwOxfFilterForObject(&B_003DD490, arg1);
    }
    temp_v0_5 = M2C_FIELD(arg1, s8 **, 0xC);
    M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *), 0x44)(arg1 + M2C_FIELD(temp_v0_5, s16 *, 0x40));
    SetSoCnstrForce(arg1, 0);
    SetSoCnstrTorque(arg1, 0);
    func_001A58D0(arg1, 0, 3);
    if (FIsBasicDerivedFrom(arg1, 0x52) != 0) {
        s64 vu_5;
        asm volatile("pextlw %0, %1, %0" : "=r"(vu_5) : "r"(0), "r"(M2C_FIELD(arg1, M2C_UNK32 *, 0x260)));
        s64 vu_6;
        asm volatile("pcpyld %0, %1, %0" : "=r"(vu_6) : "r"(0), "r"(vu_5));
        temp_v0_6 = vu_6;
        s64 vu_7;
        asm volatile("por %0, %1, %2" : "=r"(vu_7) : "r"(0), "r"(temp_v0_6));
        temp_a1 = vu_7;
        sp40 = temp_v0_6;
        func_001F4898(arg1, temp_a1);
    } else {
        asm volatile("lqc2 vf1, 0xe0(%0)" : : "r"(sp));
        if (FIsBasicDerivedFrom(arg1, 0x51) != 0) {
            asm volatile("lqc2 vf2, 0xc0(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf3, vf1, vf2");
            asm volatile("vmul.xyz vf1, vf3, vf3");
            asm volatile("vaddw.x vf2, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf2, vf1z");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(arg1, M2C_UNK32 *, 0x260)));
            asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
            s32 vu_8;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_8));
            if (vu_8 < 0.0001f) {
                asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
            } else {
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf3, Q");
            }
            temp_v1_3 = M2C_FIELD(arg1, s8 **, 0xC);
            asm volatile("vmulx.xyzw vf3, vf1, vf2x");
            asm volatile("sqc2 vf3, 0x100(%0)" : : "r"(sp));
            M2C_FIELD(temp_v1_3, M2C_UNK (**)(s8 *, s128), 0x11C)(arg1 + M2C_FIELD(temp_v1_3, s16 *, 0x118), sp100);
            LoadLookAtMatrix(&sp40, sp100);
            temp_v0_7 = M2C_FIELD(arg1, s8 **, 0xC);
            M2C_FIELD(temp_v0_7, M2C_UNK (**)(s8 *, s128 *), 0xF4)(arg1 + M2C_FIELD(temp_v0_7, s16 *, 0xF0), &sp40);
        } else {
            temp_v1_4 = M2C_FIELD(arg1, s8 **, 0xC);
            s64 vu_9;
            asm volatile("por %0, %1, %2" : "=r"(vu_9) : "r"(0), "r"(GetSoDvGravity(arg1)));
            s64 vu_10;
            asm volatile("por %0, %1, %2" : "=r"(vu_10) : "r"(0), "r"(FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(spC0, spF0, vu_9, M2C_FIELD(arg0, f32 *, 0xB0))));
            M2C_FIELD(temp_v1_4, M2C_UNK (**)(s8 *, s128), 0x11C)(arg1 + M2C_FIELD(temp_v1_4, s16 *, 0x118), vu_10);
        }
    }
    temp_f1 = M2C_FIELD(arg0, f32 *, 0xAC);
    if (temp_f1 > 0.0f) {
        temp_f24 = GRandInRange(arg1, M2C_FIELD(arg0, f32 *, 0xA8), temp_f1);
        temp_f23 = GRandInRange((s8 *)0xBF800000, 1.0f);
        temp_f20 = GRandInRange((s8 *)0xBF800000, 1.0f);
        s64 vu_11;
        asm volatile("pextlw %0, %1, %0" : "=r"(vu_11) : "r"(temp_f20), "r"(temp_f23));
        s64 vu_12;
        asm volatile("pcpyld %0, %1, %0" : "=r"(vu_12) : "r"(GRandInRange((s8 *)0xBF800000, 1.0f)), "r"(vu_11));
        temp_v1_5 = vu_12;
        asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_v1_5));
        asm volatile("vmul.xyz vf1, vf3, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        sp40 = temp_v1_5;
        asm volatile("qmtc2.ni %0, vf2" : : "r"(g_2a2da0));
        s32 vu_13;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_13));
        if (!(vu_13 < 0.0001f)) {
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf2, vf3, Q");
        }
        temp_v1_6 = M2C_FIELD(arg1, s8 **, 0xC);
        asm volatile("qmtc2.ni %0, vf1" : : "r"(temp_f24));
        asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf3, vf2, vf1x");
        s32 vu_14;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_14));
        M2C_FIELD(temp_v1_6, M2C_UNK (**)(s8 *, M2C_UNK), 0x124)(arg1 + M2C_FIELD(temp_v1_6, s16 *, 0x120), vu_14);
    }
    if (FIsBasicDerivedFrom(arg1, 0x50) != 0) {
        temp_v1_7 = M2C_FIELD(arg1, s8 **, 0xC);
        sp40 = M2C_FIELD(arg0, s128 *, 0x50);
        M2C_FIELD(temp_v1_7, M2C_UNK (**)(s8 *, s8 *, s128 *), 0x274)(arg1 + M2C_FIELD(temp_v1_7, s16 *, 0x270), M2C_FIELD(arg0, s8 **, 0x60), &sp40);
    }
}
}
