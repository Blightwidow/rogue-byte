#include "m2c_macros.h"

M2C_UNK RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, M2C_UNK, void *); /* extern */
extern M2C_UNK B_002DDF40;

void StopSeqnodeCameraMove(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x90) = arg1;
    M2C_FIELD(arg0, s32 *, 0x9C) = 0;
    RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 2, 0xA, &B_002DDF40 + 0x500);
}
