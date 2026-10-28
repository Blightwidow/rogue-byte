#include "m2c_macros.h"

M2C_UNK OnPoActive();                               /* extern */
M2C_UNK SetVehicleState(void *, M2C_UNK);           /* extern */

void OnVehicleActive(void *arg0, s32 arg1) {
    OnPoActive();
    if (arg1 != 0) {
        SetVehicleState(arg0, 2);
    } else if (M2C_FIELD(arg0, s32 *, 0x180) == 2) {
        SetVehicleState(arg0, 0);
    }
}
