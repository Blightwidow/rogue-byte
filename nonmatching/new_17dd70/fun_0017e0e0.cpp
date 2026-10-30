typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0017E0E0 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x10];
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ char pad50[0x90];
};                                                  /* size = 0xE0 */
s128 PosLoWorld(s8 *);                            /* extern */
M2C_UNK SetGoalTarget(s32, M2C_UNK *);              /* extern */
s32 SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
f32 atan2f(s8 *, M2C_UNK, M2C_UNK);               /* extern */
s32 func_001C0B50(s32, M2C_UNK, s8 *);            /* extern */
s32 func_001C1EC0(s32, s128);                       /* extern */
M2C_UNK func_002562A8(M2C_UNK *);                   /* extern */
extern f32 D_FLT_002BE770;
extern f32 g_2be76c;
extern f32 g_2dded0;
void func_0017E0E0(s8 *arg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    M2C_UNK temp_v1;
    f32 *var_s1;
    f32 temp_f21;
    f32 temp_v0_2;
    f32 var_f20;
    s128 var_s0;
    s32 temp_s6;
    s32 var_s3;
    u32 var_s2;
    s8 *temp_v0;
    s8 *var_a0;
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) g_2dded0;
    temp_s6 = M2C_FIELD(arg0, s32 *, 0x18);
    sp30 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x38));
    sp40 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10));
    var_a0 = NULL;
    asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf1, vf1, vf2");
    temp_v0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s8 **, 0xE8);
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v1 = vu_1;
    if (temp_v0 != NULL) {
        var_a0 = M2C_FIELD(temp_v0, s8 **, 0xDC);
    }
    var_s3 = 0;
    if (var_a0 != NULL) {
        var_s3 = M2C_FIELD(var_a0, s32 *, 0x10);
    }
    var_s2 = 0;
    var_f20 = 0.0f;
    s64 vu_2;
    asm volatile("prot3w %0, %1" : "=r"(vu_2) : "r"(temp_v1));
    temp_f21 = atan2f(var_a0, vu_2, temp_v1);
    s64 vu_3;
    asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(func_001C1EC0(temp_s6 + 0x40, sp40)));
    var_s0 = vu_3;
    var_s1 = &D_FLT_002BE770;
    do {
        asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorCylind__FP6VECTORfff(temp_f21 + *var_s1, g_2be76c, 0)));
        asm volatile("vadd.xyzw vf1, vf1, vf2");
        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
        if (func_001C0B50(var_s3, vu_4, sp) != 0) {
            asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf2, vf3");
            asm volatile("vmul.xy vf1, vf1, vf1");
            asm volatile("vaddy.x vf1, vf1, vf1y");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            s32 vu_5;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_5));
            temp_v0_2 = vu_5;
            if (var_f20 < temp_v0_2) {
                var_f20 = temp_v0_2;
                s32 vu_6;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_6));
                var_s0 = vu_6;
            }
        }
        var_s2 += 1;
        var_s1 += 4;
    } while (var_s2 < 0x10U);
    func_002562A8(&sp10);
    sp20 = var_s0;
    SetGoalTarget(temp_s6, &sp10);
}
}
