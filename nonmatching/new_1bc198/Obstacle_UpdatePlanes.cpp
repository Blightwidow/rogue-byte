typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Obstacle_UpdatePlanes {
    /* 0x00 */ char pad0[0xB0];
};                                                  /* size = 0xB0 */
M2C_UNK InitPlaneFromNormalPos(s32, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK g_2a2dc0;
void Obstacle_UpdatePlanes(s8 *arg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s32 temp_a0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s8 *temp_v0;
    s8 *temp_v1;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0x50);
    var_s3 = 0;
    if (temp_v0 != NULL) {
        var_s3 = M2C_FIELD(temp_v0, s32 *, 0xA4);
    }
    var_s1 = 1;
    if (M2C_FIELD(arg0, s32 *, 0x1E8) != var_s3) {
        temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
        temp_v0_2 = M2C_FIELD(temp_v1, s32 (**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
        asm volatile("lqc2 vf5, (%0)" : : "r"(temp_v0_2));
        asm volatile("sqc2 vf5, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(temp_v0_2));
        asm volatile("sqc2 vf4, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0_2));
        asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(temp_v0_2));
        asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(M2C_FIELD(arg0, s32 *, 0xF4)));
        asm volatile("vmulax.xyz ACC, vf5, vf1x");
        asm volatile("vmadday.xyz ACC, vf4, vf1y");
        asm volatile("vmaddaz.xyz ACC, vf3, vf1z");
        asm volatile("vmaddw.xyz vf5, vf2, vf0w");
        if (M2C_FIELD(arg0, s32 *, 0xE8) > 1) {
            var_s2 = 0;
            do {
                asm volatile("vmove.xyzw vf2, vf5");
                asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                asm volatile("lqc2 vf5, (%0)" : : "r"((var_s1 * 0x10) + M2C_FIELD(arg0, s32 *, 0xF4)));
                temp_a0 = M2C_FIELD(arg0, s32 *, 0x1EC) + var_s2;
                asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
                var_s1 += 1;
                asm volatile("lqc2 vf7, (%0)" : : "r"(sp));
                var_s2 += 0x10;
                asm volatile("lqc2 vf6, 0x10(%0)" : : "r"(sp));
                asm volatile("vmulax.xyz ACC, vf7, vf5x");
                asm volatile("vmadday.xyz ACC, vf6, vf5y");
                asm volatile("vmaddaz.xyz ACC, vf3, vf5z");
                asm volatile("vmaddw.xyz vf5, vf1, vf0w");
                asm volatile("lqc2 vf4, (%0)" : : "r"(&g_2a2dc0));
                asm volatile("vsub.xyzw vf2, vf5, vf2");
                asm volatile("vopmula.xyz ACC, vf2, vf4");
                asm volatile("vopmsub.xyz vf2, vf4, vf2");
                asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
                asm volatile("vmul.xyz vf1, vf2, vf2");
                asm volatile("vaddw.x vf3, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf3, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf3, vf2, Q");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
                InitPlaneFromNormalPos(temp_a0, vu_2, vu_1);
                asm volatile("lqc2 vf5, 0x40(%0)" : : "r"(sp));
            } while (var_s1 < M2C_FIELD(arg0, s32 *, 0xE8));
        }
        M2C_FIELD(arg0, s32 *, 0x1E8) = var_s3;
    }
}
}
