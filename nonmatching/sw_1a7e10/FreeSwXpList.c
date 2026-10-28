#include "m2c_macros.h"

M2C_UNK FreeSlotheapPv(s32, void *);                /* extern */

void FreeSwMqList__FP2SWP2MQ(s32 arg0, void *arg1) {
    void *var_a1;
    void *var_s0;

    var_s0 = arg1;
    if (var_s0 != NULL) {
        var_a1 = var_s0;
        do {
            var_a1 = var_s0;
            FreeSlotheapPv(arg0 + 0x3D40, var_a1);
            var_s0 = M2C_FIELD(var_s0, void **, 0xAC);
        } while (var_s0 != NULL);
    }
}
