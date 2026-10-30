typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ClipCmEye {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[4];
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ s128 sp60;                           /* inferred */
    /* 0x70 */ char pad70[0x40];
};                                                  /* size = 0xB0 */
#define sp30 (*(s128 *)(sp + 0x30))
#define sp40 (*(s128 *)(sp + 0x40))
#define sp50 (*(s128 *)(sp + 0x50))
#define sp60 (*(s128 *)(sp + 0x60))
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 SquishCmEye(s32, s32, s32, M2C_UNK *, s128, s128, f32, f32); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *, M2C_UNK, s32 *, s32 *); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BD8F0;
extern M2C_UNK D_002BD900;
extern f32 D_FLT_002BD8D8;
extern f32 D_FLT_002BD8DC;
extern M2C_UNK SvSquishCmEyeConstraint;
extern M2C_UNK func_0014F030;
extern M2C_UNK g_2dded0;
s128 ClipCmEye(s32 arg0, s128 arg1, s32 arg2) {
    s8 sp[0x70] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s32 sp14;
    s32 sp18;
    s128 sp20;
    asm volatile("qmtc2.ni %0, vf1" : : "r"(arg2));
    sp20 = arg1;
    asm volatile("qmtc2.ni %0, vf2" : : "r"(arg1));
    asm volatile("vsub.xyzw vf4, vf1, vf2");
    asm volatile("qmtc2.ni %0, vf5" : : "r"(arg1));
    asm volatile("lqc2 vf2, (%0)" : : "r"(&D_002BD8F0));
    asm volatile("vadd.xyzw vf5, vf5, vf2");
    asm volatile("qmtc2.ni %0, vf1" : : "r"(M2C_FIELD(&g_2dded0, s32 *, 0x10)));
    asm volatile("vdiv Q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf2, vf4, Q");
    asm volatile("lqc2 vf3, (%0)" : : "r"(&D_002BD900));
    asm volatile("qmtc2.ni %0, vf4" : : "r"(arg1));
    asm volatile("vadd.xyzw vf4, vf4, vf3");
    asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("sqc2 vf4, 0x50(%0)" : : "r"(sp));
    CStackFrame_Construct(&sp10);
    bevy_camera_follow_push_out(&B_003DD490, sp40, sp50, &func_0014F030, 0, &sp14, &sp18);
    asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf1, vf5, vf5");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(SquishCmEye(arg0, sp14, sp18, &SvSquishCmEyeConstraint, sp20, sp30, D_FLT_002BD8D8, vu_1 + D_FLT_002BD8DC)));
    asm volatile("qmtc2.ni %0, vf1" : : "r"(M2C_FIELD(&g_2dded0, s32 *, 0x10)));
    asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
    asm volatile("vadda.xyzw ACC, vf0, vf2");
    asm volatile("vmaddx.xyzw vf3, vf3, vf1x");
    asm volatile("sqc2 vf3, 0x60(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    CStackFrame_Destructor(&sp10, 2);
    return sp60;
}
}
