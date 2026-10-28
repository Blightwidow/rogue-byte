#include "m2c_macros.h"

s128 ConvertXfPos(M2C_UNK, s32, M2C_UNK);           /* extern */

void SetJumperTarget(void *arg0, s128 arg1) {
    s32 temp_v0;
    void *temp_s0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x10);
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, s128 *, 0x40) = arg1;
    } else if (temp_v0 >= 0) {
        if ((temp_v0 < 3) && (M2C_FIELD(arg0, s32 *, 0x60) != 0)) {
            temp_s0 = M2C_FIELD(arg0, void **, 0x68);
            M2C_FIELD(temp_s0, s128 *, 0x20) = ConvertXfPos(0, M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x58), s32 *, 0xA0), M2C_ERROR(/* unknown instruction: por $a2, $zero, $a1 */));
        }
    }
}
