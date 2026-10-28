#include "m2c_macros.h"

M2C_UNK GoalFlinch_SetState(void *, M2C_UNK);       /* extern */
M2C_UNK ReplaceSwHitFx(M2C_UNK *, M2C_UNK, s128, M2C_UNK); /* extern */
M2C_UNK func_00174B28();                            /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;

void func_0017A558(void *arg0) {
    func_00174B28();
    GoalFlinch_SetState(arg0, -1);
    ReplaceSwHitFx(&B_003DD490, -1, g_2a2dd0, 0);
}
