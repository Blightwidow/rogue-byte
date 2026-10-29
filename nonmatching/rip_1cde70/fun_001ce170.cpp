typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_001F4BA8(s8 *, s8 *, M2C_UNK);     /* extern */
extern s32 B_003E115C;

void func_001CE170(s8 *arg0) {
    s8 *temp_a1;
    s8 *temp_a2;

    temp_a1 = M2C_FIELD(arg0, s8 **, 0xEC);
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0x170);
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x180);
    temp_a2 = M2C_FIELD(arg0, s8 **, 0xEC);
    M2C_FIELD(temp_a2, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x190);
    M2C_FIELD(temp_a1, f32 *, 0x30) = (f32) M2C_FIELD(arg0, f32 *, 0x1A0);
    B_003E115C = 1;
    func_001F4BA8(temp_a1, temp_a2, 1);
}

}
