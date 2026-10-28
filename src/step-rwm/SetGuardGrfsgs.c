#include "m2c_macros.h"

M2C_UNK func_001F1900();                            /* extern */

void SetGuardGrfsgs(void *arg0, s64 arg1) {
    M2C_FIELD(arg0, s64 *, 0x2C0) = arg1;
    func_001F1900();
}
