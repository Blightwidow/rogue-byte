#include "m2c_macros.h"

M2C_UNK UpdateSo();                                 /* extern */
M2C_UNK UpdateTankAim(s32);                         /* extern */
M2C_UNK UpdateTankFire(s32);                        /* extern */
M2C_UNK UpdateTankFov(s32);                         /* extern */

void UpdateTank(s32 arg0) {
    UpdateSo();
    UpdateTankAim(arg0);
    UpdateTankFov(arg0);
    UpdateTankFire(arg0);
}
