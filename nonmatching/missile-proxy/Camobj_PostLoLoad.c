#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, void *, M2C_UNK); /* extern */
extern M2C_UNK B_002DDF40;

void Camobj_PostLoLoad(void *arg0) {
    PostLoLoad();
    M2C_FIELD(arg0, s32 *, 0x124) = 1;
    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xA, &B_002DDF40 + 0x4A8, 0);
    }
}
