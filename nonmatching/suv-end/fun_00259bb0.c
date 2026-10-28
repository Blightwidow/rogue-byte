#include "m2c_macros.h"

void func_00259BB0(void **arg0, void *arg1) {
    void *temp_v0;

    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0xC)(arg1 + M2C_FIELD(temp_v0, s16 *, 8));
    }
    *arg0 = arg1;
}
