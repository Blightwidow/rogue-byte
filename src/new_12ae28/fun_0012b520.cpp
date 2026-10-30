typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct Bytes8 { u8 bytes[8]; };
struct _m2c_stack_func_0012B520 {};                 /* size 0x0 */
void func_0012B520(s8 *arg0, s8 *arg1) {
    s8 *temp_a3;
    s8 *temp_t0;
    M2C_FIELD(arg1, s16 *, 0x9A) = 2;
    temp_a3 = arg1 + 0xD0;
    M2C_FIELD(arg1, f32 *, 0x84) = 1.0f;
    temp_t0 = arg1 + 0xF0;
    M2C_FIELD(arg1, s32 *, 0x88) = (s32) (arg1 + 0x80);
    M2C_FIELD(arg1, s32 *, 0x8C) = (s32) (arg1 + 0x84);
    M2C_FIELD(arg1, s32 *, 0x80) = 0;
    struct V3 { f32 x, y, z; };
    M2C_FIELD(arg1, V3 *, 0xC0) = M2C_FIELD(arg0, V3 *, 4);
    M2C_FIELD(arg1, s128 *, 0xE0) = (s128) M2C_FIELD(arg1, s128 *, 0xC0);
    M2C_FIELD(temp_a3, s32 *, 8) = 0;
    M2C_FIELD(temp_a3, s32 *, 4) = 0;
    M2C_FIELD(arg1, s32 *, 0xD0) = 0;
    M2C_FIELD(temp_t0, s32 *, 8) = 0;
    M2C_FIELD(temp_t0, s32 *, 4) = 0;
    M2C_FIELD(arg1, s32 *, 0xF0) = 0;
}
}
