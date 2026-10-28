#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(s32, M2C_UNK, s32); /* extern */

void LoadAcrcFromBrx(s32 arg0, s32 arg1) {
    CBinaryInputStream_Read_thunk(arg1, 0xC, arg0 + 4);
}
