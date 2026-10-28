#include "m2c_macros.h"

M2C_UNK ClonePo();                                  /* extern */
M2C_UNK func_001EEC68(s32, s32);                    /* extern */

void CloneStep(s32 arg0) {
    ClonePo();
    func_001EEC68(arg0 + 0x26C, arg0);
}
