#include "m2c_macros.h"

M2C_UNK JT_EndPose(s32);                            /* extern */
M2C_UNK RetractAsega(void *);                       /* extern */

void ReleaseSeqnodeAnim(void *arg0) {
    s32 temp_a0_2;
    void *temp_a0;
    void *temp_a1;
    void *temp_v0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x4C);
    if (temp_a0 != NULL) {
        RetractAsega(temp_a0);
        temp_a1 = M2C_FIELD(arg0, void **, 0x4C);
        temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x14)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x10), temp_a1);
        M2C_FIELD(arg0, void **, 0x4C) = NULL;
    }
    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x54);
    if (temp_a0_2 != 0) {
        JT_EndPose(temp_a0_2);
        M2C_FIELD(arg0, s32 *, 0x54) = 0;
    }
}
