typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Blot_Construct {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

M2C_UNK InitSl(s8 *, M2C_UNK);                    /* extern */
extern M2C_UNK D_002DAF30;

s8 *Blot_Construct(s8 *arg0) {
    s32 *var_v1;
    u32 var_a0;

    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002DAF30;
    M2C_FIELD(arg0, s32 *, 0x7C) = -1;
    var_a0 = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    for (; var_a0 < 10U; var_a0++)
        ((s32 *)(arg0 + 0xCC))[var_a0] = -1;
    InitSl(arg0 + 0xFC, 0x68);
    return arg0;
}

}
