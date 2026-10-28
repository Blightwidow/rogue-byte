#include "m2c_macros.h"

M2C_UNK StopBinoc(s32);                             /* extern */

void ReleaseSeqnodeBinoc(void *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0xA0);
    if (temp_a0 != 0) {
        StopBinoc(temp_a0 + 0xF00);
        M2C_FIELD(arg0, s32 *, 0xA0) = 0;
    }
}
