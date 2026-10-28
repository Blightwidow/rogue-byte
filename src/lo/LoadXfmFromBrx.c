#include "m2c_macros.h"

M2C_UNK LoadOptionsFromBrx__FPvP18CBinaryInputStream(s32, s32); /* extern */
M2C_UNK LoadXfmBaseFromBrx();                       /* extern */

void LoadXfmFromBrx(s32 arg0, s32 arg1) {
    LoadXfmBaseFromBrx();
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(arg0, arg1);
}
