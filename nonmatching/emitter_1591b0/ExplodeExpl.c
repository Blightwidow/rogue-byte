#include "m2c_macros.h"

M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void ExplodeExpl(void *arg0) {
    char sp[0x400];
    void *temp_v1;

    memset(sp, 0, 0x40);
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, void *), 0x19C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x198), sp);
}
