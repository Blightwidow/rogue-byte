typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FGadgetOnSale {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

s32 NEpisodeBest(void);                     /* extern */
extern M2C_UNK D_002BCD00;

s32 FGadgetOnSale(s32 arg0) {
    s32 temp_a0;
    s8 *temp_s0;

    temp_a0 = arg0 << 5;
    temp_s0 = (s8 *)(temp_a0 + &D_002BCD00);
    if (M2C_FIELD(temp_s0, s32 *, 0x10) == -1) {
        return 0;
    }
    return NEpisodeBest() >= M2C_FIELD(temp_s0, s32 *, 0x10);
}

}
