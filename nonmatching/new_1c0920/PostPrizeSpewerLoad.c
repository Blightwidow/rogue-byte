#include "m2c_macros.h"

M2C_UNK PostSoLoad();                               /* extern */
M2C_UNK SetSoProperties(void *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_001F1448(s32, void *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_002C0CB0;

void PostPrizeSpewerLoad(void *arg0) {
    PostSoLoad();
    SetSoProperties(arg0, 4, &D_002C0CB0);
    func_001F1448(M2C_FIELD(arg0, s32 *, 0x168), arg0, -1, 0);
}
