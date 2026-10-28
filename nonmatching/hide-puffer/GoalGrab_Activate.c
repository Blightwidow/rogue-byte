#include "m2c_macros.h"

M2C_UNK ClearGuardPathMode(void *);                 /* extern */
M2C_UNK GoalAnimLeap_SetState(void *, M2C_UNK);     /* extern */
M2C_UNK func_00154038(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_00174950();                            /* extern */
M2C_UNK func_001EEFC0(void *);                      /* extern */
M2C_UNK func_0020AB68(void *, M2C_UNK, M2C_UNK, s128); /* extern */
extern s128 g_2a2dd0;

void GoalGrab_Activate(void *arg0) {
    func_00174950();
    func_0020AB68(M2C_FIELD(arg0, void **, 0x10), 0, 0, g_2a2dd0);
    ClearGuardPathMode(M2C_FIELD(arg0, void **, 0x10));
    GoalAnimLeap_SetState(arg0, 0);
    func_001EEFC0(arg0);
    func_00154038(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF64), M2C_FIELD(arg0, s32 *, 0x5C), 2);
}
