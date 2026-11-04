#include "m2c_macros.h"

M2C_UNK func_0022D148(s128 *, s32, M2C_UNK);        /* extern */
extern s128 g_2a2dd0;

s128 GetXfmAngularVelocity(void *arg0) {
    M2C_UNK sp50;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s32 temp_a1;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_a1 != 0) {
        func_0022D148(&sp40, temp_a1, 0);
        sp10 = sp50;
        sp20 = sp60;
        M2C_ERROR(/* unknown instruction: pextlw $v1, $a0, $v1 */);
        sp30 = sp70;
        sp40 = M2C_ERROR(/* unknown instruction: pcpyld $v1, $a0, $v1 */);
        return M2C_ERROR(/* unknown instruction: por $v0, $zero, $v1 */);
    }
    return g_2a2dd0;
}
