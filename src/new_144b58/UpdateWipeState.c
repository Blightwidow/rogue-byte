#include "m2c_macros.h"

s32 FAsegaGone(s32);                                /* extern */
s32 FStreamPlaying(M2C_UNK *, s32);                 /* extern */
M2C_UNK ReleaseAsegaHandle(void *);                 /* extern */
M2C_UNK SetWipeState(void *, M2C_UNK);              /* extern */
extern M2C_UNK B_003DD040;

void UpdateWipeState(void *arg0) {
    s32 temp_a0;
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    switch (temp_v1) {                              /* irregular */
    case 0:
        SetWipeState(arg0, 1);
        return;
    case 3:
        if (FStreamPlaying(&B_003DD040, M2C_FIELD(arg0, s32 *, 0x170)) == 0) {
            SetWipeState(arg0, 2);
            return;
        }
        return;
    case 2:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x160);
        if ((temp_a0 == 0) || (FAsegaGone(temp_a0) != 0)) {
            ReleaseAsegaHandle(arg0 + 0x160);
            SetWipeState(arg0, -1);
        }
        break;
    }
}
