#include "m2c_macros.h"

M2C_UNK InitMissile();                              /* extern */

void InitRov__FP3ROV(void *arg0) {
    InitMissile();
    M2C_FIELD(arg0, f32 *, 0x270) = 2000.0f;
    M2C_FIELD(arg0, f32 *, 0x274) = 5000.0f;
    M2C_FIELD(arg0, s32 *, 0x264) = 0;
}
