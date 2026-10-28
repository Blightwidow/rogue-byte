#include "m2c_macros.h"

M2C_UNK AddSoLoHierarchy();                         /* extern */
M2C_UNK func_001F1448(s32, void *, M2C_UNK, M2C_UNK); /* extern */

void AddGadgetObjLoHierarchy(void *arg0) {
    s32 temp_a0;

    AddSoLoHierarchy();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x164);
    if (temp_a0 != 0) {
        func_001F1448(temp_a0, arg0, -1, 0);
    }
}
