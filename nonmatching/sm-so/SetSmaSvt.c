#include "m2c_macros.h"

s32 FSmaRetracted();                                /* extern */
M2C_UNK SetAsegaSpeed(s32, f32);                    /* extern */

void SetSmaSvt(void *arg0, f32 fparg0) {
    void *sp0;
    s32 temp_a0;
    void *temp_v0;
    void *temp_v0_2;

    if (FSmaRetracted() == 0) {
        sp0 = arg0;
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x30);
        M2C_FIELD(arg0, f32 *, 0x44) = fparg0;
        if (temp_a0 != 0) {
            SetAsegaSpeed(temp_a0, fparg0);
        }
        temp_v0_2 = M2C_FIELD(sp0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x14)(sp0 + M2C_FIELD(temp_v0_2, s16 *, 0x10), sp0);
    }
}
