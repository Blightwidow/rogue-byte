#include "m2c_macros.h"

M2C_UNK func_001CB5D0();                            /* extern */

void func_001C7EA8(void *arg0) {
    void *temp_v0;

    func_001CB5D0();
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), -1);
}
