#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read();                  /* extern */

void CBinaryInputStream_Read_thunk(void) {
    CBinaryInputStream_Read();
}
