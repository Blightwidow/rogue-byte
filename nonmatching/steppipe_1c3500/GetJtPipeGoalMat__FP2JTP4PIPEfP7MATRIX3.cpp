typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3 {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ M2C_UNK sp30;                       /* inferred */
    /* 0x030 */ char pad30[0x30];
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x10];
    /* 0x070 */ M2C_UNK sp70;                       /* inferred */
    /* 0x070 */ char pad70[0x10];
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ char padE0[0xC0];
};                                                  /* size = 0x1A0 */
#define sp0 (*(s128 *)(sp + 0x000))
#define sp20 (*(s128 *)(sp + 0x020))
#define spC0 (*(s128 *)(sp + 0x0C0))
#define spD0 (*(s128 *)(sp + 0x0D0))
M2C_UNK BuildRotateVectorsMatrix(s128 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK EvaluateCrvFromU(s8 *, M2C_UNK, M2C_UNK *, f32); /* extern */
f32 GModPositive__Fff(f32, f32);                    /* extern */
M2C_UNK GetPathPosFromS(s8 *, M2C_UNK *, M2C_UNK, f32); /* extern */
s128 GetPerpendicularVector(M2C_UNK);               /* extern */
f32 SMaxCrv(s8 *);                                /* extern */
f32 SMinCrv();                                      /* extern */
f32 UMinCrv(s8 *);                                /* extern */
s32 bevy_camera_follow_track_heading_weight(s8 *, M2C_UNK, s128); /* extern */
f32 func_001E6728(s8 *, f32);                     /* extern */
extern s128 g_2a2da0;
extern s128 g_2a2dc0;
void GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(s8 *arg0, s32 arg1, s8 *arg2, f32 fparg0) {
    s8 sp[0xc0] __attribute__((aligned(16)));
    s128 sp10;
    M2C_UNK sp30;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s128 sp80;
    s128 sp90;
    s128 spA0;
    s128 spB0;
    M2C_UNK temp_a2;
    f32 temp_f22;
    f32 temp_f23;
    f32 var_f0;
    f32 var_f1;
    f32 var_f21;
    s32 var_s1;
    temp_f22 = SMinCrv();
    temp_f23 = SMaxCrv(arg0);
    EvaluateCrvFromU(arg0, 0, &sp30, UMinCrv(arg0));
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
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
    asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
    var_s1 = 0;
loop_5:
    if (var_s1 & 1) {
        var_f1 = 10.0f;
        var_f0 = (f32) (var_s1 + 1);
    } else {
        var_f1 = (f32) var_s1;
        var_f0 = -10.0f;
    }
    var_f21 = fparg0 + (var_f1 * var_f0);
    if (M2C_FIELD(arg0, s32 *, 0xE4) == 0) {
        if (!(var_f21 < temp_f22) && !(temp_f23 < fparg0)) {
        } else {
block_4:
            var_s1 += 1;
            goto loop_5;
        }
    } else {
        var_f21 = temp_f22 + GModPositive__Fff(var_f21 - temp_f22, temp_f23 - temp_f22);
    }
    GetPathPosFromS(arg0, &sp60, 0, func_001E6728(arg0, var_f21 + 50.0f));
    GetPathPosFromS(arg0, &sp70, 0, func_001E6728(arg0, var_f21 - 50.0f));
    asm volatile("lqc2 vf2, 0x60(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf3, vf2, vf1");
    asm volatile("vmul.xyz vf2, vf3, vf3");
    asm volatile("vaddw.x vf1, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf1, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    if (vu_2 < 0.0001f) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2dc0));
    } else {
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf3, Q");
    }
    asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(sp));
    if (var_s1 == 0) {
        asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
    }
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x50(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf2, vf3, vf4");
    asm volatile("vaddw.x vf1, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf1, vf2z");
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
    temp_a2 = vu_3;
    s32 vu_4;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_4));
    if (!(vu_4 > -0.9f)) {
        goto block_4;
    }
    s32 vu_5;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_5));
    BuildRotateVectorsMatrix(&spB0, vu_5, temp_a2);
    sp90 = spC0;
    sp80 = spB0;
    spA0 = spD0;
    asm volatile("lqc2 vf5, 0x40(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf1, vf5, vf5");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf6, vf0, Q");
    asm volatile("lqc2 vf4, 0x80(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
    asm volatile("qmtc2.ni %0, vf7" : : "r"(bevy_camera_follow_track_heading_weight(arg0, 0, M2C_FIELD(arg0, s128 *, 0x1C0))));
    asm volatile("vmulax.xyz ACC, vf4, vf7x");
    asm volatile("vmadday.xyz ACC, vf3, vf7y");
    asm volatile("vmaddz.xyz vf2, vf1, vf7z");
    asm volatile("sqc2 vf2, 0x60(%0)" : : "r"(sp));
    s32 vu_6;
    asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_6));
    if (vu_6 < 0.0001f) {
        asm volatile("qmtc2.ni %0, vf4" : : "r"(g_2a2dc0));
    } else {
        asm volatile("vdiv Q, vf0w, vf6x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf4, vf5, Q");
    }
    asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
    asm volatile("vopmula.xyz ACC, vf4, vf1");
    asm volatile("vopmsub.xyz vf1, vf1, vf4");
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("sqc2 vf4, 0x20(%0)" : : "r"(sp));
    asm volatile("vdiv Q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf2, vf1, Q");
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x70(%0)" : : "r"(sp));
    s32 vu_7;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_7));
    if (vu_7 < 0.0001f) {
        s32 vu_8;
        asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_8));
        sp10 = GetPerpendicularVector(vu_8);
    }
    asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
    asm volatile("vopmula.xyz ACC, vf4, vf2");
    asm volatile("vopmsub.xyz vf1, vf2, vf4");
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    if (arg1 == 0) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
        asm volatile("vmulx.xyzw vf3, vf2, vf1x");
        asm volatile("sqc2 vf1, 0x70(%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf2, vf4, vf1x");
        asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
    }
    if (arg2 != NULL) {
        M2C_FIELD(arg2, s128 *, 0) = sp0;
        M2C_FIELD(arg2, s128 *, 0x20) = sp20;
        M2C_FIELD(arg2, s128 *, 0x10) = sp10;
    }
}
}
