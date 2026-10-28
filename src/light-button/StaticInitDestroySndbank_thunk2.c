#include "m2c_macros.h"

M2C_UNK StaticInitDestroySndbank(M2C_UNK, M2C_UNK); /* extern */

void StaticInitDestroySndbank_thunk2(void) {
    StaticInitDestroySndbank(0, 0xFFFF);
}
