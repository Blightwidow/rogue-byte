#include "m2c_macros.h"

M2C_UNK ExplodeGadgetBurst(void *, s32, s32, M2C_UNK, f32); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK func_001A58D0(M2C_UNK, M2C_UNK);            /* extern */

void DetonateGadgetObj(void *arg0, f32 fparg0) {
    func_001A58D0(0, 1);
    PosLoWorld(arg0);
    ExplodeGadgetBurst(arg0, M2C_FIELD(arg0, s32 *, 0x174), M2C_FIELD(arg0, s32 *, 0x178), M2C_ERROR(/* unknown instruction: por $a3, $zero, $v0 */), fparg0);
}
