#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK HandleLoMessage();                          /* extern */
void *PpoSwFocusBase(M2C_UNK *);                    /* extern */
M2C_UNK bevy_ui_binoc_recon_202030(s32);            /* extern */
M2C_UNK bevy_ui_binoc_recon_2021f8(s32);            /* extern */
extern M2C_UNK B_003DD490;

void func_00203670(s32 arg0, s32 arg1) {
    s32 temp_a0;
    void *temp_v0;

    HandleLoMessage();
    if (arg1 == 0x11) {
        temp_v0 = PpoSwFocusBase(&B_003DD490);
        if ((temp_v0 != NULL) && (FIsBasicDerivedFrom(temp_v0, 0x34) != 0)) {
            temp_a0 = M2C_FIELD(temp_v0, s32 *, 0xF38);
            if (temp_a0 != 0) {
                bevy_ui_binoc_recon_202030(temp_a0);
                bevy_ui_binoc_recon_2021f8(M2C_FIELD(temp_v0, s32 *, 0xF38));
            }
        }
    }
}
