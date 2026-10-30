typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PosAimAtPlayer {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ f32 sp10;                           /* inferred */
    /* 0x014 */ f32 sp14;                           /* inferred */
    /* 0x018 */ f32 sp18;                           /* inferred */
    /* 0x01C */ char pad1C[4];
    /* 0x020 */ f32 sp20;                           /* inferred */
    /* 0x024 */ f32 sp24;                           /* inferred */
    /* 0x028 */ char pad28[0x18];                   /* maybe part of sp24[7]? */
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x10];
    /* 0x050 */ M2C_UNK sp50;                       /* inferred */
    /* 0x050 */ char pad50[0x60];
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ f32 spF0;                           /* inferred */
    /* 0x0F4 */ f32 spF4;                           /* inferred */
    /* 0x0F8 */ f32 spF8;                           /* inferred */
    /* 0x0FC */ s32 spFC;                           /* inferred */
    /* 0x100 */ s32 sp100;                          /* inferred */
    /* 0x104 */ char pad104[0xC];                   /* maybe part of sp100[4]? */
    /* 0x110 */ s128 sp110;                         /* inferred */
    /* 0x120 */ char pad120[0x10];
    /* 0x130 */ s128 sp130;                         /* inferred */
    /* 0x140 */ s128 sp140;                         /* inferred */
    /* 0x150 */ char pad150[0x80];
};                                                  /* size = 0x1D0 */
#define sp14 (*(f32 *)(sp + 0x014))
#define sp18 (*(f32 *)(sp + 0x018))
#define sp140 (*(s128 *)(sp + 0x140))
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DecomposeSphere(M2C_UNK, f32 *, f32 *, f32 *); /* extern */
f32 GetSuck(M2C_UNK *);                             /* extern */
f32 *PmatLoWorld(s8 *);                           /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
s8 *PpoSwFocusBase(M2C_UNK *);                    /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, M2C_UNK, s32); /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
s32 SetVectorSphere__FP6VECTORfff(f32, f32, f32);   /* extern */
s32 VecCombo__FG8VU_FLOATG9VU_VECTORT0T1(M2C_UNK, M2C_UNK, M2C_UNK, s128); /* extern */
M2C_UNK __8VU_FLOATf(s128 *, f32);                  /* extern */
M2C_UNK __9VU_VECTORRC6VECTOR(s128 *, M2C_UNK *);   /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(f32 *, M2C_UNK);   /* extern */
f32 atan2f(f32, f32);                               /* extern */
M2C_UNK func_001B44D8(s32 *, s32 *);                /* extern */
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BDC60;
extern M2C_UNK D_002BDC80;
extern M2C_UNK D_FLT_002BDC70;
extern M2C_UNK D_FLT_002BDC90;
extern f32 D_FLT_002BDC98;
extern f32 D_FLT_002BDCA0;
extern f32 RO_FLT_002A513C;
extern M2C_UNK g_2a2dc0;
s128 PosAimAtPlayer(s128 arg1) {
    f32 saved_reg_f22;
    s8 sp[0x100] __attribute__((aligned(16)));
    f32 sp10;
    f32 sp20;
    f32 sp24;
    M2C_UNK sp40;
    M2C_UNK sp50;
    s128 spB0;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    f32 spF0;
    f32 spF4;
    f32 spF8;
    s32 spFC;
    s32 sp100;
    s128 sp110;
    s128 sp130;
    f32 *temp_s0;
    f32 *var_s0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f23;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_v0_4;
    f32 var_f0;
    f32 var_f21;
    f32 var_f22;
    s128 temp_v0_2;
    s32 temp_v0_3;
    s32 var_v0;
    u32 var_s1;
    s8 *temp_a1;
    s8 *temp_v0;
    var_f22 = saved_reg_f22;
    sp110 = arg1;
    temp_v0 = PpoSwFocusBase(&B_003DD490);
    asm volatile("lqc2 vf3, 0x110(%0)" : : "r"(sp));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(temp_v0)));
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
    temp_f23 = vu_1;
    temp_f21 = GetSuck(&B_002DE578);
    temp_a1 = M2C_FIELD(temp_v0, s8 **, 0xC);
    asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_v0)));
    asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(0x42480000));
    asm volatile("vadda.xyzw ACC, vf0, vf3");
    asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
    asm volatile("sqc2 vf3, 0x120(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
    temp_v0_2 = M2C_FIELD(temp_a1, s128 (**)(s8 *, s8 *, M2C_UNK), 0x10C)(temp_v0 + M2C_FIELD(temp_a1, s16 *, 0x108), temp_a1, 0x42480000);
    sp130 = temp_v0_2;
    asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_v0_2));
    asm volatile("vmul.xyz vf1, vf4, vf4");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    var_v0 = 1;
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    if (!(D_FLT_002BDC98 < vu_2)) {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_f20 = 1.0f - temp_f21;
        __8VU_FLOATf(&spB0, temp_f20);
        __9VU_VECTORRC6VECTOR(&spC0, &D_002BDC60);
        __8VU_FLOATf(&spD0, temp_f21);
        __9VU_VECTORRC6VECTOR(&spE0, &D_002BDC80);
        s64 vu_3;
        asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(spD0));
        s64 vu_4;
        asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(spC0));
        s64 vu_5;
        asm volatile("por %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(spB0));
        s64 vu_6;
        asm volatile("por %0, %1, %2" : "=r"(vu_6) : "r"(0), "r"(VecCombo__FG8VU_FLOATG9VU_VECTORT0T1(vu_5, vu_4, vu_3, spE0)));
        __as__6VECTORG9VU_VECTOR(&sp10, vu_6);
        temp_f3 = (temp_f20 * M2C_FIELD(&D_FLT_002BDC70, f32 *, 0)) + (temp_f21 * M2C_FIELD(&D_FLT_002BDC90, f32 *, 0));
        temp_f2 = sp10 + (temp_f23 * (sp14 + (temp_f23 * sp18)));
        temp_f1 = (temp_f20 * M2C_FIELD(&D_FLT_002BDC70, f32 *, 4)) + (temp_f21 * M2C_FIELD(&D_FLT_002BDC90, f32 *, 4));
        sp20 = temp_f3;
        sp24 = temp_f1;
        if (temp_f2 < temp_f3) {
            var_f0 = temp_f3;
        } else {
            var_f0 = temp_f2;
            if (temp_f1 < temp_f2) {
                var_f0 = temp_f1;
            }
        }
        asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f0));
        asm volatile("lqc2 vf3, 0x130(%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf2, vf3, vf1x");
        asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
    } else {
        temp_s0 = PmatLoWorld(temp_v0);
        SetVectorCylind__FP6VECTORfff(atan2f(M2C_FIELD(temp_s0, f32 *, 4), *PmatLoWorld(temp_v0)), D_FLT_002BDC98, 0);
    }
    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x120(%0)" : : "r"(sp));
    asm volatile("vadd.xyzw vf1, vf4, vf1");
    asm volatile("lqc2 vf2, 0x110(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf2, vf1, vf2");
    var_s1 = 0;
    s32 vu_7;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_7));
    DecomposeSphere(vu_7, &spF0, &spF4, &spF8);
    CStackFrame_Construct(&sp40);
    func_001B44D8(&spFC, &sp100);
    var_f21 = RO_FLT_002A513C;
    var_s0 = &D_FLT_002BDCA0;
