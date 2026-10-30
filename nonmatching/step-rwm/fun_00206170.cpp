typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00206170 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ M2C_UNK sp4;                         /* inferred */
    /* 0x04 */ char pad4[0x2C];
};                                                  /* size = 0x30 */
void func_00206170(s8 *arg0) {
    M2C_UNK sp4;
    s8 *temp_v0;
    s8 *temp_v1;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK), 0xD4)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xD0), 0);
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK, s32), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 0xE, 1, 1, &sp4, 0, 0);
}
}
