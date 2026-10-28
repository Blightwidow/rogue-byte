#include "m2c_macros.h"

void PrependMqList(s32 arg0, void *arg1, void **arg2) {
    void *var_v1;

    var_v1 = arg1;
    if (arg1 != NULL) {
        if (M2C_FIELD(arg1, s32 *, 0xAC) != 0) {
            do {
                var_v1 = M2C_FIELD(var_v1, void **, 0xAC);
            } while (M2C_FIELD(var_v1, s32 *, 0xAC) != 0);
        }
        M2C_FIELD(var_v1, void **, 0xAC) = (void *) *arg2;
        *arg2 = arg1;
    }
}
