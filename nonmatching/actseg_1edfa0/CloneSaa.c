#include "m2c_macros.h"

M2C_UNK InitSaa();                                  /* extern */

void CloneActseg__FP6ACTSEGT0(void *arg0, void *arg1) {
    InitSaa();
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) M2C_FIELD(arg1, f32 *, 0x10);
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(arg1, f32 *, 0xC);
}
