typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ M2C_UNK sp50;                       /* inferred */
    /* 0x050 */ char pad50[0x40];
    /* 0x090 */ M2C_UNK sp90;                       /* inferred */
    /* 0x090 */ char pad90[0x40];
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ char padF0[0x40];                   /* maybe part of spE0[5]? */
    /* 0x130 */ s128 sp130;                         /* inferred */
    /* 0x140 */ char pad140[0x80];
};                                                  /* size = 0x1C0 */
#define spE0 (*(s128 *)(sp + 0x0E0))
#define sp130 (*(s128 *)(sp + 0x130))
s32 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s128 *, f32); /* extern */
f32 *PeaFindAsegLabel(s32, M2C_UNK);                /* extern */
M2C_UNK PredictAsegEffect(s32, s8 *, s8 *, s32, M2C_UNK *, M2C_UNK, f32, M2C_UNK); /* extern */
extern M2C_UNK g_2a2dc0;
extern s32 g_2bf340;
extern s32 g_2bf344;
void RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG(s8 *arg0, s8 *arg1, s8 *arg2, s8 *arg4, f32 fparg0) {
    s8 sp[0x120] __attribute__((aligned(16)));
    M2C_UNK sp50;
    M2C_UNK sp90;
    s128 spD0;
    M2C_UNK temp_a0;
    f32 *temp_v0;
    f32 temp_f12;
    f32 var_f21;
    s32 temp_v1;
    s32 temp_v1_2;
    s8 *temp_v0_2;
    s8 *var_s1;
    if (M2C_FIELD(arg0, s32 *, 0x18C8) == 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x18D8);
        if (temp_v1 >= 6) {
            if (temp_v1 < 0xA) {
                var_s1 = M2C_FIELD(arg0, s8 **, 0x18E0);
            } else if ((temp_v1 < 0xE) && (temp_v1 >= 0xC)) {
                var_s1 = M2C_FIELD(arg0, s8 **, 0x18E0);
            } else {
                goto block_8;
            }
        } else {
block_8:
            goto block_12;
        }
    } else if (M2C_FIELD(arg0, s8 **, 0x1034) == NULL) {
        var_s1 = M2C_FIELD(arg0, s8 **, 0x1030);
    } else {
block_12:
        var_s1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1034), s8 **, 0x30);
    }
    temp_v1_2 = M2C_FIELD(var_s1, s32 *, 0x14);
    if (temp_v1_2 != M2C_FIELD(arg4, s32 *, 0)) {
        M2C_FIELD(arg4, s32 *, 0) = temp_v1_2;
        var_f21 = 0.0f;
        temp_v0 = PeaFindAsegLabel(M2C_FIELD(var_s1, s32 *, 0x14), 0x16A);
        if (temp_v0 != NULL) {
            var_f21 = *temp_v0;
        }
        PredictAsegEffect(M2C_FIELD(var_s1, s32 *, 0x14), arg0, arg1, M2C_FIELD(arg0, s32 *, 0x60), (M2C_UNK *)(sp), 0, var_f21, 0);
        asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(-fparg0));
        asm volatile("vadda.xyzw ACC, vf0, vf3");
        asm volatile("vmaddx.xyzw vf4, vf1, vf2x");
        asm volatile("sqc2 vf4, 0x130(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
        PredictAsegEffect(M2C_FIELD(var_s1, s32 *, 0x14), arg0, arg2, M2C_FIELD(arg0, s32 *, 0x60), &sp50, 0, var_f21, 0);
        PredictAsegEffect(M2C_FIELD(var_s1, s32 *, 0x14), arg0, M2C_FIELD(M2C_FIELD(arg2, s8 **, 0xA8), s8 **, 0), M2C_FIELD(arg0, s32 *, 0x60), &sp90, 0, var_f21, 0);
        asm volatile("lqc2 vf4, 0xb0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf6, 0xa0(%0)" : : "r"(M2C_FIELD(arg2, s8 **, 0xA8)));
        asm volatile("lqc2 vf2, 0xc0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, 0xa0(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf3, vf6x");
        asm volatile("vmadday.xyz ACC, vf5, vf6y");
        asm volatile("vmaddaz.xyz ACC, vf4, vf6z");
        asm volatile("vmaddw.xyz vf3, vf2, vf0w");
        asm volatile("lqc2 vf2, 0x130(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf8" : : "r"(g_2bf340));
        asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf3, vf2, vf3");
        asm volatile("vadd.xyzw vf1, vf1, vf3");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_a0 = vu_1;
        asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(arg4));
        asm volatile("qmtc2.ni %0, vf7" : : "r"(g_2bf344));
        temp_v0_2 = M2C_FIELD(arg2, s8 **, 0xA8);
        asm volatile("sqc2 vf8, 0x40(%0)" : : "r"(sp));
        asm volatile("sqc2 vf7, 0x40(%0)" : : "r"(sp));
        temp_f12 = M2C_FIELD(temp_v0_2, f32 *, 0xC0) + M2C_FIELD(temp_v0_2, f32 *, 0xC4) + 10.0f;
        M2C_FIELD(arg4, f32 *, 8) = temp_f12;
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("lqc2 vf4, 0x130(%0)" : : "r"(sp));
        asm volatile("vadda.xyzw ACC, vf0, vf2");
        asm volatile("vmaddx.xyzw vf2, vf1, vf7x");
        asm volatile("vadda.xyzw ACC, vf0, vf4");
        asm volatile("vmaddx.xyzw vf4, vf1, vf8x");
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
        M2C_FIELD(arg4, s32 *, 4) = (s32) (ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(temp_a0, vu_3, vu_2, 1, &spD0, temp_f12) > 0);
        M2C_FIELD(arg4, s128 *, 0x30) = spD0;
        M2C_FIELD(arg4, s128 *, 0x10) = sp130;
        M2C_FIELD(arg4, s128 *, 0x40) = spE0;
        asm volatile("lqc2 vf2, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(-M2C_FIELD(arg4, f32 *, 8)));
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg4));
        asm volatile("vadda.xyzw ACC, vf0, vf1");
        asm volatile("vmaddx.xyzw vf1, vf2, vf3x");
        asm volatile("sqc2 vf3, 0x40(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(arg4));
    }
}
}
