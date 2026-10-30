typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetGadgetObjState {
    /* 0x000 */ char pad0[8];
    /* 0x008 */ f32 sp8;                            /* inferred */
    /* 0x00C */ char padC[4];
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s8 *sp60;                         /* inferred */
    /* 0x064 */ char pad64[0x10C];
};                                                  /* size = 0x170 */
#define sp40 (*(s128 *)(sp + 0x040))
#define sp50 (*(s128 *)(sp + 0x050))
M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, M2C_UNK, M2C_UNK); /* extern */
s32 ConvertXfVec(M2C_UNK, s32, s128);               /* extern */
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 DecomposeRotateMatrixEuler(...); /* extern */
s32 FGadgetObjIsKindB(s8 *, s8 *);              /* extern */
M2C_UNK FadeAloOut(s8 *, M2C_UNK);                /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK RecalcSwOxfFilterForObject(M2C_UNK *, s8 *); /* extern */
M2C_UNK SetSmaGoalIfReachable(s32, s32);            /* extern */
M2C_UNK SetSoCnstrForce(s8 *, M2C_UNK);           /* extern */
M2C_UNK SetSoCnstrTorque(s8 *, M2C_UNK);          /* extern */
s32 func_0012DC18(s8 *, s8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0012E460(s8 *);                      /* extern */
M2C_UNK func_001A58D0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002C4398;
extern s128 g_2a2dc0;
extern f32 g_2dded0;
extern s8 *g_2e1e40;
void SetGadgetObjState(s8 *arg0, s32 arg1) {
    s8 sp[0xe0] __attribute__((aligned(16)));
    f32 sp8;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s8 *sp60;
    M2C_UNK temp_s1;
    f32 temp_v0_7;
    f32 var_f20;
    s128 temp_s0_2;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_4;
    s32 var_s1;
    s8 **var_s4;
    s8 *temp_a0;
    s8 *temp_a1;
    s8 *temp_s0_3;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    s8 *var_s3;
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x150);
    if (arg1 != temp_s0) {
        M2C_FIELD(arg0, s32 *, 0x150) = arg1;
        M2C_FIELD(arg0, s32 *, 0x158) = -1;
        M2C_FIELD(arg0, f32 *, 0x154) = (f32) g_2dded0;
        func_0012E460(arg0 + 0x180);
        func_0012E460(arg0 + 0x17C);
        if ((temp_s0 == 0) || (temp_s0 == 4)) {
            RecalcSwOxfFilterForObject(&B_003DD490, arg0);
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
        switch (temp_v1) {                          /* irregular */
        case 0:
            SetSoCnstrForce(arg0, 0);
            SetSoCnstrTorque(arg0, 0);
            temp_v1_2 = M2C_FIELD(arg0, s8 **, 0x58);
            temp_v0 = temp_v1_2 + 0xB0;
            M2C_FIELD(temp_v0, s32 *, 4) = 0;
            M2C_FIELD(temp_v0, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_2, s32 *, 0xB0) = 0;
            temp_a0 = M2C_FIELD(arg0, s8 **, 0x5C);
            temp_v0_2 = temp_a0 + 0xB0;
            M2C_FIELD(temp_v0_2, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_2, s32 *, 8) = 0;
            M2C_FIELD(temp_a0, s32 *, 0xB0) = 0;
            temp_s0_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x58), s128 *, 0x30);
            s64 vu_1;
            asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(DecomposeRotateMatrixEuler(M2C_FIELD(arg0, s8 **, 0x5C))));
            temp_s1 = vu_1;
            s64 vu_2;
            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s0_2));
            vu_2;
            s64 vu_3;
            asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_s1));
            vu_3;
            M2C_FIELD(arg0, s32 *, 0x180) = func_0012DC18(arg0, M2C_FIELD(arg0, s8 **, 0x58), 0, 7);
            M2C_FIELD(arg0, s32 *, 0x17C) = func_0012DC18(arg0, M2C_FIELD(arg0, s8 **, 0x5C), 0, 7);
            RecalcSwOxfFilterForObject(&B_003DD490, arg0);
            break;
        case 2:
            SetSoCnstrForce(arg0, 1);
            SetSoCnstrTorque(arg0, 1);
            temp_a1 = M2C_FIELD(arg0, s8 **, 0x58);
            temp_v0_3 = temp_a1 + 0xB0;
            M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_3, s32 *, 8) = 0;
            M2C_FIELD(temp_a1, s32 *, 0xB0) = 0;
            temp_v1_3 = M2C_FIELD(arg0, s8 **, 0x5C);
            temp_v0_4 = temp_v1_3 + 0xB0;
            M2C_FIELD(temp_v0_4, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_4, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_3, s32 *, 0xB0) = 0;
            if (FGadgetObjIsKindB(arg0, temp_a1) != 0) {
                temp_v0_5 = M2C_FIELD(arg0, s8 **, 0x5C);
                if (temp_v0_5 != NULL) {
                    asm volatile("qmtc2.ni %0, vf1" : : "r"(ConvertXfVec(0, M2C_FIELD(temp_v0_5, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0x190))));
                    asm volatile("vmul.xyz vf3, vf1, vf1");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf3, vf3y");
                    asm volatile("vmaddz.x vf3, vf2, vf3z");
                    asm volatile("vsqrt Q, vf3x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf3, vf0, Q");
                    asm volatile("vdiv Q, vf0w, vf3x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf3, vf1, Q");
                    asm volatile("sqc2 vf3, 0xf0(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf3, 0xf0(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x5C), s32 *, 0xA0), g_2a2dc0)));
                    asm volatile("vmul.xyz vf1, vf2, vf2");
                    asm volatile("vaddw.x vf4, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf4, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    asm volatile("vdiv Q, vf0w, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf3, vf2, Q");
                    s32 vu_4;
                    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_4));
                    s32 vu_5;
                    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_5));
                    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp30, vu_5, vu_4);
                    sp10 = sp40;
                    sp20 = sp50;
                    s64 vu_6;
                    asm volatile("por %0, %1, %2" : "=r"(vu_6) : "r"(0), "r"(DecomposeRotateMatrixEuler(sp, sp30, sp30)));
                    vu_6;
                    M2C_FIELD(arg0, s32 *, 0x17C) = func_0012DC18(arg0, M2C_FIELD(arg0, s8 **, 0x5C), 0, 7);
                }
            }
            break;
        case 1:
            func_001A58D0(arg0, 0, 0xF);
            SetSoCnstrForce(arg0, 0);
            if (M2C_FIELD(arg0, s32 *, 0x15C) != 0x29) {
                SetSoCnstrTorque(arg0, 0);
            } else {
                SetSoCnstrTorque(arg0, 1);
                temp_v0_6 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x38, 0);
                var_f20 = 3.4028235e38f;
                var_s3 = g_2e1e40;
                if (temp_v0_6 > 0) {
                    var_s4 = &sp60;
                    var_s1 = temp_v0_6;
                    do {
                        temp_s0_3 = *var_s4;
                        asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(temp_s0_3)));
                        asm volatile("sqc2 vf1, 0xe0(%0)" : : "r"(sp));
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0)));
                        asm volatile("lqc2 vf1, 0xe0(%0)" : : "r"(sp));
                        asm volatile("vsub.xyzw vf1, vf1, vf2");
                        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                        sp8 *= 2.0f;
                        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                        asm volatile("vmul.xyz vf1, vf1, vf1");
                        asm volatile("vaddw.x vf2, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf2, vf1z");
                        asm volatile("vsqrt Q, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf1, vf0, Q");
                        s32 vu_7;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_7));
                        temp_v0_7 = vu_7;
                        var_s1 -= 1;
                        if (temp_v0_7 < var_f20) {
                            var_f20 = temp_v0_7;
                            var_s3 = temp_s0_3;
                        }
                        var_s4 += 4;
                    } while (var_s1 != 0);
                }
                M2C_FIELD(arg0, s8 **, 0x160) = var_s3;
            }
            break;
        case 4:
            RecalcSwOxfFilterForObject(&B_003DD490, arg0);
            FadeAloOut(arg0, 0x3E800000);
            break;
        }
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x168);
        if (temp_a0_2 != 0) {
            temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x150);
            if (temp_v1_4 >= 0) {
                SetSmaGoalIfReachable(temp_a0_2, *((temp_v1_4 * 4) + &D_002C4398));
            }
        }
    }
}
}
