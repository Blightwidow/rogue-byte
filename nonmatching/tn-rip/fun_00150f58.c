#include "m2c_macros.h"

s32 FFloatsNear__Ffff(s128, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK bevy_classes_k30_cam_150780();              /* extern */

s32 func_00150F58(void *arg0) {
    s128 temp_s1;
    s32 var_v0;

    temp_s1 = M2C_FIELD(arg0, s128 *, 0x20);
    bevy_classes_k30_cam_150780();
    var_v0 = 0;
    if (FFloatsNear__Ffff(temp_s1, M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */), 0x38D1B717) != 0) {
        var_v0 = 0;
        if (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), 0x38D1B717) != 0) {
            var_v0 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), 0x38D1B717) != 0;
        }
    }
    return var_v0;
}
