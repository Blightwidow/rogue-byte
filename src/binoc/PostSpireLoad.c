#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK SetTnTns__FP2TN3TNS(s32, M2C_UNK);          /* extern */

void PostSpireLoad(void *arg0) {
    s32 temp_a0;

    PostLoLoad();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x110);
    if (temp_a0 != 0) {
        SetTnTns__FP2TN3TNS(temp_a0, 0);
    }
}
