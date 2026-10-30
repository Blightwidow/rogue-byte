typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BuildJmpEdgeProbes {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x30];
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ char pad90[0x90];
};                                                  /* size = 0x120 */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
extern s128 g_2a2dc0;
void BuildJmpEdgeProbes(s8 *arg0, s32 arg1, s32 arg2, s8 *arg3) {
    s8 sp[0x80] __attribute__((aligned(16)));
    M2C_UNK sp40;
    s128 sp70;
    s128 sp80;
    M2C_UNK32 temp_f3;
    f32 temp_f12;
    f32 temp_f2;
    s32 temp_s0_4;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s0_3;
    s8 *var_s0_2;
    var_s1 = 8;
    temp_s0 = arg3 + 0x10;
    temp_s0_2 = temp_s0 + 0x10;
    temp_s0_3 = temp_s0_2 + 0x10;
    M2C_FIELD(arg3, f32 *, 0) = (f32) M2C_FIELD(arg0, f32 *, 0x114);
    var_s0 = (s32)(temp_s0_3 + 0x10);
    M2C_FIELD(arg3, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x11C);
    M2C_FIELD(arg3, s32 *, 4) = 0;
    M2C_FIELD(arg3, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x114);
    M2C_FIELD(temp_s0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x118);
    M2C_FIELD(temp_s0, s32 *, 4) = 0;
    M2C_FIELD(temp_s0, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x108);
    M2C_FIELD(temp_s0_2, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x110);
    M2C_FIELD(temp_s0_2, s32 *, 4) = 0;
    M2C_FIELD(temp_s0_3, M2C_UNK32 *, 4) = 0;
    M2C_FIELD(temp_s0_2, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x114);
    M2C_FIELD(temp_s0_3, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x11C);
    temp_f3 = M2C_FIELD(temp_s0_3, M2C_UNK32 *, 4);
    temp_f2 = M2C_FIELD(arg0, f32 *, 0x108);
    s64 vu_1;
    asm volatile("pextlw %0, %1, %0" : "=r"(vu_1) : "r"(temp_f3), "r"(temp_f2));
    s64 vu_2;
    asm volatile("pcpyld %0, %1, %0" : "=r"(vu_2) : "r"(M2C_FIELD(arg0, f32 *, 0x110)), "r"(vu_1));
    sp70 = vu_2;
    s64 vu_3;
    asm volatile("pextlw %0, %1, %0" : "=r"(vu_3) : "r"(temp_f3), "r"(temp_f2));
    s64 vu_4;
    asm volatile("pcpyld %0, %1, %0" : "=r"(vu_4) : "r"(M2C_FIELD(arg0, f32 *, 0x10C)), "r"(vu_3));
    sp80 = vu_4;
    do {
        temp_f12 = (f32) (var_s1 - 4);
        var_s1 -= 1;
        LoadRotateMatrixRad(&sp40, g_2a2dc0, temp_f12 * 0.2617994f);
        asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(sp));
        temp_v0 = var_s0;
        asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
        temp_s0_4 = var_s0 + 0x10;
        asm volatile("lqc2 vf2, 0x60(%0)" : : "r"(sp));
        temp_v1 = temp_s0_4;
        asm volatile("lqc2 vf5, 0x70(%0)" : : "r"(sp));
        var_s0 = temp_s0_4 + 0x10;
        asm volatile("vmulax.xyz ACC, vf3, vf5x");
        asm volatile("vmadday.xyz ACC, vf1, vf5y");
        asm volatile("vmaddz.xyz vf4, vf2, vf5z");
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
        asm volatile("sqc2 vf4, (%0)" : : "r"(temp_v0));
        asm volatile("lqc2 vf4, 0x80(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf2, vf4x");
        asm volatile("vmadday.xyz ACC, vf3, vf4y");
        asm volatile("vmaddz.xyz vf2, vf1, vf4z");
        asm volatile("sqc2 vf2, (%0)" : : "r"(temp_v1));
    } while (var_s1 >= 0);
    var_s1_2 = arg2 - 1;
    var_s0_2 = arg3;
    if (var_s1_2 >= 0) {
        do {
            asm volatile("lqc2 vf5, (%0)" : : "r"(var_s0_2));
            var_s1_2 -= 1;
            asm volatile("lqc2 vf2, (%0)" : : "r"(arg1));
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(arg1));
            asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(arg1));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(arg1));
            asm volatile("vmulax.xyz ACC, vf2, vf5x");
            asm volatile("vmadday.xyz ACC, vf4, vf5y");
            asm volatile("vmaddaz.xyz ACC, vf3, vf5z");
            asm volatile("vmaddw.xyz vf2, vf1, vf0w");
            asm volatile("sqc2 vf2, (%0)" : : "r"(var_s0_2));
            var_s0_2 += 0x10;
        } while (var_s1_2 >= 0);
    }
}
}
