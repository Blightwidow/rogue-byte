#include "m2c_macros.h"

M2C_UNK SetSoCnstrForce(void *, M2C_UNK);           /* extern */
M2C_UNK SetSoCnstrTorque(void *, M2C_UNK);          /* extern */
M2C_UNK StepStgSwitch(void *, M2C_UNK);             /* extern */
M2C_UNK func_001CB518();                            /* extern */

void func_001BBEA8(void *arg0) {
    func_001CB518();
    StepStgSwitch(arg0, 0x609);
    if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
        SetSoCnstrForce(arg0, 1);
        SetSoCnstrTorque(arg0, 1);
    }
}
