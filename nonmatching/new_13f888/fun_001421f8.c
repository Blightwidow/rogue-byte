#include "m2c_macros.h"

M2C_UNK StartAttach(s32, M2C_UNK, s32, M2C_UNK);    /* extern */
M2C_UNK func_001CD308(s32, s32);                    /* extern */

void func_001421F8(void *arg0, s32 arg1) {
    void *temp_v0;

    if (arg1 != 0) {
        StartAttach(arg0 + 0x4C0, 5, arg1, 0);
        func_001CD308(arg0 + 0x900, arg1);
    } else if (M2C_FIELD(arg0, s32 *, 0x4C8) == 5) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x2C4)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x2C0), 0);
    }
}
