typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateJtCaneInput {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 ChooseJtCaneAlternateSwing(s8 *);             /* extern */
s32 ChooseJtCaneSwing(s8 *);                      /* extern */
s32 FButtonPressedWithin(s8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetJmpState(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetJtJtcs(s8 *, s32);                     /* extern */
M2C_UNK SetJtState(s8 *, M2C_UNK, M2C_UNK);       /* extern */
void UpdateJtCaneInput(s8 *arg0) {
    s32 temp_v1;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_s1;
    u32 temp_v1_2;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x18D8);
    if ((temp_v1 < 0x16) && (temp_v1 >= 0xC) && !(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s32 *, 0x30) & 0x80)) {
        M2C_FIELD(arg0, s32 *, 0x18EC) = 0;
    }
    temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x18C8);
    var_s1 = 0;
    switch (temp_v1_2) {
    case 3:
    case 21:
    case 22:
        if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x80, 0) != 0) {
            SetJmpState(arg0 + 0x2C0, 0, 0, 0);
        }
    default:
block_21:
        if ((var_s1 != 0) && ((temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x18D8), (temp_v1_3 == -1)) || ((temp_v1_3 >= -1) && (temp_v1_3 < 0x18) && (temp_v1_3 >= 0xC) && (M2C_FIELD(arg0, s32 *, 0x18E4) != 0)))) {
            if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x10, 0x3EB33333) != 0) {
                SetJtJtcs(arg0, -1);
                SetJtJtcs(arg0, ChooseJtCaneAlternateSwing(arg0));
                return;
            }
            if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x80, 0x3EB33333) != 0) {
                SetJtJtcs(arg0, -1);
                SetJtJtcs(arg0, ChooseJtCaneSwing(arg0));
            }
        } else {
            return;
        }
        break;
    case 7:
        temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x4C8);
        if (temp_v1_4 < 5) {
            var_s1 = temp_v1_4 >= 3;
        }
        goto block_21;
    case 5:
        temp_v1_5 = M2C_FIELD(arg0, s32 *, 0x18D0);
        if (temp_v1_5 >= 6) {
            if (temp_v1_5 < 8) {
                if (!(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s32 *, 0x30) & 0x80)) {
                    if (M2C_FIELD(arg0, s32 *, 0x18E8) != 0) {
                        SetJtState(arg0, 5, 8);
                    } else {
                        SetJtState(arg0, 5, 4);
                    }
                }
                goto block_21;
            }
            var_s1 = 1;
            if (temp_v1_5 < 0xA) {
                return;
            }
            goto block_21;
        }
    case 0:
    case 1:
    case 10:
    case 12:
        var_s1 = 1;
        goto block_21;
    }
}
}
