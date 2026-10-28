#include "m2c_macros.h"

M2C_UNK StaticInitSensor(M2C_UNK, M2C_UNK);         /* extern */

void GlobalCtorSensor(void) {
    StaticInitSensor(1, 0xFFFF);
}
