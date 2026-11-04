#include "m2c_macros.h"

M2C_UNK PosLoWorld(s128);                           /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */

void AttachCyl_GetParam(void *arg0, void *arg1, f32 *arg2) {
    PosLoWorld(*M2C_FIELD(arg1, s128 **, 0x218));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    *arg2 = atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */)) * M2C_FIELD(arg0, f32 *, 0x10C);
}
