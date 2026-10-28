#include "m2c_macros.h"

M2C_UNK DecomposeRotateMatrixEuler(s32);            /* extern */
s32 PmatLoWorld();                                  /* extern */

s32 GetLoEulerDegrees(void) {
    DecomposeRotateMatrixEuler(PmatLoWorld());
    M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */);
    M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */);
    M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
    M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */);
    return M2C_ERROR(/* unknown instruction: por $v0, $zero, $v1 */);
}
