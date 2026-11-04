#include "m2c_macros.h"

M2C_UNK SetStepRadTarget(s32, f32);                 /* extern */
f32 atan2f(M2C_UNK, s32);                           /* extern */

void SetStepRadTargetDir(s32 arg0, s32 arg1) {
    SetStepRadTarget(arg0, atan2f(M2C_ERROR(/* unknown instruction: prot3w $v0, $a1 */), arg1));
}
