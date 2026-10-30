typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C8350 {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
s32 FIsJsgActive(s32);                              /* extern */
M2C_UNK SetVaultOpen(M2C_UNK);                      /* extern */
M2C_UNK UpdateSo();                                 /* extern */
M2C_UNK func_001C84D8(s8 *);                      /* extern */
M2C_UNK func_001C8730(s8 *, M2C_UNK);             /* extern */
void func_001C8350(s8 *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    UpdateSo();
loop_1:
    switch (M2C_FIELD(arg0, s32 *, 0x180)) {        /* irregular */
    case 1:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x19C);
        if ((temp_a0 == 0) || (FIsJsgActive(temp_a0) == 0)) {
            func_001C8730(arg0, 2);
        }
        break;
    case 3:
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x19C);
        if ((temp_a0_2 == 0) || (FIsJsgActive(temp_a0_2) == 0)) {
            SetVaultOpen(1);
            func_001C8730(arg0, 5);
        }
        break;
    case 4:
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x19C);
        if ((temp_a0_3 == 0) || (FIsJsgActive(temp_a0_3) == 0)) {
            func_001C8730(arg0, 0);
        }
        break;
    case 2:
        temp_a0_4 = M2C_FIELD(arg0, s32 *, 0x19C);
        if ((temp_a0_4 == 0) || (FIsJsgActive(temp_a0_4) == 0)) {
            if (M2C_FIELD(arg0, s32 *, 0x198) == M2C_FIELD(arg0, s32 *, 0x1F0)) {
                func_001C8730(arg0, 3);
            } else {
                func_001C8730(arg0, 4);
            }
        } else {
            func_001C84D8(arg0);
        }
        break;
    }
    if (M2C_FIELD(arg0, s32 *, 0x180) != M2C_FIELD(arg0, s32 *, 0x180)) {
        goto loop_1;
    }
}
}
