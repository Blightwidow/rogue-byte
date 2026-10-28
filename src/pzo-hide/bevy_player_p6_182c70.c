#include "m2c_macros.h"

M2C_UNK func_001A6CA8(s32, M2C_UNK);                /* extern */

void bevy_player_p6_182c70(void *arg0) {
    s16 temp_a1;
    void *temp_v1;

    M2C_FIELD(arg0, s32 *, 0x14) = -1;
    M2C_FIELD(arg0, f32 *, 8) = 3.4028235e38f;
    temp_v1 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(arg0, s32 *, 0x1C) = 7;
    temp_a1 = M2C_FIELD(temp_v1, s16 *, 0x30);
    func_001A6CA8(M2C_FIELD(temp_v1, s32 (**)(void *, s16), 0x34)(arg0 + temp_a1, temp_a1), 3);
}
