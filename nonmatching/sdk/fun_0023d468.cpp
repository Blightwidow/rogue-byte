typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023D468 {};                 /* size 0x0 */
void func_0023D468(u64 *arg0, s8 *arg1) {
    s32 temp_a0;
    s64 temp_v1;
    u64 temp_v0;
    M2C_FIELD(arg1, s32 *, 4) = (s32) (temp_v0 >> 0x3F);
    temp_v0 = *arg0;
    temp_v1 = temp_v0 & (-1U >> 0xC);
    temp_a0 = (temp_v0 >> 0x34) & 0x7FF;
    switch (temp_a0) {                              /* irregular */
    case 0x0:
        M2C_FIELD(arg1, s32 *, 0) = 2;
        return;
    case 0x7FF:
        if (temp_v1 == 0) {
            M2C_FIELD(arg1, s32 *, 0) = 4;
            return;
        }
        if (temp_v1 & (0x8000 << 0x24)) {
            M2C_FIELD(arg1, s32 *, 0) = 1;
        } else {
            M2C_FIELD(arg1, s32 *, 0) = 0;
        }
        M2C_FIELD(arg1, s64 *, 0x10) = temp_v1;
        return;
    default:
        M2C_FIELD(arg1, s64 *, 0x10) = (s64) ((temp_v1 << 8) | (0x8000L << 0x2D));
        M2C_FIELD(arg1, s32 *, 0) = 3;
        M2C_FIELD(arg1, s32 *, 8) = (s32) (temp_a0 - 0x3FF);
        return;
    }
}
}
