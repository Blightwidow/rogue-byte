#include "m2c_macros.h"

s32 JT_FPosing();                                   /* extern */

void JT_EndPose(void *arg0) {
    void *temp_v0;

    if (JT_FPosing() != 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x2C4)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x2C0), 0);
    }
}
