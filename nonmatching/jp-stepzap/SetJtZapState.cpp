typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetJtZapState {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of sp4[3]? */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0x70];
};                                                  /* size = 0xA0 */
#define sp0 (*(f32 *)(sp + 0x00))
#define sp4 (*(f32 *)(sp + 0x04))
M2C_UNK ApplyAsegToHandle(s32, s8 *, M2C_UNK, s8 *, M2C_UNK, M2C_UNK); /* extern */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
M2C_UNK FixStepAngularVelocity__FP4STEP(s8 *);    /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
f32 RadYawSo(s8 *);                               /* extern */
M2C_UNK RetractAsegaHandle(s8 *);                 /* extern */
M2C_UNK RetractSmaRef(s8 *);                      /* extern */
M2C_UNK SetStepRadTarget(s8 *, f32);              /* extern */
M2C_UNK SetStepRadTargetDir(s8 *, M2C_UNK);       /* extern */
f32 atan2f(f32, f32, f32);                          /* extern */
M2C_UNK func_001F1448(M2C_UNK, s8 *, M2C_UNK, M2C_UNK, s8 *); /* extern */
M2C_UNK func_001F4BF8(s8 *);                      /* extern */
extern M2C_UNK B_002DDF40;
extern s128 D_002BFA00;
extern s128 D_002BFA10;
extern M2C_UNK D_FLT_002BFA20;
extern s128 g_2a2dd0;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded0;
void SetJtZapState(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s128 sp10;
    s128 sp20;
    M2C_UNK var_s3;
    f32 temp_a0_4;
    f32 temp_f3;
    f32 var_f20;
    s32 temp_v1;
    s32 var_s1;
    s32 var_s2;
    u32 var_v1;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a0_3;
    s8 *temp_a0_5;
    s8 *temp_a0_6;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *temp_a1_3;
    s8 *temp_a1_4;
    s8 *temp_a1_5;
    s8 *temp_a1_6;
    s8 *temp_a1_7;
    s8 *temp_a1_8;
    s8 *temp_a1_9;
    s8 *temp_a2;
    s8 *temp_a3;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *var_v1_2;
    var_s2 = arg1;
    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    if (var_s2 != temp_v1) {
        if (temp_v1 != 3) {
            if (temp_v1 < 4) {
                var_v1 = var_s2 + 1;
                if (temp_v1 != -1) {
                } else {
                    if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0), 0x35) != 0) {
                        temp_a3 = M2C_FIELD(arg0, s8 **, 0);
                        M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a3, s8 **, 0x19B8), s8 **, 0xA8), s8 **, 0x60), s128 *, 0x20) = (s128) D_002BFA00;
                        M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a3, s8 **, 0x19BC), s8 **, 0xA8), s8 **, 0x60), s128 *, 0x20) = (s128) D_002BFA00;
                    }
                    temp_a1 = M2C_FIELD(arg0, s8 **, 0);
                    temp_v0 = M2C_FIELD(temp_a1, s8 **, 0xC);
                    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0x2DC)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x2D8), temp_a1);
                    temp_a0 = M2C_FIELD(arg0, s8 **, 0);
                    temp_v1_2 = temp_a0 + 0x190;
                    M2C_FIELD(temp_v1_2, s32 *, 4) = 0;
                    M2C_FIELD(temp_v1_2, s32 *, 8) = 0;
                    M2C_FIELD(temp_a0, s32 *, 0x190) = 0;
                    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x15C) = 0;
                    M2C_FIELD(arg0, f32 *, 0x98) = 3.4028235e38f;
                    goto block_12;
                }
            } else {
                var_v1 = var_s2 + 1;
                if (temp_v1 != 0xA) {
                } else {
                    goto block_10;
                }
            }
        } else {
block_10:
            var_v1 = var_s2 + 1;
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0), 0x35) != 0) {
                temp_a1_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0x19B8), s8 **, 0xA8), s8 **, 0x60);
                temp_v0_2 = temp_a1_2 + 0x20;
                M2C_FIELD(temp_v0_2, s32 *, 4) = 0;
                M2C_FIELD(temp_v0_2, s32 *, 8) = 0;
                M2C_FIELD(temp_a1_2, s32 *, 0x20) = 0;
