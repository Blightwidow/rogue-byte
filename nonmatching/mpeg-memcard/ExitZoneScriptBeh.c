#include "m2c_macros.h"

M2C_UNK Goal_Deactivate(void *);                    /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */
M2C_UNK SetZoneScriptState(M2C_UNK);                /* extern */

void ExitZoneScriptBeh(void *arg0) {
    SetZoneScriptState(-1);
    Goal_Deactivate(arg0);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x25);
}
