#include "m2c_macros.h"

M2C_UNK GoalFlinch_SetState(void *, M2C_UNK);       /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK ReplaceSwHitFx(M2C_UNK *, M2C_UNK, M2C_UNK, void *); /* extern */
M2C_UNK ResetSensorStates(s32);                     /* extern */
M2C_UNK func_00174950();                            /* extern */
extern M2C_UNK B_003DD490;

void func_0017A4E8(void *arg0) {
    func_00174950();
    GoalFlinch_SetState(arg0, 0);
    ResetSensorStates(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF64));
    PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
    ReplaceSwHitFx(&B_003DD490, 1, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), M2C_FIELD(arg0, void **, 0x10));
}
