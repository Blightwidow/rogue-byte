#include "m2c_macros.h"

M2C_UNK AddBtnAseg(s32);                            /* extern */

void AddVolbtnAseg(s32 arg0) {
    AddBtnAseg(arg0 + 0x130);
}
