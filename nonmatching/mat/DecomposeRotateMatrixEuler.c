#include "m2c_macros.h"

f32 GLimitAbs__Fff(f32, M2C_UNK);                   /* extern */
f32 asinf(f32);                                     /* extern */
f32 atan2f(f32, f32);                               /* extern */

s32 DecomposeRotateMatrixEuler(void *arg0) {
    f32 temp_f0;
    f32 temp_f20;

    temp_f0 = asinf(GLimitAbs__Fff(-M2C_FIELD(arg0, f32 *, 8), 0x3F800000));
    if (!(temp_f0 < 1.5706964f)) {
        atan2f(-M2C_FIELD(arg0, f32 *, 0x10), M2C_FIELD(arg0, f32 *, 0x20));
        M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
        M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
        M2C_ERROR(/* unknown instruction: por $v1, $zero, $v0 */);
    } else {
        if (!(temp_f0 > -1.5706964f)) {
            atan2f(-M2C_FIELD(arg0, f32 *, 0x10), -M2C_FIELD(arg0, f32 *, 0x20));
            M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
            M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
        } else {
            temp_f20 = atan2f(M2C_FIELD(arg0, f32 *, 0x18), M2C_FIELD(arg0, f32 *, 0x28));
            atan2f(M2C_FIELD(arg0, f32 *, 4), M2C_FIELD(arg0, f32 *, 0));
            M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
            M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
        }
        M2C_ERROR(/* unknown instruction: por $v1, $zero, $v0 */);
    }
    return M2C_ERROR(/* unknown instruction: por $v0, $zero, $v1 */);
}
