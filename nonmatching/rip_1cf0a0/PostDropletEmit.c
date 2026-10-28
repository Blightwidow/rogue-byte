#include "m2c_macros.h"

M2C_UNK func_001CE9B8();                            /* extern */

void PostDropletEmit(void *arg0, void *arg1) {
    func_001CE9B8();
    M2C_FIELD(arg0, s32 *, 0xF4) = (s32) M2C_FIELD(M2C_FIELD(arg1, void **, 8), s32 *, 0xC);
}
