#include "m2c_macros.h"

s32 PchzStringFromId(M2C_UNK *, s32);               /* extern */
M2C_UNK strcpy(s8 *, s32);                          /* extern */
extern M2C_UNK B_003DD490;

void func_002277D0(s32 *arg0, s8 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 == -1) {
        *arg1 = 0;
        return;
    }
    strcpy(arg1, PchzStringFromId(&B_003DD490, temp_v1));
}
