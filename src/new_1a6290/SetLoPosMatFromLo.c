#include "m2c_macros.h"

M2C_UNK SetLoPosMat(s32, s32);                      /* extern */

void SetLoPosMatFromLo(s32 arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg1, void **, 0xC);
    SetLoPosMat(arg0, M2C_FIELD(temp_v1, s32 (**)(void *), 0xFC)(arg1 + M2C_FIELD(temp_v1, s16 *, 0xF8)));
}
