typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023A420 {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
M2C_UNK func_00239CD8(s32);                         /* extern */
M2C_UNK func_00239E68(s32);                         /* extern */
M2C_UNK func_00239EF0(s32, s64);                         /* extern */
s32 func_0023A1D0();                                /* extern */
extern M2C_UNK D_002C5A30;
s32 func_0023A420(u32 arg0, s64 arg1, s32 arg2, s32 arg3) {
    s32 saved_reg_gp;
    s32 temp_s0;
    temp_s0 = (arg0 >> 0xA) << 6;
    if ((s32) arg0 >= 0) {
        if ((arg0 & 0x3FF) == M2C_FIELD(temp_s0, s32 *, 8)) {
            if (M2C_FIELD(&D_002C5A30, s32 *, 0x1C) != arg0) {
                if (M2C_FIELD(temp_s0, s32 *, 0xC) & 2) {
                    func_00239EF0(temp_s0, arg1);
                }
                M2C_FIELD(temp_s0, s32 *, 0x28) = arg2;
                if (arg2 == 0) {
                    M2C_FIELD(temp_s0, s32 *, 0xC) = (s32) (M2C_FIELD(temp_s0, s32 *, 0xC) & 0xFFFFFFFD);
                } else {
                    M2C_FIELD(temp_s0, s64 *, 0x20) = arg1;
                    M2C_FIELD(temp_s0, s32 *, 0xC) = (s32) (M2C_FIELD(temp_s0, s32 *, 0xC) | 2);
                    M2C_FIELD(temp_s0, s32 *, 0x2C) = (s32) saved_reg_gp;
                    M2C_FIELD(temp_s0, s32 *, 0x30) = arg3;
                    if (M2C_FIELD(temp_s0, s32 *, 0xC) & 1) {
                        func_00239E68(temp_s0);
                    }
                }
                func_00239CD8(func_0023A1D0());
                return 0;
            }
            return 0x80000010;
        }
        goto block_4;
    }
block_4:
    return 0x80008002;
}
}
