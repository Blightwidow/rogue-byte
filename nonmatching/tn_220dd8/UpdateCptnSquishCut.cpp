typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateCptnSquishCut {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ char pad40[0x60];                   /* maybe part of sp30[7]? */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ M2C_UNK spB0;                       /* inferred */
    /* 0x0B0 */ char padB0[4];
    /* 0x0B4 */ s32 spB4;                           /* inferred */
    /* 0x0B8 */ s32 spB8;                           /* inferred */
    /* 0x0BC */ f32 spBC;                           /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ char padD0[0xB0];
};                                                  /* size = 0x180 */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s128 ConvertCmScreenToWorld(M2C_UNK *, s128);       /* extern */
s128 ConvertCmWorldToScreen(M2C_UNK *, s128);       /* extern */
s32 FFindCmClearInterval(s32, s32, s128, M2C_UNK, M2C_UNK); /* extern */
s32 PosLoWorld(s32);                                /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *); /* extern */
extern M2C_UNK B_002DDF40;
extern s32 B_002DFBC4;
extern M2C_UNK B_003DD490;
extern s32 D_002C4118;
extern M2C_UNK D_002C4290;
extern f32 D_FLT_002C4110;
extern f32 D_FLT_002C4114;
extern M2C_UNK func_0014F030;
extern s128 g_2a2da0;
extern s128 g_2a2dc0;
extern f32 g_2dded0;
void UpdateCptnSquishCut(s8 *arg0) {
    s32 unksp28;
    s8 sp[0xb0] __attribute__((aligned(16)));
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 spA0;
    M2C_UNK spB0;
    s32 spB4;
    s32 spB8;
    f32 spBC;
    s128 spC0;
    M2C_UNK *var_s2;
    s128 *var_s0;
    s128 *var_s0_2;
    s128 temp_v0_2;
    s32 temp_s4;
    u32 var_s1;
    u32 var_s1_2;
    s8 *temp_v0;
    temp_s4 = M2C_FIELD(arg0, s32 *, 0);
    if (B_002DFBC4 & 2) {
        M2C_FIELD(arg0, f32 *, 0x80) = (f32) g_2dded0;
    } else {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0x10);
        if (((temp_v0 == NULL) || (M2C_FIELD(temp_v0, s32 *, 0x18C) == 0)) && (D_002C4118 == 0)) {
            if (!((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x80)) < D_FLT_002C4110)) {
                if (M2C_FIELD(&B_002DDF40, s32 *, 0x300) != 0) {
                    return;
                }
                sp0 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
                sp10 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
                spC0 = g_2a2dc0;
                spA0 = g_2a2dc0;
                asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s4)));
                asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(&B_002DDF40));
                asm volatile("vsub.xyzw vf2, vf3, vf1");
                asm volatile("lqc2 vf1, 0xc0(%0)" : : "r"(sp));
                asm volatile("vopmula.xyz ACC, vf1, vf2");
                asm volatile("vopmsub.xyz vf3, vf2, vf1");
                asm volatile("vmul.xyz vf1, vf3, vf3");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                asm volatile("qmtc2.ni %0, vf2" : : "r"(g_2a2da0));
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                if (vu_1 < 0.0001f) {
                } else {
                    asm volatile("vdiv Q, vf0w, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf2, vf3, Q");
                }
                asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
                asm volatile("vopmula.xyz ACC, vf1, vf2");
                asm volatile("vopmsub.xyz vf1, vf2, vf1");
                asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(sp));
                asm volatile("sqc2 vf1, 0x80(%0)" : : "r"(sp));
                var_s2 = &D_002C4290;
                var_s1 = 0;
                var_s0 = &sp30;
                do {
                    var_s1 += 1;
                    asm volatile("lqc2 vf4, (%0)" : : "r"(var_s2));
                    asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
                    var_s2 += 0x10;
                    asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf5, 0x80(%0)" : : "r"(sp));
                    asm volatile("vmulax.xyz ACC, vf5, vf4x");
                    asm volatile("vmadday.xyz ACC, vf3, vf4y");
                    asm volatile("vmaddz.xyz vf4, vf1, vf4z");
                    asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s4)));
                    asm volatile("vadd.xyzw vf1, vf3, vf4");
                    asm volatile("vmini.xyz vf2, vf2, vf1");
                    asm volatile("vmax.xyz vf3, vf2, vf1");
                    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                    asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
                    asm volatile("sqc2 vf1, (%0)" : : "r"(var_s0));
                    var_s0 += 0x10;
                } while (var_s1 < 5U);
                var_s0_2 = &sp30;
                CStackFrame_Construct(&spB0);
                var_s1_2 = 0;
                bevy_camera_follow_push_out(&B_003DD490, sp0, sp10, &func_0014F030);
loop_16:
                sp20 = ConvertCmWorldToScreen(&B_002DDF40, *var_s0_2);
                unksp28 = M2C_FIELD(&B_002DDF40, f32 *, 0x4C);
                temp_v0_2 = ConvertCmScreenToWorld(&B_002DDF40, sp20);
                sp20 = temp_v0_2;
                s64 vu_2;
                asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_v0_2));
                if ((FFindCmClearInterval(spB4, spB8, *var_s0_2, vu_2, 0) == 0) || !(spBC >= 1.0f)) {
                    var_s1_2 += 1;
                    var_s0_2 += 0x10;
                    if (var_s1_2 < 5U) {
                        goto loop_16;
                    }
                } else {
                    M2C_FIELD(arg0, f32 *, 0x80) = (f32) g_2dded0;
                }
                if (D_FLT_002C4114 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x80))) {
                    SetResetFlag__FP2CM(&B_002DDF40);
                }
                CStackFrame_Destructor(&spB0, 2);
            }
        }
    }
}
}
