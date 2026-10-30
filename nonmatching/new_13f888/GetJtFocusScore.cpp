typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetJtFocusScore {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
s128 PosLoWorld(...);                         /* extern */
s32 SetVectorCylind__FP6VECTORfff(s8 *, f32, f32, M2C_UNK); /* extern */
extern M2C_UNK D_FLT_002BD280;
extern M2C_UNK D_FLT_002BD290;
extern M2C_UNK D_FLT_002BD2A0;
extern M2C_UNK D_FLT_002BD2B0;
extern M2C_UNK g_2bbb60;
void GetJtFocusScore(s8 *arg0, s32 arg1, s32 *arg2, f32 *arg3, f32 *arg4) {
    s8 sp[0x20] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f2;
    f32 var_f22;
    f32 var_f23;
    f32 var_f3;
    s8 *temp_a0;
    var_f23 = 0.0f;
    var_f22 = 0.0f;
    asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0, arg1, PosLoWorld(arg0))));
    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf2, vf1, vf2");
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("vmul.xy vf2, vf1, vf1");
    asm volatile("vaddy.x vf2, vf2, vf2y");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    s64 vu_2;
    asm volatile("pextuw %0, %1, %0" : "=r"(vu_2) : "r"(0), "r"(vu_1));
    temp_f21 = vu_2;
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
    temp_f20 = vu_3;
    if ((s32)arg0 == *arg2) {
        var_f22 = M2C_FIELD(&D_FLT_002BD280, f32 *, 0) + (temp_f20 * (M2C_FIELD(&D_FLT_002BD280, f32 *, 4) + (temp_f20 * M2C_FIELD(&D_FLT_002BD280, f32 *, 8))));
        var_f23 = M2C_FIELD(&D_FLT_002BD290, f32 *, 0) + (temp_f21 * (M2C_FIELD(&D_FLT_002BD290, f32 *, 4) + (temp_f21 * M2C_FIELD(&D_FLT_002BD290, f32 *, 8))));
    }
    temp_a0 = M2C_FIELD(arg0, s8 **, 0x150);
    if ((temp_a0 != NULL) && (temp_f20 > 0.0001f)) {
        asm volatile("qmtc2.ni %0, vf3" : : "r"(SetVectorCylind__FP6VECTORfff(temp_a0, M2C_FIELD(temp_a0, f32 *, 0x18), M2C_FIELD(temp_a0, f32 *, 0x1C), 0)));
        asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
        asm volatile("vmul.xyz vf1, vf3, vf4");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
        temp_f0 = vu_4 / temp_f20;
        temp_f2 = M2C_FIELD(&D_FLT_002BD2A0, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002BD2A0, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002BD2A0, f32 *, 8))));
        if (temp_f2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f3 = temp_f2;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f2) {
                var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        var_f22 += var_f3 * (M2C_FIELD(&D_FLT_002BD2B0, f32 *, 0) + (temp_f20 * (M2C_FIELD(&D_FLT_002BD2B0, f32 *, 4) + (temp_f20 * M2C_FIELD(&D_FLT_002BD2B0, f32 *, 8)))));
    }
    if (arg3 != NULL) {
        *arg3 = temp_f20 + var_f22;
    }
    if (arg4 != NULL) {
        *arg4 = temp_f21 + var_f23;
    }
}
}
