#include "m2c_macros.h"
extern "C" {

void Goal_Deactivate(void *);
void RemoveGuardSgs(s32, s32);
void SetZoneScriptState(void *, s32);

void ExitZoneScriptBeh(void *arg0) {
    SetZoneScriptState(arg0, -1);
    Goal_Deactivate(arg0);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x25);
}
}
