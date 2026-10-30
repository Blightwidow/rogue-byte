typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001D2490 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x20];
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ char pad40[0x20];
};                                                  /* size = 0x60 */
M2C_UNK FindCrvClosestPointFromS(s32, M2C_UNK, M2C_UNK, s8 *, M2C_UNK *, M2C_UNK, s8 *, f32); /* extern */
s128 PosLoWorld();                                  /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */
extern M2C_UNK g_2c20d0;
extern M2C_UNK g_2c20e0;
void func_001D2490(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s128 sp30;
    M2C_UNK var_v0;
    f32 temp_v0_2;
    f32 var_f3;
    s128 temp_v0;
    temp_v0 = PosLoWorld();
    sp30 = temp_v0;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0));
    FindCrvClosestPointFromS(M2C_FIELD(arg0, s32 *, 0x5AC), vu_1, 0, sp, &sp10, 0, arg0 + 0x5B0, M2C_FIELD(arg0, f32 *, 0x5B0));
    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf1, vf2, vf1");
    asm volatile("vmul.xy vf1, vf1, vf1");
    asm volatile("vaddy.x vf1, vf1, vf1y");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    temp_v0_2 = vu_2;
    var_f3 = M2C_FIELD(&g_2c20d0, f32 *, 0) + (temp_v0_2 * (M2C_FIELD(&g_2c20d0, f32 *, 4) + (temp_v0_2 * M2C_FIELD(&g_2c20d0, f32 *, 8))));
    if (var_f3 < M2C_FIELD(&g_2c20e0, f32 *, 0)) {
        var_f3 = M2C_FIELD(&g_2c20e0, f32 *, 0);
    } else if (M2C_FIELD(&g_2c20e0, f32 *, 4) < var_f3) {
        var_f3 = M2C_FIELD(&g_2c20e0, f32 *, 4);
    }
    asm volatile("qmtc2.ni %0, vf2" : : "r"(var_f3));
    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
    asm volatile("vadda.xyzw ACC, vf0, vf1");
    asm volatile("vmaddx.xyzw vf1, vf5, vf2x");
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf4, vf1, vf3");
    asm volatile("vmul.xyz vf1, vf4, vf4");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf3, vf1z");
    asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_3));
    var_v0 = vu_3;
    s32 vu_4;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
    if (!(vu_4 < 0.0001f)) {
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf2, vf4, Q");
        s32 vu_5;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_5));
        var_v0 = vu_5;
    }
    s64 vu_6;
    asm volatile("prot3w %0, %1" : "=r"(vu_6) : "r"(var_v0));
    M2C_FIELD(arg0, f32 *, 0x544) = atan2f(vu_6, var_v0);
    M2C_FIELD(arg0, f32 *, 0x550) = (f32) (M2C_FIELD(arg0, f32 *, 0x51C) * 0.75f);
}
}
