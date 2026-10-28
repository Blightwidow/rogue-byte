#include "m2c_macros.h"

M2C_UNK SetBinocState(M2C_UNK);                     /* extern */

s32 StopBinoc(void *arg0) {
    s32 *temp_v0;
    s32 temp_v1;

    temp_v0 = M2C_FIELD(arg0, s32 **, 0x38);
    if ((temp_v0 == NULL) || ((temp_v1 = *temp_v0, (temp_v1 != 0)) && ((temp_v1 < 0) || (temp_v1 >= 0xB) || (temp_v1 < 8)))) {
        SetBinocState(2);
    }
}
