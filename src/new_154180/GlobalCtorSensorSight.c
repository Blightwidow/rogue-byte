#include "m2c_macros.h"

M2C_UNK StaticInitSensorSight(M2C_UNK, M2C_UNK);    /* extern */

void GlobalCtorSensorSight(void) {
    StaticInitSensorSight(1, 0xFFFF);
}
