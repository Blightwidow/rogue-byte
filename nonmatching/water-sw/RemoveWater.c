#include "m2c_macros.h"

M2C_UNK FreeSwXaList__FP2SWP2XA(M2C_UNK *, void *); /* extern */
M2C_UNK RemoveSoLoHierarchy();                      /* extern */
M2C_UNK RemoveSoXa__FP2SOP2XA(s32, void *);         /* extern */
extern M2C_UNK B_003DD490;

void RemoveWater(void *arg0) {
    void *var_s0;

    RemoveSoLoHierarchy();
    var_s0 = M2C_FIELD(arg0, void **, 0x150);
    if (var_s0 != NULL) {
        do {
            RemoveSoXa__FP2SOP2XA(M2C_FIELD(var_s0, s32 *, 4), var_s0);
            var_s0 = M2C_FIELD(var_s0, void **, 0xC);
        } while (var_s0 != NULL);
    }
    FreeSwXaList__FP2SWP2XA(&B_003DD490, M2C_FIELD(arg0, void **, 0x150));
    M2C_FIELD(arg0, void **, 0x150) = NULL;
}
