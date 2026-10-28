#include "m2c_macros.h"

M2C_UNK InitMissile();                              /* extern */

void InitTarmiss(void *arg0) {
    InitMissile();
    M2C_FIELD(arg0, f32 *, 0x274) = 1500.0f;
}