loop_11:
    temp_f0 = RadNormalize__Ff(spF0 + *var_s0);
    asm volatile("lqc2 vf3, 0x110(%0)" : : "r"(sp));
    asm volatile("qmtc2.ni %0, vf4" : : "r"(SetVectorSphere__FP6VECTORfff(temp_f0, spF4, spF8)));
    asm volatile("vadd.xyzw vf1, vf3, vf4");
    asm volatile("sqc2 vf1, 0x150(%0)" : : "r"(sp));
    s32 vu_8;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_8));
    temp_v0_3 = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp110, vu_8, spFC);
    asm volatile("lqc2 vf1, 0x150(%0)" : : "r"(sp));
    if (temp_v0_3 != 0) {
        asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
    }
    asm volatile("lqc2 vf2, 0x110(%0)" : : "r"(sp));
    if (temp_v0_3 != 0) {
        asm volatile("vsub.xyzw vf1, vf2, vf1");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_9;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_9));
        temp_v0_4 = vu_9;
        var_s1 += 1;
        if (var_f21 < temp_v0_4) {
            var_f21 = temp_v0_4;
            var_f22 = temp_f0;
        }
        var_s0 += 4;
        if (var_s1 < 0xBU) {
            goto loop_11;
        }
    } else {
        var_f22 = temp_f0;
    }
    asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorSphere__FP6VECTORfff(var_f22, spF4, spF8)));
    asm volatile("lqc2 vf1, 0x110(%0)" : : "r"(sp));
    asm volatile("vadd.xyzw vf2, vf1, vf2");
    asm volatile("sqc2 vf2, 0x140(%0)" : : "r"(sp));
    CStackFrame_Destructor(&sp40, 2);
    return sp140;
}
}
