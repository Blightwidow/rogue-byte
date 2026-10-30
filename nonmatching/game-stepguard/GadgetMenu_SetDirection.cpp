typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GadgetMenu_SetDirection {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x40];
    /* 0x050 */ f32 sp50;                           /* inferred */
    /* 0x054 */ char pad54[0x1C];                   /* maybe part of sp50[8]? */
    /* 0x070 */ f32 sp70;                           /* inferred */
    /* 0x074 */ f32 sp74;                           /* inferred */
    /* 0x078 */ char pad78[0xD8];
};                                                  /* size = 0x150 */
#define sp50 (*(f32 *)(sp + 0x050))
M2C_UNK ClosestPointOnSegment(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, s128); /* extern */
s8 *GadgetMenu_PgmeFind(s32);                     /* extern */
M2C_UNK GadgetMenu_SelectGadget(s8 *, s32);       /* extern */
M2C_UNK Menu_ClearDialog(s8 *);                   /* extern */
s32 NewEmitter(M2C_UNK);                            /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
extern f32 g_2c3274;
extern f32 g_2c3278;
extern f32 g_2c327c;
extern f32 g_2c3280;
extern f32 g_2ddf0c;
void GadgetMenu_SetDirection(s8 *arg0, s32 arg1) {
    s8 sp[0xb0] __attribute__((aligned(16)));
    M2C_UNK sp10;
    f32 sp70;
    f32 sp74;
    f32 var_f0;
    f32 var_f21;
    s128 temp_a1_2;
    s128 temp_s0;
    s32 temp_a1;
    s32 var_s2;
    s32 var_s5;
    s8 *temp_s1;
    s8 *temp_v0;
    s8 *temp_v1;
    if ((arg1 != M2C_FIELD(arg0, s32 *, 0x28)) && (M2C_FIELD(arg0, s32 *, 0x28) = arg1, M2C_FIELD(arg0, f32 *, 0x2C) = (f32) g_2ddf0c, (arg1 != -1))) {
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x48);
        if (temp_a1 != -1) {
            temp_v0 = GadgetMenu_PgmeFind(temp_a1);
            temp_v1 = M2C_FIELD(arg0, s8 **, 0x10);
            s64 vu_1;
            asm volatile("pextlw %0, %1, %0" : "=r"(vu_1) : "r"(M2C_FIELD(temp_v0, f32 *, 0x18) * g_2c3280), "r"(M2C_FIELD(temp_v0, f32 *, 0x14)));
            s64 vu_2;
            asm volatile("pcpyld %0, %1, %0" : "=r"(vu_2) : "r"(0), "r"(vu_1));
            temp_a1_2 = vu_2;
            if (temp_v1 != NULL) {
                s64 vu_3;
                asm volatile("pextlw %0, %1, %0" : "=r"(vu_3) : "r"(-M2C_FIELD(temp_v1, f32 *, 0x1040)), "r"(M2C_FIELD(temp_v1, f32 *, 0x103C)));
                s64 vu_4;
                asm volatile("pcpyld %0, %1, %0" : "=r"(vu_4) : "r"(0), "r"(vu_3));
                asm volatile("qmtc2.ni %0, vf3" : : "r"(vu_4));
            } else {
                asm volatile("vsub.xyzw vf3, vf0, vf0");
            }
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
            asm volatile("qmtc2.ni %0, vf2" : : "r"(g_2c3274));
            var_s5 = -1;
            asm volatile("vmulx.xyzw vf3, vf1, vf2x");
            asm volatile("sqc2 vf3, 0x80(%0)" : : "r"(sp));
            var_s2 = 0;
            var_f21 = 3.4028235e38f;
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            if (M2C_FIELD(arg0, s32 *, 0x4C) > 0) {
                asm volatile("qmtc2.ni %0, vf1" : : "r"(temp_a1_2));
loop_8:
                temp_s1 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x50) + (var_s2 << 5));
                if ((temp_s1 != temp_v0) && (M2C_FIELD(temp_s1, s32 *, 0x1C) & 4)) {
                    asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(sp));
                    asm volatile("vadd.xyzw vf2, vf1, vf2");
                    s64 vu_5;
                    asm volatile("pextlw %0, %1, %0" : "=r"(vu_5) : "r"(M2C_FIELD(temp_s1, f32 *, 0x18) * g_2c3280), "r"(M2C_FIELD(temp_s1, f32 *, 0x14)));
                    s64 vu_6;
                    asm volatile("pcpyld %0, %1, %0" : "=r"(vu_6) : "r"(0), "r"(vu_5));
                    temp_s0 = vu_6;
                    asm volatile("sqc2 vf1, 0x90(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(sp));
                    s32 vu_7;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_7));
                    s32 vu_8;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_8));
                    s64 vu_9;
                    asm volatile("por %0, %1, %2" : "=r"(vu_9) : "r"(0), "r"(temp_s0));
                    if (ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(vu_9, vu_8, vu_7, 1, g_2c3278, temp_s0) > 0) {
                        var_f0 = sp50 * g_2c3274;
                        goto block_15;
                    }
                    asm volatile("lqc2 vf3, 0x80(%0)" : : "r"(sp));
                    asm volatile("vadd.xyzw vf3, vf1, vf3");
                    asm volatile("sqc2 vf1, 0x90(%0)" : : "r"(sp));
                    s32 vu_10;
                    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_10));
                    s32 vu_11;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_11));
                    s64 vu_12;
                    asm volatile("por %0, %1, %2" : "=r"(vu_12) : "r"(0), "r"(temp_s0));
                    ClosestPointOnSegment(vu_12, vu_11, vu_10, 0);
                    asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(sp));
                    if ((sp74 < g_2c327c) && (sp70 > 0.0f)) {
                        var_f0 = g_2c3274 + sp74;
block_15:
                        if (var_f0 < var_f21) {
                            var_s5 = M2C_FIELD(temp_s1, s32 *, 0);
                            var_f21 = var_f0;
                        }
                    }
                }
                var_s2 += 1;
                if (var_s2 < M2C_FIELD(arg0, s32 *, 0x4C)) {
                    goto loop_8;
                }
            }
            if (var_s5 != -1) {
                GadgetMenu_SelectGadget(arg0, var_s5);
                Menu_ClearDialog(arg0);
                SetEmitterUnpositioned(NewEmitter(0x35), 0);
            }
        }
    }
}
}
