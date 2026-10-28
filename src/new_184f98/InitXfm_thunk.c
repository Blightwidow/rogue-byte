#include "m2c_macros.h"

M2C_UNK InitXfm();                                  /* extern */

void InitXfm_thunk(void) {
    InitXfm();
}
