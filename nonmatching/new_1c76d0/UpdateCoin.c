#include "m2c_macros.h"

M2C_UNK UpdateDprize();                             /* extern */
extern f32 g_2dded4;

void UpdateCoin(void *arg0) {
    f32 temp_f0;
    void *temp_v0;

    UpdateDprize();
    if (M2C_FIELD(arg0, s32 *, 0x150) == 0) {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x238) - g_2dded4;
        M2C_FIELD(arg0, f32 *, 0x238) = temp_f0;
        if (temp_f0 <= 0.0f) {
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), 5);
        }
    }
}
