#include "m2c_macros.h"

M2C_UNK StaticInitDestroySndbank(M2C_UNK, M2C_UNK); /* extern */

void StaticInitDestroySndbank_thunk(void) {
    StaticInitDestroySndbank(1, 0xFFFF);
}
