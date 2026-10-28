#include "m2c_macros.h"

M2C_UNK Mount_SetState(s32, M2C_UNK);               /* extern */

void func_00181728(void *arg0) {
    void *temp_v1;

    Mount_SetState(M2C_FIELD(arg0, s32 *, 0x1C8), 1);
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, s32 *, 0x1C8) = 0;
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 6, 0, 0);
}
