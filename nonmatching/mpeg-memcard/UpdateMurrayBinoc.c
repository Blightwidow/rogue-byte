#include "m2c_macros.h"

s32 FButtonPressedWithin(s32, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK StopBinoc(void *);                          /* extern */
M2C_UNK UpdateBinoc(void *);                        /* extern */
s32 bevy_player_p15_binoc_active();                 /* extern */

void UpdateMurrayBinoc(void *arg0) {
    void *temp_s1;

    if (bevy_player_p15_binoc_active() != 0) {
        temp_s1 = arg0 + 0xF00;
        if ((M2C_FIELD(arg0, s32 *, 0xF04) == 1) && (M2C_FIELD(arg0, s32 *, 0xF20) == 0) && (FButtonPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 0x4F0, 0x3E800000) != 0)) {
            StopBinoc(temp_s1);
        }
        UpdateBinoc(temp_s1);
    }
}
