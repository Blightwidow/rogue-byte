#include "m2c_macros.h"

M2C_UNK RemoveLoHierarchy();                        /* extern */
M2C_UNK RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, M2C_UNK, void *); /* extern */
extern M2C_UNK B_002DDF40;

void Camobj_RemoveLoHierarchy(void *arg0) {
    RemoveLoHierarchy();
    if (M2C_FIELD(arg0, s32 *, 0x124) != 0) {
        RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xF, 0xA, &B_002DDF40 + 0x4A8);
    }
}
