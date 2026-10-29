typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PosCplookEye {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
M2C_UNK LoadRotateMatrixPanTilt(s8 *, f32, f32, s128); /* extern */
s32 PosCplookAnchor(s8 *);                        /* extern */
extern s128 RO_002A5000;
s32 PosCplookEye(s8 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    LoadRotateMatrixPanTilt(sp, M2C_FIELD(arg0, f32 *, 0x10), M2C_FIELD(arg0, f32 *, 0x14), RO_002A5000);
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf3, vf4x");
    asm volatile("vmadday.xyz ACC, vf2, vf4y");
    asm volatile("vmaddz.xyz vf1, vf1, vf4z");
    asm volatile("qmtc2.ni %0, vf2" : : "r"(PosCplookAnchor(arg0)));
    asm volatile("vadd.xyzw vf2, vf2, vf1");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
    return vu_1;
}
}
