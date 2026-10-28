#include "m2c_macros.h"

M2C_UNK EndMurrayAttack(void *);                    /* extern */
s32 FAsegaGone(s32);                                /* extern */
s32 FButtonPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
s32 FMurrayAttackCanChain(void *);                  /* extern */
s32 FMurrayTryGrabGuard(void *);                    /* extern */
M2C_UNK SetMurrayAttackState(void *, s32);          /* extern */
M2C_UNK SetMurrayState(void *, M2C_UNK);            /* extern */

void UpdateMurrayAttack(void *arg0) {
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
                        if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x10, 0x3E800000) != 0)) {
                            SetMurrayAttackState(arg0, ((M2C_FIELD(arg0, s32 *, 0x1810) ^ 2) != 0) ? 2 : 3);
                        } else if (((FMurrayAttackCanChain(arg0) == 0) || (FMurrayTryGrabGuard(arg0) == 0)) && (M2C_FIELD(arg0, s32 *, 0x181C) != 0) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C) > 0.0f)) {
                            EndMurrayAttack(arg0);
                        }
                    }
                } else if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x80, 0x3E800000) != 0)) {
                    SetMurrayAttackState(arg0, M2C_FIELD(arg0, s32 *, 0x1810) == 0);
                } else if (((FMurrayAttackCanChain(arg0) == 0) || (FMurrayTryGrabGuard(arg0) == 0)) && (M2C_FIELD(arg0, s32 *, 0x181C) != 0) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C) > 0.0f)) {
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
