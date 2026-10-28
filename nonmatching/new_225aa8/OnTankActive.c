#include "m2c_macros.h"

M2C_UNK OnPoActive();                               /* extern */
M2C_UNK RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, M2C_UNK, void *); /* extern */
M2C_UNK SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, void *, s32); /* extern */
extern M2C_UNK B_002DDF40;

void OnTankActive(s32 arg0, s32 arg1) {
    OnPoActive();
    if (arg1 != 0) {
        SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 9, &B_002DDF40 + 0x5F0, arg0);
        return;
    }
    RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xF, 9, &B_002DDF40 + 0x5F0);
}
