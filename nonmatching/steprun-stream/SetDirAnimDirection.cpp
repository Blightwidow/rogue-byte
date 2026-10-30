typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetDirAnimDirection {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
M2C_UNK ApplyAsegToHandle(s32, s32, s32, s8 *, f32, M2C_UNK); /* extern */
f32 *PeaFindAsegLabel(s32, M2C_UNK, u32);           /* extern */
M2C_UNK SubscribeLoObject(s8 *, s8 *);          /* extern */
extern f32 D_FLT_002C3DE4;
void SetDirAnimDirection(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    M2C_UNK var_a1;
    f32 *temp_v0;
    f32 var_f0;
    f32 var_f1;
    f32 var_f20;
    s32 *var_a0;
    s32 *var_s1;
    s32 temp_a1;
    u32 var_a2;
    asm volatile("qmtc2.ni %0, vf1" : : "r"(arg1));
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("vdiv Q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf3, vf1, Q");
    var_f1 = -3.4028235e38f;
    var_s1 = NULL;
    asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
    if ((M2C_FIELD(arg0, s32 *, 0x34) != 0) || (M2C_FIELD(arg0, s32 *, 0x38) != 0)) {
        asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
        var_a0 = M2C_FIELD(arg0, s32 **, 0x28);
        var_a2 = 0;
        do {
            temp_a1 = *var_a0;
            if (temp_a1 == 0) {
                var_a2 += 1;
            } else {
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(var_a0));
                asm volatile("vmul.xyz vf1, vf2, vf2");
                asm volatile("vaddw.x vf3, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf3, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf2, Q");
                asm volatile("vmul.xyz vf1, vf4, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                var_f0 = vu_1;
                if (temp_a1 == M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x24), s32 *, 0x14)) {
                    var_f0 *= D_FLT_002C3DE4;
                }
                var_a2 += 1;
                if (var_f1 < var_f0) {
                    var_f1 = var_f0;
                    var_s1 = var_a0;
                }
            }
            var_a0 += 0x30;
        } while (var_a2 < 4U);
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
        if (var_s1 != M2C_FIELD(arg0, s32 **, 0x2C)) {
            var_f20 = 0.0f;
            var_a1 = 0x17D;
            if (M2C_FIELD(arg0, s32 *, 0x34) != 0) {
            } else {
                var_a1 = 0x17F;
            }
            temp_v0 = PeaFindAsegLabel(*var_s1, var_a1, var_a2);
            if (temp_v0 != NULL) {
                var_f20 = *temp_v0;
            }
            ApplyAsegToHandle(*var_s1, M2C_FIELD(arg0, s32 *, 0x20), M2C_FIELD(arg0, s32 *, 0x30), arg0 + 0x24, var_f20, 0x3F800000);
            SubscribeLoObject(M2C_FIELD(arg0, s8 **, 0x24), arg0);
            M2C_FIELD(arg0, s32 **, 0x2C) = var_s1;
            goto block_18;
        }
    } else {
block_18:
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
    }
    asm volatile("qmtc2.ni %0, vf1" : : "r"(M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x2C), s32 *, 0x20)));
    asm volatile("vmulx.xyzw vf2, vf3, vf1x");
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(arg0));
}
}
