#include "m2c_macros.h"

void ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(void *arg0, s32 arg1, s32 arg2, s128 arg3, f32 fparg0, f32 fparg1) {
    char sp[0x400];
    M2C_UNK (*temp_a2)(void *, void *, M2C_UNK, s32, s32, f32, f32, s128, s128);
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    temp_a2 = M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *, M2C_UNK, s32, s32, f32, f32, s128, s128), 0x19C);
    temp_a2(arg0 + M2C_FIELD(temp_v0, s16 *, 0x198), sp, temp_a2, arg1, arg2, fparg0, fparg1, arg3, M2C_ERROR(/* Read from unset register $t0 */));
}
