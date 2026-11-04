#include "m2c_macros.h"

s128 PosLoWorld();                         /* extern */
M2C_UNK SetStepRadTargetDir();          /* extern */

void func_002046F0(s32 arg0, s32 arg1) {
    PosLoWorld(arg0, PosLoWorld(arg1));
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    SetStepRadTargetDir(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
}
