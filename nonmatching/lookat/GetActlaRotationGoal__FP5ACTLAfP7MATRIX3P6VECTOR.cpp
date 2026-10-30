typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetActlaRotationGoal__FP5ACTLAfP7MATRIX3P6VECTOR {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0x10];
    /* 0x30 */ f32 sp30;                            /* inferred */
    /* 0x34 */ f32 sp34;                            /* inferred */
    /* 0x38 */ char pad38[8];                       /* maybe part of sp34[3]? */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ char pad60[0x30];
};                                                  /* size = 0x90 */
#define sp40 (*(s128 *)(sp + 0x40))
M2C_UNK CalculateVectorPanTilt__FP6VECTORPfT1(M2C_UNK, f32 *, f32 *); /* extern */
s32 ConvertXfVec(M2C_UNK, s32, s128);               /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
s32 PosLoWorld(s32);                                /* extern */
M2C_UNK ResortXfActList(s32, s8 *);               /* extern */
s32 func_001C4AF8(M2C_UNK *, s128);                 /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;
extern s32 g_2dded4;
void GetActlaRotationGoal__FP5ACTLAfP7MATRIX3P6VECTOR(s8 *arg0) {
    s32 unksp4;
    s32 unksp8;
    s8 sp[0x30] __attribute__((aligned(16)));
    s128 sp0;                                       /* compiler-managed */
    s128 sp10;
    f32 sp30;
    f32 sp34;
    s128 sp50;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 var_f20;
    f32 var_f3;
    f32 var_f3_2;
    s128 temp_a1;
    s32 temp_a2;
    s32 var_a0;
    s32 var_v1;
    s8 *temp_a1_2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    if (M2C_FIELD(arg0, s32 *, 0x70) == 0) {
        temp_a2 = M2C_FIELD(arg0, s32 *, 0x6C);
        if (temp_a2 != -1) {
            M2C_FIELD(arg0, s32 *, 0x70) = PloFindSwObject_thunk(&B_003DD490, 0x104, temp_a2, M2C_FIELD(arg0, s32 *, 4));
        }
    }
    var_a0 = M2C_FIELD(arg0, s32 *, 0x70);
    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s128 *, 0x70);
    sp50 = temp_a1;
    if ((var_a0 != 0) || (var_a0 = func_001C4AF8(&B_003DD490, temp_a1), (var_a0 != 0))) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(var_a0)));
        asm volatile("lqc2 vf2, 0x50(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(sp));
        asm volatile("vmul.xyz vf1, vf1, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        var_f20 = vu_1;
    } else {
        var_f20 = 3.4028235e38f;
    }
    if (!(M2C_FIELD(arg0, f32 *, 0x60) < var_f20)) {
        var_v1 = M2C_FIELD(arg0, s32 *, 0x64);
    } else {
        var_v1 = M2C_FIELD(arg0, s32 *, 0x68);
    }
    if (var_v1 == M2C_FIELD(arg0, s32 *, 0xC)) {
        goto block_18;
    }
    M2C_FIELD(arg0, s32 *, 0xC) = var_v1;
    ResortXfActList(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s8 **, 8));
    temp_a1_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s8 **, 0x90);
    if (temp_a1_2 == arg0) {
block_18:
        if (M2C_FIELD(arg0, f32 *, 0x60) < var_f20) {
            sp0 = M2C_FIELD(arg0, s128 *, 0x20);
            sp10 = g_2a2dd0;
            M2C_FIELD(arg0, s32 *, 0x74) = 0;
        } else {
            s64 vu_2;
            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s32 *, 0xA0), sp40)));
            CalculateVectorPanTilt__FP6VECTORPfT1(vu_2, &sp30, &sp34);
            temp_v0 = arg0 + 0x30;
            temp_f4 = M2C_FIELD(arg0, f32 *, 0x50);
            var_f3 = M2C_FIELD(arg0, f32 *, 0x30) + (sp30 * (M2C_FIELD(temp_v0, f32 *, 4) + (sp30 * M2C_FIELD(temp_v0, f32 *, 8))));
            temp_f5 = M2C_FIELD(arg0, f32 *, 0x54);
            if (var_f3 < temp_f4) {
                var_f3 = temp_f4;
            } else if (temp_f5 < var_f3) {
                var_f3 = temp_f5;
            }
            sp30 = var_f3;
            temp_v0_2 = arg0 + 0x40;
            temp_f4_2 = M2C_FIELD(arg0, f32 *, 0x58);
            temp_f0 = M2C_FIELD(arg0, f32 *, 0x40) + (sp34 * (M2C_FIELD(temp_v0_2, f32 *, 4) + (sp34 * M2C_FIELD(temp_v0_2, f32 *, 8))));
            temp_f5_2 = M2C_FIELD(arg0, f32 *, 0x5C);
            if (temp_f0 < temp_f4_2) {
                var_f3_2 = temp_f4_2;
            } else {
                var_f3_2 = temp_f0;
                if (temp_f5_2 < temp_f0) {
                    var_f3_2 = temp_f5_2;
                }
            }
            unksp8 = sp30;
            unksp4 = -var_f3_2;
            sp34 = var_f3_2;
            sp0 = 0;
            if (M2C_FIELD(arg0, s32 *, 0x74) != 0) {
                asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, 0xc0(%0)" : : "r"(M2C_FIELD(arg0, s8 **, 8)));
                asm volatile("vsub.xyzw vf2, vf2, vf1");
                asm volatile("qmtc2.ni %0, vf3" : : "r"(g_2dded4));
                asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
                asm volatile("vdiv Q, vf0w, vf3x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf2, Q");
            } else {
                asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dd0));
            }
            asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
            M2C_FIELD(arg0, s32 *, 0x74) = 1;
        }
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s128 *, 0xC0) = (s128) sp0;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s128 *, 0xD0) = sp10;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s16 *, 0x9A) = 3;
        return;
    }
    temp_v0_3 = M2C_FIELD(temp_a1_2, s8 **, 0x18);
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *), 0x24)(temp_a1_2 + M2C_FIELD(temp_v0_3, s16 *, 0x20), temp_a1_2);
}
}
