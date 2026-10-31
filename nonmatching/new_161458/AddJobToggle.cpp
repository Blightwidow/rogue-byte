typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddJobToggle {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 GrfOfState(s32);                                /* extern */
void AddJobToggle(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_v0;
    s32 temp_v1;
    s8 *temp_s0;
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x8C);
        if (temp_v1 < 0x20) {
            M2C_FIELD(temp_s0, s32 *, 0) = arg1;
            temp_s0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x90) + (temp_v1 * 0x10));
            M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (temp_v1 + 1);
            M2C_FIELD(temp_s0, s32 *, 4) = arg3;
            temp_v0 = GrfOfState(arg2);
            M2C_FIELD(temp_s0, s32 *, 8) = temp_v0;
            M2C_FIELD(temp_s0, s32 *, 0xC) = arg4;
        }
    }
}
}
