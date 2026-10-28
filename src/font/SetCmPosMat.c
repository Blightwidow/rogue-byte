#include "m2c_macros.h"

M2C_UNK UpdateCmMat4(void *);                       /* extern */

void SetCmPosMat(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(arg1, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x70) = (s128) M2C_FIELD(arg1, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x80) = (s128) M2C_FIELD(arg1, s128 *, 0x20);
    M2C_FIELD(arg0, s128 *, 0x90) = (s128) M2C_FIELD(arg1, s128 *, 0x30);
    UpdateCmMat4(arg0);
}
