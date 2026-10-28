#include "m2c_macros.h"

M2C_UNK RemoveSoLoHierarchy();                      /* extern */
M2C_UNK RetractSmaRef(void *);                      /* extern */

void RemoveGadgetObjLoHierarchy(void *arg0) {
    void *temp_v0;

    RemoveSoLoHierarchy();
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), -1);
    RetractSmaRef(arg0 + 0x168);
}
