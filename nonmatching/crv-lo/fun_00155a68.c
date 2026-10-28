#include "m2c_macros.h"

M2C_UNK PosLoWorld(s32);                            /* extern */
s32 func_00227C90(s32, M2C_UNK);                    /* extern */

s32 func_00155A68(void *arg0) {
    void *temp_s0;
    void *temp_s0_2;

    temp_s0 = M2C_FIELD(arg0, void **, 0x38);
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0x4C));
    if ((func_00227C90(M2C_FIELD(temp_s0, s32 *, 0xC), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */)) != 0) || (temp_s0_2 = M2C_FIELD(arg0, void **, 0x38), PosLoWorld(M2C_FIELD(arg0, s32 *, 0x4C)), (func_00227C90(M2C_FIELD(temp_s0_2, s32 *, 0x1C), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */)) == 0))) {
        return M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s32 *, 4);
    }
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s32 *, 0x14);
}
