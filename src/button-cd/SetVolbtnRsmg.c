#include "m2c_macros.h"

M2C_UNK SetAlarmRsmg__FP5ALARMi3OIDN22(s32);        /* extern */

void SetVolbtnRsmg(s32 arg0) {
    SetAlarmRsmg__FP5ALARMi3OIDN22(arg0 + 0x130);
}