block_12:
                var_v1 = var_s2 + 1;
            }
        }
        var_s1 = 0;
        var_s3 = 1;
        switch (var_v1) {
        case 0:
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0), 0x35) != 0) {
                temp_a1_3 = M2C_FIELD(arg0, s8 **, 0);
                temp_a0_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a1_3, s8 **, 0x19B8), s8 **, 0xA8), s8 **, 0x60);
                temp_v0_3 = temp_a0_2 + 0x20;
                M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
                M2C_FIELD(temp_v0_3, s32 *, 8) = 0;
                M2C_FIELD(temp_a0_2, s32 *, 0x20) = 0;
                temp_a0_3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a1_3, s8 **, 0x19BC), s8 **, 0xA8), s8 **, 0x60);
                temp_v0_4 = temp_a0_3 + 0x20;
                M2C_FIELD(temp_v0_4, s32 *, 4) = 0;
                M2C_FIELD(temp_v0_4, s32 *, 8) = 0;
                M2C_FIELD(temp_a0_3, s32 *, 0x20) = 0;
            }
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x15C) = 1;
            M2C_FIELD(arg0, f32 *, 0x98) = (f32) g_2dded0;
            break;
        case 9:
            temp_a1_4 = M2C_FIELD(arg0, s8 **, 0);
            temp_v1_3 = M2C_FIELD(temp_a1_4, s8 **, 0xC);
            temp_a1_5 = M2C_FIELD(arg0, s8 **, 0);
            asm volatile("qmtc2.ni %0, vf4" : : "r"(M2C_FIELD(temp_v1_3, s32 (**)(s8 *, s8 *), 0x10C)(temp_a1_4 + M2C_FIELD(temp_v1_3, s16 *, 0x108), temp_a1_4)));
            asm volatile("lqc2 vf1, 0x1b0(%0)" : : "r"(temp_a1_5));
            asm volatile("vmul.xyz vf2, vf4, vf1");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf3, vf2z");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
            if (!(vu_1 > -250.0f)) {
                temp_v1_4 = M2C_FIELD(temp_a1_5, s8 **, 0xC);
                asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(temp_v1_4, s32 (**)(s8 *, s8 *), 0x10C)(temp_a1_5 + M2C_FIELD(temp_v1_4, s16 *, 0x108), temp_a1_5)));
                asm volatile("vmul.xy vf1, vf2, vf2");
                asm volatile("vaddy.x vf1, vf1, vf1y");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                temp_a0_4 = vu_2;
                asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                temp_f3 = M2C_FIELD(&D_FLT_002BFA20, f32 *, 0) + (temp_a0_4 * (M2C_FIELD(&D_FLT_002BFA20, f32 *, 4) + (temp_a0_4 * M2C_FIELD(&D_FLT_002BFA20, f32 *, 8))));
                if (temp_f3 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
                    var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 0);
                } else {
                    var_f20 = temp_f3;
                    if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f3) {
                        var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 4);
                    }
                }
                temp_a0_5 = M2C_FIELD(arg0, s8 **, 0);
                SetStepRadTarget(temp_a0_5, M2C_FIELD(temp_a0_5, f32 *, 0x1A8) + (RadNormalize__Ff((atan2f(temp_a0_4, sp4, sp0) + 3.1415927f) - M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), f32 *, 0x1A8)) * var_f20));
                FixStepAngularVelocity__FP4STEP(M2C_FIELD(arg0, s8 **, 0));
            } else {
                var_s2 = 9;
            }
            /* fallthrough */
        case 10:
            var_s3 = 0x21;
            var_s1 = M2C_FIELD((arg0 + (var_s2 * 4)), s32 *, 0xA0);
            break;
        case 11:
            var_s3 = 0x21;
            sp10 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0))));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
            SetStepRadTargetDir(M2C_FIELD(arg0, s8 **, 0), vu_3);
            /* fallthrough */
        case 4:
            var_s1 = M2C_FIELD((arg0 + (var_s2 * 4)), s32 *, 0xA0);
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0), 0x35) != 0) {
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0x19B8), s8 **, 0xA8), s8 **, 0x60), s128 *, 0x20) = (s128) D_002BFA10;
            }
            break;
        case 6:
        case 12:
            sp20 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
            asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0))));
            asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf4, vf4, vf1");
            s32 vu_4;
            asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_4));
            SetStepRadTargetDir(M2C_FIELD(arg0, s8 **, 0), vu_4);
            var_v1_2 = arg0 + (var_s2 * 4);
            var_s3 = ((var_s2 ^ 0xB) == 0) ? 0x21 : 1;
