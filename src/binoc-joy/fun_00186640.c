#include "m2c_macros.h"

M2C_UNK ActivateAct();                              /* extern */

void func_00186640(void *arg0) {
    ActivateAct();
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0xA8) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
}
