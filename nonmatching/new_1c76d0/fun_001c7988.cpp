typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C7988 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */

M2C_UNK func_001C7A08();                            /* extern */

void func_001C7988(s8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s8 *temp_v0;

    func_001C7A08();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x23C);
    if (temp_v1 < 0x20) {
        M2C_FIELD(arg0, s32 *, 0x23C) = (s32) (temp_v1 + 1);
        temp_v0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x240) + (temp_v1 * 0x2C));
        M2C_FIELD(arg0, s8 **, 0x244) = temp_v0;
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, s32 *, 4) = arg2;
        M2C_FIELD(temp_v0, s32 *, 0x18) = -1;
        M2C_FIELD(temp_v0, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_v0, s32 *, 0x14) = -1;
    }
}

}