block_35:
            var_s1 = M2C_FIELD(var_v1_2, s32 *, 0xA0);
            break;
        case 1:
        case 7:
        case 8:
            var_s1 = M2C_FIELD((arg0 + (var_s2 * 4)), s32 *, 0xA0);
            break;
        case 5:
        case 13:
            temp_a2 = M2C_FIELD(arg0, s8 **, 0);
            temp_v1_5 = M2C_FIELD(temp_a2, s8 **, 0xC);
            M2C_FIELD(temp_v1_5, M2C_UNK (**)(s8 *, s128, s8 *), 0x124)(temp_a2 + M2C_FIELD(temp_v1_5, s16 *, 0x120), g_2a2dd0, temp_a2);
            SetStepRadTarget(M2C_FIELD(arg0, s8 **, 0), RadYawSo(M2C_FIELD(arg0, s8 **, 0)));
            temp_a1_6 = M2C_FIELD(arg0, s8 **, 0);
            var_s3 = ((var_s2 ^ 0xC) == 0) ? 0x21 : 1;
            M2C_FIELD(M2C_FIELD(temp_a1_6, s8 **, 0x150), f32 *, 0x18) = (f32) M2C_FIELD(temp_a1_6, f32 *, 0x1A8);
            var_s1 = M2C_FIELD((arg0 + (var_s2 * 4)), s32 *, 0xA0);
            break;
        case 2:
        case 3:
            var_s3 = 0;
            SetStepRadTarget(M2C_FIELD(arg0, s8 **, 0), RadYawSo(M2C_FIELD(arg0, s8 **, 0)));
            temp_a0_6 = M2C_FIELD(arg0, s8 **, 0);
            var_v1_2 = arg0 + (var_s2 * 4);
            M2C_FIELD(M2C_FIELD(temp_a0_6, s8 **, 0x150), f32 *, 0x18) = (f32) M2C_FIELD(temp_a0_6, f32 *, 0x1A8);
            goto block_35;
        }
        func_001F4BF8(M2C_FIELD(arg0, s8 **, 0));
        M2C_FIELD(arg0, s32 *, 4) = var_s2;
        M2C_FIELD(arg0, f32 *, 8) = (f32) g_2dded0;
        if (var_s2 != -1) {
            if (var_s1 == 0) {
                var_s1 = *(arg0 + 0xA0 + ((var_s2 < 8) ? 0 : 0x20));
            }
            RetractAsegaHandle(M2C_FIELD(arg0, s8 **, 0) + 0x1030);
            RetractSmaRef(M2C_FIELD(arg0, s8 **, 0) + 0x1034);
            temp_a1_7 = M2C_FIELD(arg0, s8 **, 0);
            ApplyAsegToHandle(var_s1, temp_a1_7, var_s3, temp_a1_7 + 0x1030, 0, 0x3F800000);
            temp_a1_8 = M2C_FIELD(arg0, s8 **, 0);
            func_001F1448(0, temp_a1_8, -1, 0, temp_a1_8 + 0x1034);
            temp_a1_9 = M2C_FIELD(arg0, s8 **, 0);
            temp_v0_5 = M2C_FIELD(temp_a1_9, s8 **, 0xC);
            M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, s8 *), 0x2D4)(temp_a1_9 + M2C_FIELD(temp_v0_5, s16 *, 0x2D0), temp_a1_9);
        }
    }
}
}
