#include "m2c_macros.h"

M2C_UNK RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, void *, s32); /* extern */
extern M2C_UNK B_002DDF40;
extern s32 g_2f7900;

void func_001CBF90(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x1010) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x1010) = arg1;
        if (arg1 != 0) {
            SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 6, &B_002DDF40 + 0x600, g_2f7900);
        } else {
            RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 1, 6, 0);
        }
    }
}
