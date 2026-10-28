#include "m2c_macros.h"

s32 FAsegaGone(s32);                                /* extern */
s32 FVjoyButtonHeld(s32, s32);                      /* extern */
s32 GrfbtnJtGadget(void *, s32);                    /* extern */
M2C_UNK ReleaseBentleyGadget(void *);               /* extern */
M2C_UNK SetBentleyGadgetAnim(void *, M2C_UNK);      /* extern */
M2C_UNK SetJmpState(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK StickGadgetObj(void *, s32);                /* extern */
extern f32 g_2dded0;

void UpdateBentleyGadget(void *arg0) {
    s32 temp_v0;
    void *temp_s1;
    void *temp_v0_2;

loop_1:
    if (M2C_FIELD(arg0, s32 *, 0x16B0) == 0) {
        if (FAsegaGone(M2C_FIELD(arg0, s32 *, 0x1030)) != 0) {
            SetBentleyGadgetAnim(arg0, 1);
        }
    } else if ((M2C_FIELD(arg0, s32 *, 0x16B0) >= 0) && (M2C_FIELD(arg0, s32 *, 0x16B0) < 3)) {
        temp_s1 = M2C_FIELD(arg0, void **, 0x186C);
        temp_v0 = M2C_FIELD(temp_s1, s32 *, 0x158);
        if (temp_v0 == 2) {
            StickGadgetObj(temp_s1, M2C_FIELD(temp_s1, s32 *, 0x1A0));
            goto block_11;
        }
        if ((temp_v0 == 4) || (FVjoyButtonHeld(M2C_FIELD(arg0, s32 *, 0x150), GrfbtnJtGadget(arg0, *M2C_FIELD(arg0, s32 **, 0x16B4)) | 0x10) == 0)) {
            temp_v0_2 = M2C_FIELD(temp_s1, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK), 0x264)(temp_s1 + M2C_FIELD(temp_v0_2, s16 *, 0x260), 1);
block_11:
            ReleaseBentleyGadget(arg0);
            SetJmpState(arg0 + 0x2C0, 0xB, 0, 0);
        } else if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x20C)) > 0.1f) {
            SetBentleyGadgetAnim(arg0, 2);
        } else {
            SetBentleyGadgetAnim(arg0, 1);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x16B0) != M2C_FIELD(arg0, s32 *, 0x16B0)) {
        if (M2C_FIELD(arg0, s32 *, 0x13D0) == 6) {
            goto loop_1;
        }
    }
}
