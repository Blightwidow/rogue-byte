#include "m2c_macros.h"

M2C_UNK InitSo();                                   /* extern */
M2C_UNK SetAloInteract(s32, M2C_UNK, M2C_UNK);      /* extern */

void InitStgSwitch(s32 arg0) {
    InitSo();
    SetAloInteract(arg0, 0x03FFFFFF, 8);
    SetAloInteract(arg0, 0x80001, 0);
}
