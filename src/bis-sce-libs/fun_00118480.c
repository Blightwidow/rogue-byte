#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Constructor();           /* extern */
extern M2C_UNK D_002CA5A0;

void *func_00118480(void *arg0) {
    CBinaryInputStream_Constructor();
    M2C_FIELD(arg0, M2C_UNK **, 0x30) = &D_002CA5A0;
    return arg0;
}
