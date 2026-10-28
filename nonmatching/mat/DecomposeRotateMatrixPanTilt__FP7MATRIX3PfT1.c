#include "m2c_macros.h"

f32 atan2f();                               /* extern */

void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = atan2f(M2C_FIELD(arg0, f32 *, 4), M2C_FIELD(arg0, f32 *, 0));
    M2C_ERROR(/* unknown instruction: c1 0x10344 */);
    *arg2 = atan2f(M2C_FIELD(arg0, f32 *, 8));
}
