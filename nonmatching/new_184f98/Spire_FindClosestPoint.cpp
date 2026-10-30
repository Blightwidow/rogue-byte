typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Spire_FindClosestPoint {
    /* 0x000 */ char pad0[0x48];
    /* 0x048 */ f32 sp48;                           /* inferred */
    /* 0x04C */ char pad4C[0xC];                    /* maybe part of sp48[4]? */
    /* 0x058 */ f32 sp58;                           /* inferred */
    /* 0x05C */ char pad5C[4];
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x20];
    /* 0x080 */ f32 sp80;                           /* inferred */
    /* 0x084 */ char pad84[0xC];                    /* maybe part of sp80[4]? */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ char padC0[0x90];
};                                                  /* size = 0x150 */
#define spB0 (*(s128 *)(sp + 0x0B0))
M2C_UNK ClosestPointOnSegment(s128, M2C_UNK, M2C_UNK, M2C_UNK *, f32 *, M2C_UNK); /* extern */
void Spire_FindClosestPoint(s8 *arg0, s128 arg1, s8 *arg3, s128 *arg4, s32 arg5) {
    s32 saved_reg_s2;
    s8 sp[0xa0] __attribute__((aligned(16)));
    f32 sp48;
    f32 sp58;
    M2C_UNK sp60;
    f32 sp80;
    s128 sp90;
    s128 spA0;
    M2C_UNK temp_a0_2;
    M2C_UNK temp_a1;
    M2C_UNK temp_v1_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_v0;
    f32 var_f22;
    s128 var_s2;
    s32 temp_a2;
    s32 var_s0;
    s8 *temp_a0;
    s8 *temp_v1;
    var_s2 = saved_reg_s2;
    var_s0 = 0;
    spA0 = arg1;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    var_f22 = 3.4028235e38f;
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
        do {
            temp_a2 = M2C_FIELD(arg0, s32 *, 0xE4);
            asm volatile("lqc2 vf6, (%0)" : : "r"(sp));
            asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
            temp_a0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0xEC) + (var_s0 * 0xC));
            asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, (%0)" : : "r"((M2C_FIELD(temp_a0, s32 *, 0) * 0x10) + temp_a2));
            asm volatile("vmulax.xyz ACC, vf6, vf1x");
            asm volatile("vmadday.xyz ACC, vf5, vf1y");
            asm volatile("vmaddaz.xyz ACC, vf4, vf1z");
            asm volatile("vmaddw.xyz vf12, vf3, vf0w");
            asm volatile("lqc2 vf2, (%0)" : : "r"((M2C_FIELD(temp_a0, s32 *, 4) * 0x10) + temp_a2));
            asm volatile("lqc2 vf1, (%0)" : : "r"((M2C_FIELD(temp_a0, s32 *, 8) * 0x10) + temp_a2));
            asm volatile("vmulax.xyz ACC, vf6, vf2x");
            asm volatile("vmadday.xyz ACC, vf5, vf2y");
            asm volatile("vmaddaz.xyz ACC, vf4, vf2z");
            asm volatile("vmaddw.xyz vf11, vf3, vf0w");
            asm volatile("vmulax.xyz ACC, vf6, vf1x");
            asm volatile("vmadday.xyz ACC, vf5, vf1y");
            asm volatile("vmaddaz.xyz ACC, vf4, vf1z");
            asm volatile("vmaddw.xyz vf10, vf3, vf0w");
            asm volatile("vmove.xyzw vf9, vf12");
            asm volatile("vmove.xyzw vf7, vf10");
            asm volatile("vmove.xyzw vf8, vf11");
            asm volatile("vsub.xyzw vf3, vf9, vf7");
            asm volatile("vsub.xyzw vf1, vf8, vf7");
            asm volatile("lqc2 vf4, 0xa0(%0)" : : "r"(sp));
            asm volatile("vopmula.xyz ACC, vf3, vf1");
            asm volatile("vopmsub.xyz vf2, vf1, vf3");
            asm volatile("sqc2 vf2, 0xb0(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf2, vf4, vf7");
            asm volatile("lqc2 vf4, 0xb0(%0)" : : "r"(sp));
            asm volatile("vopmula.xyz ACC, vf4, vf1");
            asm volatile("vopmsub.xyz vf1, vf1, vf4");
            asm volatile("vopmula.xyz ACC, vf2, vf3");
            asm volatile("vopmsub.xyz vf4, vf3, vf2");
            asm volatile("vmul.xyz vf3, vf3, vf1");
            asm volatile("vaddw.x vf5, vf0, vf0w");
            asm volatile("vadday.x ACC, vf3, vf3y");
            asm volatile("vmaddz.x vf3, vf5, vf3z");
            asm volatile("vmul.xyz vf2, vf2, vf1");
            asm volatile("vaddw.x vf6, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf6, vf2z");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
            temp_f0 = 1.0f / vu_1;
            asm volatile("lqc2 vf2, 0xb0(%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf4, vf2, vf4");
            asm volatile("vaddw.x vf1, vf0, vf0w");
            asm volatile("vadday.x ACC, vf4, vf4y");
            asm volatile("vmaddz.x vf4, vf1, vf4z");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
            temp_f2 = temp_f0 * vu_2;
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
            temp_f1 = temp_f0 * vu_3;
            if (temp_f2 < 0.0f) {
                s32 vu_4;
                asm volatile("qmfc2.ni %0, vf7" : "=r"(vu_4));
                s32 vu_5;
                asm volatile("qmfc2.ni %0, vf8" : "=r"(vu_5));
                ClosestPointOnSegment(spA0, vu_5, vu_4, &sp60, &sp80, 0);
                sp48 = 1.0f - sp80;
            } else if (temp_f1 < 0.0f) {
                s32 vu_6;
                asm volatile("qmfc2.ni %0, vf7" : "=r"(vu_6));
                s32 vu_7;
                asm volatile("qmfc2.ni %0, vf9" : "=r"(vu_7));
                ClosestPointOnSegment(spA0, vu_7, vu_6, &sp60, &sp80, 0);
                sp48 = 0.0f;
            } else {
                s32 vu_8;
                asm volatile("qmfc2.ni %0, vf9" : "=r"(vu_8));
                temp_a1 = vu_8;
                if ((temp_f2 + temp_f1) > 1.0f) {
                    s32 vu_9;
                    asm volatile("qmfc2.ni %0, vf8" : "=r"(vu_9));
                    ClosestPointOnSegment(spA0, temp_a1, vu_9, &sp60, &sp80, 0);
                    sp48 = sp80;
                } else {
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_f2));
                    asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_f1));
                    sp48 = temp_f1;
                    asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf1" : : "r"((1.0f - temp_f2) - temp_f1));
                    asm volatile("vmulax.xyzw ACC, vf12, vf2x");
                    asm volatile("vmaddax.xyzw ACC, vf11, vf3x");
                    asm volatile("vmaddx.xyzw vf2, vf10, vf1x");
                    asm volatile("sqc2 vf1, 0x70(%0)" : : "r"(sp));
                    asm volatile("sqc2 vf2, 0x60(%0)" : : "r"(sp));
                }
            }
            asm volatile("lqc2 vf2, 0xa0(%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf3, vf2");
            asm volatile("vmul.xyz vf1, vf1, vf1");
            asm volatile("vaddw.x vf2, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf2, vf1z");
            s32 vu_10;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_10));
            temp_v0 = vu_10;
            if (temp_v0 < var_f22) {
                var_f22 = temp_v0;
                s32 vu_11;
                asm volatile("ldl %0, 0x47(%1)" : "=r"(vu_11) : "r"(sp));
                s32 vu_12;
                asm volatile("ldr %0, 0x40(%1)" : "=r"(vu_12) : "r"(sp), "0"(vu_11));
                temp_v1_2 = vu_12;
                asm volatile("sdl %0, 0x57(%1)" : : "r"(temp_v1_2), "r"(sp));
                asm volatile("sdr %0, 0x50(%1)" : : "r"(temp_v1_2), "r"(sp));
                sp58 = sp48;
                s32 vu_13;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_13));
                var_s2 = vu_13;
                sp90 = spB0;
            }
            var_s0 += 1;
        } while (var_s0 < M2C_FIELD(arg0, s32 *, 0xE8));
    }
    if (arg3 != NULL) {
        s32 vu_14;
        asm volatile("ldl %0, 0x57(%1)" : "=r"(vu_14) : "r"(sp));
        s32 vu_15;
        asm volatile("ldr %0, 0x50(%1)" : "=r"(vu_15) : "r"(sp), "0"(vu_14));
        temp_a0_2 = vu_15;
        asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_a0_2), "r"(arg3));
        asm volatile("sdr %0, (%1)" : : "r"(temp_a0_2), "r"(arg3));
        M2C_FIELD(arg3, f32 *, 8) = sp58;
    }
    if (arg4 != NULL) {
        *arg4 = var_s2;
    }
    asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
    if (arg5 != 0) {
        asm volatile("vmul.xyz vf1, vf3, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf3, Q");
        asm volatile("sqc2 vf1, (%0)" : : "r"(arg5));
    }
}
}
