typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_0022C818(s32, s8 *, M2C_UNK);        /* extern */

void func_0012E010(s8 *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), f32 *, 0xA8) = (f32) M2C_FIELD(arg0, f32 *, 0x1C);
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s128 *, 0xC0) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s128 *, 0xD0) = (s128) M2C_FIELD(arg0, s128 *, 0x30);
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s16 *, 0x9A) = 2;
    func_0022C818(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s8 **, 8), 2);
}

}
