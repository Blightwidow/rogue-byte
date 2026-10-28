#include "m2c_macros.h"

void CTextBox_SetHorizontalJust(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
}
