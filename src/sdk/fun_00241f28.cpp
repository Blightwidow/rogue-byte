typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00241F28 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK func_00235518(M2C_UNK);                     /* extern */
M2C_UNK func_00236960(M2C_UNK *);                   /* extern */
s32 sceSifCheckStatRpc(M2C_UNK *);                  /* extern */
extern s32 D_002C6750;
extern M2C_UNK D_002C82C0;
s32 func_00241F28(s32 arg0) {
    if (arg0 == 0) {
        if (D_002C6750 > 0) {
            func_00236960((M2C_UNK *)("S cmd wait\n"));
        }
        while (sceSifCheckStatRpc(&D_002C82C0) != 0) {
            func_00235518(0xFA0);
        }
        return 0;
    }
    return sceSifCheckStatRpc(&D_002C82C0);
}
}
