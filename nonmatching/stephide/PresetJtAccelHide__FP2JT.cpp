typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PresetJtAccelHide__FP2JT {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x30];
    /* 0x40 */ f32 sp40;                            /* inferred */
    /* 0x44 */ f32 sp44;                            /* inferred */
    /* 0x48 */ char pad48[0x68];
};                                                  /* size = 0xB0 */
void AddSoAcceleration(s8 *, M2C_UNK);
void EvaluateCrvFromU(s8 *, M2C_UNK, M2C_UNK *, f32, s128);
f32 GSmooth__FfffP3SMPPf(M2C_UNK *, f32 *, M2C_UNK, f32, f32);
extern M2C_UNK D_002BF700;
extern M2C_UNK g_2dded0;
void PresetJtAccelHide__FP2JT(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK sp10;
    f32 sp40;
    f32 sp44;
    M2C_UNK temp_v0;
    f32 temp_f21;
    f32 var_f0;
    s8 *temp_a1;
    s8 *temp_s2;
    s8 *temp_v1;
    if (M2C_FIELD(arg0, s32 *, 8) == 3) {
        temp_s2 = M2C_FIELD(arg0, s8 **, 0x14);
        if (M2C_FIELD(temp_s2, s32 *, 0x1BC) != 0) {
            temp_a1 = M2C_FIELD(arg0, s8 **, 0);
            temp_v1 = M2C_FIELD(temp_a1, s8 **, 0xC);
            EvaluateCrvFromU(temp_s2, 0, &sp10, M2C_FIELD(arg0, f32 *, 0x1C), M2C_FIELD(temp_v1, s128 (**)(s8 *, s8 *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1));
            asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf1, vf3, vf1");
            asm volatile("vaddw.x vf4, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf4, vf1z");
            asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0xE8)));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            temp_v0 = vu_1;
            asm volatile("vmul.xyz vf3, vf3, vf2");
            asm volatile("vaddw.x vf4, vf0, vf0w");
            asm volatile("vadday.x ACC, vf3, vf3y");
            asm volatile("vmaddz.x vf3, vf4, vf3z");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
            temp_f21 = vu_2;
            GSmooth__FfffP3SMPPf(&D_002BF700, &sp40, temp_v0, M2C_FIELD(temp_s2, f32 *, 0x1C0), M2C_FIELD(&g_2dded0, f32 *, 4));
            GSmooth__FfffP3SMPPf(&D_002BF700, &sp44, temp_v0, -M2C_FIELD(temp_s2, f32 *, 0x1C0), M2C_FIELD(&g_2dded0, f32 *, 4));
            var_f0 = M2C_FIELD(temp_s2, f32 *, 0x1C4) * temp_f21;
            if (var_f0 < sp44) {
                var_f0 = sp44;
            } else if (sp40 < var_f0) {
                var_f0 = sp40;
            }
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(var_f0 - temp_f21));
            asm volatile("vmulx.xyzw vf1, vf1, vf2x");
            asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
            AddSoAcceleration(M2C_FIELD(arg0, s8 **, 0), vu_3);
        }
    }
}
}
