#include "m2c_macros.h"

M2C_UNK InitXfm();                                  /* extern */

void InitCnvo__FP4CNVO(void *arg0) {
    InitXfm();
    M2C_FIELD(arg0, f32 *, 0xE8) = 100.0f;
}
