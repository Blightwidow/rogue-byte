typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetSmaSvt {
    /* 0x00 */ s8 *sp0;                           /* inferred */
    /* 0x04 */ char pad4[0x3C];
};                                                  /* size = 0x40 */
s32 FSmaRetracted();                                /* extern */
M2C_UNK SetAsegaSpeed(s32, f32);                    /* extern */
void SetSmaSvt(s8 *arg0, f32 fparg0) {
    s8 *sp0;
    s32 temp_a0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    if (FSmaRetracted() == 0) {
        sp0 = arg0;
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x30);
        M2C_FIELD(arg0, f32 *, 0x44) = fparg0;
        if (temp_a0 != 0) {
            SetAsegaSpeed(temp_a0, fparg0);
        }
        temp_v0_2 = M2C_FIELD(sp0, s8 **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *), 0x14)(sp0 + M2C_FIELD(temp_v0_2, s16 *, 0x10), sp0);
    }
}
}
