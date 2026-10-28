#include "m2c_macros.h"

M2C_UNK SetJmpState(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetJtZapState(M2C_UNK);                     /* extern */
M2C_UNK WarpZapToSafePoint();                       /* extern */

void func_001A2080(void *arg0) {
    void *temp_v0;

    if (*M2C_FIELD(arg0, s32 **, 0x10) > 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x30);
        if (temp_v0 == NULL) {
            goto block_8;
        }
        if (!(M2C_FIELD(temp_v0, s64 *, 0x148) & (0x8000 << 0x12))) {
block_8:
            SetJmpState(M2C_FIELD(arg0, s32 *, 0) + 0x2C0, 0xB, 0, 0);
            return;
        }
        WarpZapToSafePoint();
        return;
    }
    SetJtZapState(8);
}
