#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */

s32 func_001C41B8(void *arg0) {
    char sp[0x400];
    s32 sp0;
    s32 sp4;
    void *temp_t2;

    sp4 = 1;
    sp0 = 0x17;
    temp_t2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_t2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_t2, s16 *, 0x18), 0xD, 0, 0);
    CRef_Destruct(sp);
    return ((0x17 ^ 0x17) == 0) ? sp4 : 1;
}
