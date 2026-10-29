typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PresetHbskAccel__FP4HBSKf {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */

void AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(s8 *, s8 *, M2C_UNK *, s128);
void AddSoGravityAcceleration();
s32 PmatLoWorld(s8 *);
void TiltMatUpright__FP7MATRIX3N20(s32, M2C_UNK, s8 *);
extern M2C_UNK D_002BE8D0;
extern s128 g_2a2dd0;

void PresetHbskAccel__FP4HBSKf(s8 *arg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    AddSoGravityAcceleration();
    if ((M2C_FIELD(arg0, s32 *, 0x18C) != 0) && (M2C_FIELD(arg0, s32 *, 0x17C) == 0)) {
        TiltMatUpright__FP7MATRIX3N20(PmatLoWorld(arg0), 0, sp);
        AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(arg0, sp, &D_002BE8D0, g_2a2dd0);
    }
}

}
