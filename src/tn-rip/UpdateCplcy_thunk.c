#include "m2c_macros.h"

M2C_UNK UpdateCplcy();                              /* extern */

void UpdateCplcy_thunk(void) {
    UpdateCplcy();
}
