#include "m2c_macros.h"

M2C_UNK CalculateSinCos__FfPfT1(void *, f32 *, f32); /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
f32 atan2f(f32, f32);                               /* extern */

void UpdateVjoyStick(f32 *arg1, f32 *arg2, f32 *arg3, f32 fparg0) {
    char sp[0x400];
    M2C_UNK sp0;
    f32 sp4;
    f32 *temp_s0;
    f32 *temp_s1;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;

    temp_s0 = M2C_ERROR(/* Read from unset register $t0 */);
    temp_s1 = M2C_ERROR(/* Read from unset register $t1 */);
    M2C_ERROR(/* unknown instruction: c1 0x10084 */);
    *temp_s0 = M2C_ERROR(/* Read from unset register $f2 */);
    temp_f0 = M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f3 */);
    *temp_s1 = temp_f0;
    temp_f1 = *temp_s0;
    if (!(temp_f1 < temp_f0)) {
        if (temp_f1 != 0.0f) {
            *arg3 = RadNormalize__Ff((atan2f(*arg2, *arg1) + fparg0) - 1.5707964f);
            *temp_s1 = *temp_s0;
            return;
        }
        goto block_4;
    }
block_4:
    CalculateSinCos__FfPfT1(sp, &sp4, (*arg3 - fparg0) + 1.5707964f);
    temp_f1_2 = *temp_s1;
    *temp_s0 = temp_f1_2;
    *arg1 = temp_f1_2 * sp4;
    *arg2 = *temp_s0 * sp0;
}
