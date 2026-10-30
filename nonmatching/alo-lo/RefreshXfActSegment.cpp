typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefreshXfActSegment {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK SetXfKind(s32, s8 *, M2C_UNK);            /* extern */
M2C_UNK func_0022C818(s32, s8 *);                 /* extern */
void RefreshXfActSegment(s32 arg0, s8 *arg1) {
    f32 temp_f1;
    s16 temp_v1;
    u16 temp_v1_2;
    s8 *temp_a1;
    s8 *temp_v0;
    temp_f1 = *M2C_FIELD(arg1, f32 **, 0x88);
    if ((temp_f1 < M2C_FIELD(arg1, f32 *, 0x80)) || (M2C_FIELD(arg1, f32 *, 0x84) < temp_f1) || (M2C_FIELD(arg1, s16 *, 0x9A) >= 3)) {
        temp_a1 = M2C_FIELD(arg1, s8 **, 0x90);
        if (temp_a1 == NULL) {
            M2C_FIELD(arg1, s16 *, 0x9A) = 0;
            func_0022C818(arg0, arg1);
            SetXfKind(arg0, arg1, 0);
        } else {
            temp_v0 = M2C_FIELD(temp_a1, s8 **, 0x18);
            M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0x24)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x20), temp_a1);
            temp_v1 = M2C_FIELD(arg1, s16 *, 0x98);
            switch (temp_v1) {                      /* irregular */
            case 6:
                if ((u32) ((u16) M2C_FIELD(arg1, s16 *, 0x9A) - 3) < 2U) {
block_21:
                    SetXfKind(arg0, arg1, 7);
                    return;
                }
                break;
            case 19:
                if (M2C_FIELD(arg1, s16 *, 0x9A) != 2) {
                    SetXfKind(arg0, arg1, 0x12);
                    return;
                }
                break;
            case 10:
                temp_v1_2 = (u16) M2C_FIELD(arg1, s16 *, 0x9A);
                if ((u32) (temp_v1_2 - 3) >= 2U) {
                    if ((s16) temp_v1_2 != 2) {
                        SetXfKind(arg0, arg1, 6);
                        return;
                    }
                } else {
                    goto block_21;
                }
                break;
            case 12:
                if (M2C_FIELD(arg1, s16 *, 0x9A) != 2) {
                    SetXfKind(arg0, arg1, 0xB);
                    return;
                }
                break;
            }
        }
    }
}
}
