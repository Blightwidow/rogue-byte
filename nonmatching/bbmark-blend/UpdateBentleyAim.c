#include "m2c_macros.h"

s32 FButtonPressedWithin(s32, M2C_UNK, M2C_UNK);    /* extern */
s32 IsmsFindSmOptional__FP2SM3OID(s32, M2C_UNK);    /* extern */
M2C_UNK SeekSma(s32, M2C_UNK);                      /* extern */
M2C_UNK SetBentleyAimState(void *, M2C_UNK);        /* extern */
M2C_UNK ThrowBentleyBomb(void *, M2C_UNK);          /* extern */
M2C_UNK UpdateLookRig(void *, M2C_UNK);             /* extern */
s32 bevy_player_p15_binoc_active(void *);           /* extern */
extern f32 D_FLT_002BC994;
extern f32 g_2dded0;

void UpdateBentleyAim(void *arg0) {
    s32 temp_s1;
    u32 temp_v1;

    do {
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x16BC);
        if (temp_s1 != -1) {
            if ((temp_s1 >= -1) && (temp_s1 < 2)) {
                if (bevy_player_p15_binoc_active(arg0) != 0) {
                    if (M2C_FIELD(arg0, s32 *, 0x16BC) != 1) {
                        if (FButtonPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 8, 0x3E800000) != 0) {
                            ThrowBentleyBomb(arg0, 0x80000);
                        }
                    } else if (D_FLT_002BC994 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x1700))) {
                        SetBentleyAimState(arg0, 0);
                    }
                } else {
                    SetBentleyAimState(arg0, -1);
                }
            }
        } else {
            if ((bevy_player_p15_binoc_active(arg0) != 0) && (M2C_FIELD(arg0, s32 *, 0xF20) != 2)) {
                if (D_FLT_002BC994 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x1700))) {
                    SetBentleyAimState(arg0, 0);
                } else {
                    SetBentleyAimState(arg0, 1);
                }
            }
            temp_v1 = M2C_FIELD(arg0, u32 *, 0x13D0);
            switch (temp_v1) {
            case 0:
                UpdateLookRig(arg0 + 0x1710, 0);
                if ((M2C_FIELD(arg0, s32 *, 0x181C) != 0) && (M2C_FIELD(arg0, s32 *, 0x1714) != -1) && (M2C_FIELD(arg0, s32 *, 0x1034) != 0) && (IsmsFindSmOptional__FP2SM3OID(M2C_FIELD(arg0, s32 *, 0x1028), 0x17B) >= 0)) {
                    SeekSma(M2C_FIELD(arg0, s32 *, 0x1034), 0x17B);
                }
                break;
            case 1:
            case 2:
            case 3:
            case 7:
                UpdateLookRig(arg0 + 0x1710, 1);
                break;
            case 5:
                UpdateLookRig(arg0 + 0x1710, 2);
                break;
            default:
                UpdateLookRig(arg0 + 0x1710, -1);
                break;
            }
        }
    } while (temp_s1 != M2C_FIELD(arg0, s32 *, 0x16BC));
}
