#include "m2c_macros.h"

M2C_UNK FreeSlotheapPv(s32, void *);                /* extern */

void FreeSwXaList__FP2SWP2XA(s32 arg0, void *arg1) {
    void *var_a1;
    void *var_s0;

    var_s0 = arg1;
    if (var_s0 != NULL) {
        var_a1 = var_s0;
        do {
            var_s0 = M2C_FIELD(var_s0, void **, 0xC);
            FreeSlotheapPv(arg0 + 0x40E8, var_a1);
            var_a1 = var_s0;
        } while (var_s0 != NULL);
    }
}
