#include "m2c_macros.h"

M2C_UNK AddLoHierarchy();                           /* extern */
M2C_UNK SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, void *, M2C_UNK); /* extern */
extern M2C_UNK B_002DDF40;

void Camobj_AddLoHierarchy(void *arg0) {
    AddLoHierarchy();
    if (M2C_FIELD(arg0, s32 *, 0x124) != 0) {
        SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xA, &B_002DDF40 + 0x4A8, 0);
    }
}
