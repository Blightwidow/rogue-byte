typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitJob {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

M2C_UNK InitLo();                                   /* extern */
M2C_UNK InitSl(s32, M2C_UNK);                       /* extern */

void InitJob(s8 *arg0) {
    InitLo();
    M2C_FIELD(arg0, f32 *, 0x9C) = 480.0f;
    M2C_FIELD(arg0, f32 *, 0xA0) = 720.0f;
    M2C_FIELD(arg0, s32 *, 0x6C) = -1;
    M2C_FIELD(arg0, s32 *, 0x70) = -1;
    M2C_FIELD(arg0, s32 *, 0xAC) = -1;
    M2C_FIELD(arg0, s32 *, 0xB0) = -1;
    M2C_FIELD(arg0, s32 *, 0xB4) = -1;
    InitSl((int)(arg0 + 0x80), 0x84);
}

}
