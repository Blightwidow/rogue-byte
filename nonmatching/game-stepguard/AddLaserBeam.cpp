typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddLaserBeam {};                  /* size 0x0 */
void AddLaserBeam(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5) {
    s32 temp_v1;
    s8 *temp_a5;
    s8 *temp_a5_2;
    s8 *temp_v0;
    s8 *temp_v1_2;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x198);
    if (temp_v1 < 0x40) {
        temp_v0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x19C) + (temp_v1 * 0x150));
        M2C_FIELD(temp_v0, f32 *, 0x18) = fparg0;
        temp_a5 = temp_v0 + 0x18;
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_a5, s32 *, 0xC) = arg2;
        M2C_FIELD(temp_a5, f32 *, 4) = fparg1;
        M2C_FIELD(temp_a5, f32 *, 8) = fparg2;
        temp_v1_2 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x19C) + (M2C_FIELD(arg0, s32 *, 0x198) * 0x150));
        M2C_FIELD(temp_v1_2, f32 *, 0xB8) = fparg3;
        temp_a5_2 = temp_v1_2 + 0xB8;
        M2C_FIELD(temp_v1_2, s32 *, 0xA0) = arg3;
        M2C_FIELD(temp_a5_2, s32 *, 0xC) = arg4;
        M2C_FIELD(temp_a5_2, f32 *, 4) = fparg4;
        M2C_FIELD(temp_a5_2, f32 *, 8) = fparg5;
        M2C_FIELD(arg0, s32 *, 0x198) = (s32) (M2C_FIELD(arg0, s32 *, 0x198) + 1);
    }
}
}
