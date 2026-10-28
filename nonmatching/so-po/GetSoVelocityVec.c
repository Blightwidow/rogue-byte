#include "m2c_macros.h"

s128 VelocityXfAtPos(void *, M2C_UNK, s128);        /* extern */
extern s128 g_2a2dd0;

s128 GetSoVelocityVec(void *arg0) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x58);
    if (temp_a0 != NULL) {
        if (M2C_FIELD(temp_a0, s32 *, 0x94) == 1) {
            return VelocityXfAtPos(temp_a0, 0, M2C_FIELD(temp_a0, s128 *, 0x70));
        }
        goto block_4;
    }
block_4:
    return g_2a2dd0;
}
