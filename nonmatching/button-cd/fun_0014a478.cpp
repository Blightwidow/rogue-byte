typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0014A478 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

s32 FFindSurfaceAlongUp(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s128); /* extern */
s128 PosLoWorld(s8 *);                            /* extern */

s32 func_0014A478(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s8 *temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 **, 0x10);
    if (M2C_FIELD(temp_a0, s32 *, 0x208) != 0) {
        return 0;
    }
    return FFindSurfaceAlongUp(sp, 1, 0, 0x42C80000, 0xC37A0000, PosLoWorld(temp_a0)) == 0;
}

}
