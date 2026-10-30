typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_classes_k30_cam_1507f8 {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x18];                     /* maybe part of sp4[7]? */
    /* 0x20 */ M2C_UNK sp20;                        /* inferred */
    /* 0x20 */ char pad20[0x30];
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ char pad60[0x30];
};                                                  /* size = 0x90 */
#define sp0 (*(f32 *)(sp + 0x00))
#define sp4 (*(f32 *)(sp + 0x04))
M2C_UNK LoadRotateMatrixPanTilt(M2C_UNK *, f32, f32); /* extern */
s32 PosLoWorld(s32);                                /* extern */
f32 atan2f(f32, f32);                               /* extern */
s32 bevy_classes_k30_cam_150780(s8 *);            /* extern */
extern s128 RO_002A5000;
s32 bevy_classes_k30_cam_1507f8(s8 *arg0) {
    s8 sp[0x60] __attribute__((aligned(16)));
    M2C_UNK sp20;
    s128 sp50;
    s32 temp_a0;
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x14);
    if (temp_a0 != 0) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(temp_a0)));
        asm volatile("sqc2 vf1, 0x60(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(bevy_classes_k30_cam_150780(arg0)));
        asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        asm volatile("vmul.xyz vf2, vf1, vf1");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf2, vf2y");
        asm volatile("vmaddz.x vf2, vf3, vf2z");
        asm volatile("vsqrt Q, vf2x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf2, vf0, Q");
        asm volatile("vdiv Q, vf0w, vf2x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf2, vf1, Q");
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        M2C_FIELD(arg0, f32 *, 0xA4) = atan2f(sp4, sp0);
        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(&RO_002A5000));
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf3, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        asm volatile("qmtc2.ni %0, vf3" : : "r"(bevy_classes_k30_cam_150780(arg0)));
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(-vu_1));
        asm volatile("vmulx.xyzw vf2, vf2, vf1x");
        asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("vadd.xyzw vf1, vf3, vf2");
    } else {
        sp50 = RO_002A5000;
        LoadRotateMatrixPanTilt(&sp20, M2C_FIELD(arg0, f32 *, 0xA4), M2C_FIELD(arg0, f32 *, 0xA8));
        asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x50(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf3, vf4x");
        asm volatile("vmadday.xyz ACC, vf2, vf4y");
        asm volatile("vmaddz.xyz vf1, vf1, vf4z");
        asm volatile("qmtc2.ni %0, vf2" : : "r"(bevy_classes_k30_cam_150780(arg0)));
        asm volatile("vadd.xyzw vf1, vf2, vf1");
    }
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    return vu_2;
}
}
