#include "m2c_macros.h"

M2C_UNK func_00205D10();                            /* extern */

void func_001F1F38(void *arg0, s32 arg1) {
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;

    func_00205D10();
    temp_a2 = M2C_FIELD(arg0, void **, 0x494);
    if (arg1 != 0) {
        if (temp_a2 != NULL) {
            temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0xAC)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0xA8), 0, temp_a2);
        }
    } else if (temp_a2 != NULL) {
        temp_v0_2 = M2C_FIELD(temp_a2, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *), 0xAC)(temp_a2 + M2C_FIELD(temp_v0_2, s16 *, 0xA8), 1, temp_a2);
    }
}
