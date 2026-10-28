#include "m2c_macros.h"

M2C_UNK InitSo();                                   /* extern */

void func_001B4438(void *arg0) {
    InitSo();
    M2C_FIELD(arg0, s64 *, 0x148) = (s64) (M2C_FIELD(arg0, s64 *, 0x148) & ((0xBFFFFFFF << 5) | 0x1F));
}
