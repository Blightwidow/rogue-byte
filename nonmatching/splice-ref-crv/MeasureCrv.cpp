typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_MeasureCrv {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK FillCrvcCache(s8 *, s32);                 /* extern */
M2C_UNK InvalidateCrvCache();                       /* extern */
M2C_UNK RemeasureRopeSim(s32, s32);                 /* extern */
void MeasureCrv(s8 *arg0) {
    f32 var_f1;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s1;
    s8 *temp_a0;
    s8 *temp_v0;
    s8 *temp_v1;
    s8 *temp_v1_3;
    s8 *var_a1;
    InvalidateCrvCache();
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    temp_v0 = M2C_FIELD(temp_v1, s8 *(**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    asm volatile("lqc2 vf5, (%0)" : : "r"(temp_v0));
    var_a1 = M2C_FIELD(arg0, s8 **, 0xE0);
    asm volatile("sqc2 vf5, 0x100(%0)" : : "r"(arg0));
    M2C_FIELD(arg0, s128 *, 0x110) = (s128) M2C_FIELD(temp_v0, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x120) = (s128) M2C_FIELD(temp_v0, s128 *, 0x20);
    M2C_FIELD(arg0, s128 *, 0x130) = (s128) M2C_FIELD(temp_v0, s128 *, 0x30);
    if (var_a1 == NULL) {
        temp_a0 = arg0 + 0x100;
        var_a2 = 1;
        var_f1 = 0.0f;
        asm volatile("lqc2 vf4, (%0)" : : "r"(M2C_FIELD(arg0, s32 *, 0xF4)));
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_a0));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_a0));
        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(temp_a0));
        *M2C_FIELD(arg0, M2C_UNK32 **, 0xF0) = 0;
        asm volatile("vmulax.xyz ACC, vf5, vf4x");
        asm volatile("vmadday.xyz ACC, vf3, vf4y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf4z");
        asm volatile("vmaddw.xyz vf6, vf1, vf0w");
        var_a1 = temp_a0;
        if (M2C_FIELD(arg0, s32 *, 0xE8) > 1) {
            do {
                asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(var_a1));
                temp_a0_2 = var_a2 * 4;
                asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(var_a1));
                asm volatile("lqc2 vf4, (%0)" : : "r"((var_a2 * 0x10) + M2C_FIELD(arg0, s32 *, 0xF4)));
                var_a2 += 1;
                asm volatile("lqc2 vf3, 0x100(%0)" : : "r"(arg0));
                asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(var_a1));
                asm volatile("vmulax.xyz ACC, vf3, vf4x");
                asm volatile("vmadday.xyz ACC, vf5, vf4y");
                asm volatile("vmaddaz.xyz ACC, vf2, vf4z");
                asm volatile("vmaddw.xyz vf3, vf1, vf0w");
                asm volatile("vsub.xyzw vf1, vf6, vf3");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                asm volatile("vmove.xyzw vf6, vf3");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                var_f1 += vu_1;
                *(temp_a0_2 + M2C_FIELD(arg0, M2C_UNK32 **, 0xF0)) = var_f1;
            } while (var_a2 < M2C_FIELD(arg0, s32 *, 0xE8));
        }
    } else {
        *M2C_FIELD(arg0, M2C_UNK32 **, 0xF0) = 0;
        var_s1 = 0;
        if ((M2C_FIELD(arg0, s32 *, 0xE8) - 1) > 0) {
            var_a1 = NULL;
            do {
                FillCrvcCache(arg0, (s32) var_a1);
                temp_v1_2 = var_s1 * 4;
                var_s1 += 1;
                temp_v1_3 = (s8 *)(temp_v1_2 + M2C_FIELD(arg0, M2C_UNK32 **, 0xF0));
                M2C_FIELD(temp_v1_3, f32 *, 4) = (f32) (M2C_FIELD(temp_v1_3, f32 *, 0) + M2C_FIELD(arg0, f32 *, 0x174));
                var_a1 = (s8 *) var_s1;
            } while (var_s1 < (M2C_FIELD(arg0, s32 *, 0xE8) - 1));
        }
    }
    temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x17C);
    if (temp_a0_3 != 0) {
        RemeasureRopeSim(temp_a0_3, (s32) var_a1);
    }
}
}
