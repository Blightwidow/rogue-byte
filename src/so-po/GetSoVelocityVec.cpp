#include "m2c_macros.h"
extern "C" {

s128 VelocityXfAtPos(s8 *, s32, s128);        /* extern */
extern s128 g_2a2dd0;

s128 GetSoVelocityVec(s8 *arg0) {
    s8 *temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 **, 0x58);
    if (temp_a0 == NULL || M2C_FIELD(temp_a0, s32 *, 0x94) != 1) {
        return g_2a2dd0;
    }
    return VelocityXfAtPos(temp_a0, 0, M2C_FIELD(temp_a0, s128 *, 0x70));
}

}
