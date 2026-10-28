#include "m2c_macros.h"

M2C_UNK PostSoLoad();                               /* extern */
M2C_UNK func_00226370(void *, M2C_UNK);             /* extern */

void PostTankLoad(void *arg0) {
    PostSoLoad();
    if (M2C_FIELD(arg0, s32 *, 0x1CC) != 0) {
        M2C_FIELD(arg0, s32 *, 0x1CC) = 0;
        func_00226370(arg0, 1);
    }
}
