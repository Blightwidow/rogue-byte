typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CloneGeom {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ char pad50[0x50];
};                                                  /* size = 0xA0 */
M2C_UNK InitPlaneFromNormalPos(s8 *, M2C_UNK, s128); /* extern */
s32 PvAllocSwCopyImpl__FiPv(s8 *, s32, s32, s32); /* extern */
void CloneGeom(s8 *arg0, s8 *arg1, s8 *arg2) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a3;
    s32 var_s0;
    s8 *temp_v0_2;
    M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg2, s32 *, 4) = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0) * 0x10, 0x10);
    M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg2, s32 *, 0xC) = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s32 *, 0xC), M2C_FIELD(arg0, s32 *, 8) << 5, 0x10);
    M2C_FIELD(arg2, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
    M2C_FIELD(arg2, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
    if (arg1 != NULL) {
        var_a3 = 0;
        sp10 = M2C_FIELD(arg1, s128 *, 0);
        sp20 = M2C_FIELD(arg1, s128 *, 0x10);
        sp30 = M2C_FIELD(arg1, s128 *, 0x20);
        sp40 = M2C_FIELD(arg1, s128 *, 0x30);
        if (M2C_FIELD(arg2, s32 *, 0) > 0) {
loop_3:
            temp_v0 = var_a3 * 0x10;
            asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
            var_a3 += 1;
            temp_v1 = M2C_FIELD(arg2, s32 *, 4) + temp_v0;
            asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(sp));
            asm volatile("lqc2 vf4, (%0)" : : "r"(temp_v1));
            asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf3, vf4x");
            asm volatile("vmadday.xyz ACC, vf5, vf4y");
            asm volatile("vmaddaz.xyz ACC, vf2, vf4z");
            asm volatile("vmaddw.xyz vf3, vf1, vf0w");
            asm volatile("sqc2 vf3, (%0)" : : "r"(temp_v1));
            if (var_a3 < M2C_FIELD(arg2, s32 *, 0)) {
                goto loop_3;
            }
        }
        var_s0 = 0;
        if (M2C_FIELD(arg2, s32 *, 8) > 0) {
            do {
                temp_v1_2 = var_s0 << 5;
                asm volatile("lqc2 vf6, 0x10(%0)" : : "r"(sp));
                var_s0 += 1;
                temp_v0_2 = (s8 *)(M2C_FIELD(arg2, s32 *, 0xC) + temp_v1_2);
                asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(&sp10));
                asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v0_2));
                asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(&sp10));
                asm volatile("vmulax.xyz ACC, vf6, vf1x");
                asm volatile("vmadday.xyz ACC, vf5, vf1y");
                asm volatile("vmaddz.xyz vf1, vf4, vf1z");
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
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
                InitPlaneFromNormalPos(temp_v0_2, vu_1, *(s32 *)((M2C_FIELD(temp_v0_2, s32 *, 0x1C) * 0x10) + M2C_FIELD(arg2, s32 *, 4)));
            } while (var_s0 < M2C_FIELD(arg2, s32 *, 8));
        }
    }
}
}
