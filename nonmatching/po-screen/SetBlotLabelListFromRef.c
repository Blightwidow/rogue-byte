#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK func_002013D8(void *, M2C_UNK, M2C_UNK);    /* extern */

void SetBlotLabelListFromRef(void *arg0) {
    char sp[0x400];
    M2C_UNK sp10;
    void *temp_v0;

    func_002013D8(sp, 0x10, 0xA);
    CRef_Destruct(sp);
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x18C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x188), -1);
}
