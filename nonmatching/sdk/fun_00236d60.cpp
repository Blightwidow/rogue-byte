typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00236D60 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
M2C_UNK func_00236CD0(void);                         /* extern */
M2C_UNK iSignalSema(s32);                           /* extern */
s32 func_00236D60(s8 *arg0) {
    s32 temp_a0;
    s32 temp_gp;
    u32 temp_v1;
    s8 *temp_s1_2;
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x20);
    if (temp_v1 != 0x8000000A) {
        if (temp_v1 <= 0x8000000AU) {
            if (temp_v1 != 0x80000009) {
            } else {
                M2C_FIELD((M2C_FIELD(arg0, s8 **, 0x1C)), s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
                M2C_FIELD((M2C_FIELD(arg0, s8 **, 0x1C)), s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
            }
        }
    } else {
        temp_s1_2 = M2C_FIELD(arg0, s8 **, 0x1C);
        if (M2C_FIELD(temp_s1_2, M2C_UNK (**)(s32), 0x1C) != NULL) {
            M2C_FIELD(temp_s1_2, M2C_UNK (**)(s32), 0x1C)(M2C_FIELD(temp_s1_2, s32 *, 0x20));
            temp_gp = M2C_FIELD(temp_s1_2, s32 *, 0x18);
        }
    }
    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1C), s32 *, 8);
    if (temp_a0 >= 0) {
        iSignalSema(temp_a0);
    }
    func_00236CD0();
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1C), s32 *, 0) = 0;
    return temp_gp;
}
}
