#include "m2c_macros.h"

M2C_UNK CPLCY_Destruct();                           /* extern */

void CPLCY_Destruct_thunk(void) {
    CPLCY_Destruct();
}
