typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CalculateVolPan {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s32 ConvertAloVec(M2C_UNK, M2C_UNK *, M2C_UNK);     /* extern */
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
s32 PosLoWorld(s32);                                /* extern */
s32 PpoSwFocus(M2C_UNK *, s128);                    /* extern */
f32 atan2f(f32, s32);                               /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2bbb60;
extern M2C_UNK g_2ddfa0;
void CalculateVolPan(s128 arg1, s8 *arg2, f32 *arg3, s32 *arg4) {
    s8 sp[0x20] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f2;
    s32 temp_v0;
    s32 temp_v0_2;
    temp_v0 = PpoSwFocus(&B_003DD490, arg1);
    if (temp_v0 == 0) {
        asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(&B_002DDF40));
    } else {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(temp_v0)));
    }
    asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf3, vf2, vf1");
    temp_f0 = M2C_FIELD(arg2, f32 *, 4);
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_f1 = GLimitLm__FP2LMf(&g_2bbb60, (temp_f0 - vu_1) / (temp_f0 - M2C_FIELD(arg2, f32 *, 0)));
    asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
    if (arg3 != NULL) {
        *arg3 = temp_f1;
    }
    if (arg4 != NULL) {
        if (temp_f1 > 0.0f) {
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
            temp_v0_2 = ConvertAloVec(0, &g_2ddfa0, vu_2);
            s64 vu_3;
            asm volatile("prot3w %0, %1" : "=r"(vu_3) : "r"(temp_v0_2));
            var_f2 = atan2f(-vu_3, temp_v0_2);
            if (M2C_FIELD(arg2, f32 *, 4) < M2C_FIELD(arg2, f32 *, 0)) {
                var_f2 += 3.1415927f;
            }
            *arg4 = (s32) (var_f2 * 57.295776f);
            return;
        }
        *arg4 = 0;
    }
}
}
