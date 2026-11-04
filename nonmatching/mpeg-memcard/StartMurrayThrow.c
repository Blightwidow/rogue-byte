#include "m2c_macros.h"

s128 PosLoWorld();                      /* extern */
M2C_UNK SetMurrayState();                    /* extern */
M2C_UNK SetStepRadTargetDir();       /* extern */

void StartMurrayThrow(void *arg0, void *arg1) {
    s128 temp_v0;

    SetMurrayState(7);
    if (arg1 != NULL) {
        temp_v0 = PosLoWorld(arg1);
        M2C_FIELD(arg0, s128 *, 0x1420) = temp_v0;
        PosLoWorld(arg0, temp_v0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        SetStepRadTargetDir(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
    }
}
