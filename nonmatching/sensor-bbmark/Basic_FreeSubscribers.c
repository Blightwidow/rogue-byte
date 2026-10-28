#include "m2c_macros.h"

M2C_UNK FreeSlotheapPv(M2C_UNK *, void *);          /* extern */
extern M2C_UNK B_003E1144;

void Basic_FreeSubscribers(void *arg0) {
    void *var_a1;
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 8);
    if (var_s0 != NULL) {
        var_a1 = var_s0;
        do {
            var_a1 = var_s0;
            var_s0 = M2C_FIELD(var_s0, void **, 8);
            FreeSlotheapPv(&B_003E1144, var_a1);
        } while (var_s0 != NULL);
    }
    M2C_FIELD(arg0, void **, 8) = NULL;
}
