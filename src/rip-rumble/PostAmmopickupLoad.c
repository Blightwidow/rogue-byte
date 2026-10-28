#include "m2c_macros.h"

M2C_UNK PostSoLoad();                               /* extern */
M2C_UNK SetAmmopickupState(void *, M2C_UNK);        /* extern */
M2C_UNK func_001F1448(s32, void *, M2C_UNK, M2C_UNK, void *); /* extern */

void PostAmmopickupLoad(void *arg0) {
    PostSoLoad();
    func_001F1448(M2C_FIELD(arg0, s32 *, 0x160), arg0, -1, 0, (char *)arg0 + 0x164);
    SetAmmopickupState(arg0, 0);
}
