#include "m2c_macros.h"

M2C_UNK MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(s32 *, s128, void *, s128, s32); /* extern */

f32 GMeasureJumpToHshape(void *arg0) {
    s128 sp10;
    f32 sp20;
    void *temp_a0;
    void *temp_t0;

    temp_a0 = M2C_FIELD(arg0, void **, 4);
    temp_t0 = M2C_FIELD(temp_a0, void **, 0x1B0);
    M2C_FIELD(temp_t0, M2C_UNK (**)(void *, s32, s128 *, M2C_UNK), 0x1C)(temp_a0 + 0x190 + M2C_FIELD(temp_t0, s16 *, 0x18), *M2C_FIELD(arg0, s32 **, 0), &sp10, 0);
    MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(M2C_FIELD(arg0, s32 **, 0), M2C_FIELD(arg0, s128 *, 0x10), M2C_FIELD(arg0, void **, 4), sp10, 0);
    return sp20;
}
