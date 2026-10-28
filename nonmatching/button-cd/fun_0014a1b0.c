#include "m2c_macros.h"

M2C_UNK AddGuardSgs(s32, M2C_UNK);                  /* extern */
M2C_UNK func_001EEF68();                            /* extern */
M2C_UNK func_001FEE90(M2C_UNK *);                   /* extern */
extern M2C_UNK B_003DD040;

void func_0014A1B0(void *arg0) {
    func_001EEF68();
    func_001FEE90(&B_003DD040);
    AddGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x24);
    M2C_FIELD(arg0, s32 *, 0x3C) = -1;
    M2C_FIELD(arg0, s32 *, 0x30) = -1;
    M2C_FIELD(arg0, s32 *, 0x40) = -1;
}
