typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateMurrayAttack {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
M2C_UNK EndMurrayAttack(s8 *);                    /* extern */
s32 FAsegaGone(s32);                                /* extern */
s32 FButtonPressedWithin(s8 *, M2C_UNK, M2C_UNK); /* extern */
s32 FMurrayAttackCanChain(s8 *);                  /* extern */
s32 FMurrayTryGrabGuard(s8 *);                    /* extern */
M2C_UNK SetMurrayAttackState(s8 *, s32);          /* extern */
M2C_UNK SetMurrayState(s8 *, M2C_UNK);            /* extern */
void UpdateMurrayAttack(s8 *arg0) {
    s32 temp_a0;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v1;
loop_1:
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x1030);
    temp_s1 = M2C_FIELD(arg0, s32 *, 0x1810);
    if (temp_a0 != 0) {
        if (FAsegaGone(temp_a0) == 0) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x1810);
            if (temp_v1 >= 0) {
                if (temp_v1 >= 2) {
                    if (temp_v1 < 4) {
                        if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x10, 0x3E800000) != 0)) {
                            SetMurrayAttackState(arg0, ((M2C_FIELD(arg0, s32 *, 0x1810) ^ 2) != 0) ? 2 : 3);
                        } else if (((FMurrayAttackCanChain(arg0) == 0) || (FMurrayTryGrabGuard(arg0) == 0)) && (M2C_FIELD(arg0, s32 *, 0x181C) != 0) && (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C) > 0.0f)) {
                            EndMurrayAttack(arg0);
                        }
                    }
                } else if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x80, 0x3E800000) != 0)) {
                    SetMurrayAttackState(arg0, M2C_FIELD(arg0, s32 *, 0x1810) == 0);
                } else if (((FMurrayAttackCanChain(arg0) == 0) || (FMurrayTryGrabGuard(arg0) == 0)) && (M2C_FIELD(arg0, s32 *, 0x181C) != 0) && (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C) > 0.0f)) {
                    EndMurrayAttack(arg0);
                }
            }
        } else {
            goto block_5;
        }
    } else {
block_5:
        SetMurrayState(arg0, 0);
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1810);
    if ((temp_v0 != temp_s1) && (temp_v0 != -1)) {
        goto loop_1;
    }
}
}
