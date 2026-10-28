#include "m2c_macros.h"

s32 FAsegaGone(s32);                                /* extern */

void bevy_player_p25_1371c8(void **arg0) {
    void *temp_a2;
    void *temp_v0;

    if (FAsegaGone(M2C_FIELD(*arg0, s32 *, 0x1030)) != 0) {
        temp_a2 = *arg0;
        temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x2C0), 0, temp_a2);
    }
}
