#include "m2c_macros.h"

M2C_UNK SetVehicleState(void *, M2C_UNK);           /* extern */
M2C_UNK SnapSmaToGoal(void *, s32);                 /* extern */
M2C_UNK UpdateVehicleHpBlot();                      /* extern */

void func_001D14C0(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s32 *, 0x560) = (s32) M2C_FIELD(arg0, s32 *, 0x55C);
    UpdateVehicleHpBlot();
    temp_a0 = M2C_FIELD(arg0, void **, 0x570);
    if (temp_a0 != NULL) {
        SnapSmaToGoal(temp_a0, *M2C_FIELD(M2C_FIELD(temp_a0, void **, 0x24), s32 **, 0x54));
    }
    SetVehicleState(arg0, 0);
}
