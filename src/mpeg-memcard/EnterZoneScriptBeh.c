#include "m2c_macros.h"

M2C_UNK SetZoneScriptState(s32, M2C_UNK);           /* extern */
M2C_UNK func_001EEF70();                            /* extern */

void EnterZoneScriptBeh(s32 arg0) {
    func_001EEF70();
    SetZoneScriptState(arg0, 0);
}
