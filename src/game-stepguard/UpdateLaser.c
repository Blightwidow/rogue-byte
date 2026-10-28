#include "m2c_macros.h"

M2C_UNK AdvanceLaserBeams(s32);                     /* extern */
M2C_UNK UpdateSo();                                 /* extern */

void UpdateLaser(s32 arg0) {
    UpdateSo();
    AdvanceLaserBeams(arg0);
}
