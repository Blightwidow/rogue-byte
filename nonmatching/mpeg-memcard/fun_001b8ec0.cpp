typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001B8EC0 {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
s32 FAsegaGone(s32);                                /* extern */
s32 FJumperDone(s32);                               /* extern */
M2C_UNK SetMurrayState(s8 *, M2C_UNK);            /* extern */
M2C_UNK UpdateJumper(s32);                          /* extern */
M2C_UNK func_001B8D30(s8 *, M2C_UNK);             /* extern */
extern f32 D_FLT_002C0A30;
extern f32 D_FLT_002C0A34;
extern f32 g_2dded0;
void func_001B8EC0(s8 *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_s1;
    s32 temp_v1_2;
    s8 *temp_v1;
loop_1:
    temp_s1 = M2C_FIELD(arg0, s32 *, 0x1840);
    switch (temp_s1) {                              /* irregular */
    case 0:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x1030);
        if ((temp_a0 == 0) || (FAsegaGone(temp_a0) != 0)) {
            func_001B8D30(arg0, 1);
        }
        break;
    case 3:
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x1030);
        if ((temp_a0_2 == 0) || (FAsegaGone(temp_a0_2) != 0)) {
block_33:
block_34:
            SetMurrayState(arg0, 0);
        } else if (D_FLT_002C0A34 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x1844))) {
            temp_v1 = M2C_FIELD(arg0, s8 **, 0x150);
            if ((M2C_FIELD(temp_v1, s32 *, 0x80) == 1) && (M2C_FIELD(temp_v1, f32 *, 0x1C) > 0.0f)) {
                SetMurrayState(arg0, 0);
            }
        }
        break;
    case 1:
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x1030);
        if (temp_a0_3 != 0) {
            if (FAsegaGone(temp_a0_3) == 0) {
                if (M2C_FIELD(arg0, s32 *, 0x1908) == 0) {
                    if ((M2C_FIELD(arg0, s32 *, 0x1AC0) == 0) && (D_FLT_002C0A30 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x1844)))) {
                        func_001B8D30(arg0, 3);
                    }
                } else {
                    func_001B8D30(arg0, 2);
                }
            } else {
                goto block_34;
            }
        } else {
            goto block_33;
        }
        break;
    case 2:
        temp_a0_4 = M2C_FIELD(arg0, s32 *, 0x1900);
        if ((temp_a0_4 == 0) || (FJumperDone(temp_a0_4) != 0)) {
            if (M2C_FIELD(arg0, s32 *, 0x1AC0) != 0) {
                func_001B8D30(arg0, 0);
            } else {
                goto block_33;
            }
        } else {
            UpdateJumper(M2C_FIELD(arg0, s32 *, 0x1900));
        }
        break;
    }
    temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x1840);
    if ((temp_v1_2 != temp_s1) && (temp_v1_2 != -1)) {
        goto loop_1;
    }
}
}
