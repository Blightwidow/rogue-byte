typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddImage__4GIFSi {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
void AddImage__4GIFSi(s8 *arg0, s32 arg1) {
    s8 *temp_v0;
    s8 *temp_v0_2;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0x18);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8), 0);
    temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(arg0, s8 **, 0xC) = (s8 *) (temp_v0_2 + 0x10);
    M2C_FIELD(temp_v0_2, s64 *, 0) = (s64) (arg1 | (0x8000 << 0x2C));
    M2C_FIELD(temp_v0_2, s64 *, 8) = 0;
}
}
