#include "m2c_macros.h"

s32 FFindSurfaceAlongUp(void *, M2C_UNK, M2C_UNK, M2C_UNK, f32, s128); /* extern */
s128 PosLoWorld(void *);                            /* extern */

s32 FJtLandsWithin(void *arg0, f32 fparg0) {
    char sp[0x400];
    f32 temp_f21;
    f32 temp_f21_2;
    s32 var_v0;
    void *temp_v1;

    temp_f21 = M2C_FIELD(arg0, f32 *, 0x248);
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
    temp_f21_2 = temp_f21 + (fparg0 * M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */)) + (fparg0 * (fparg0 * 0.5f) * M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), f32 *, 0x88));
    var_v0 = 0;
    if (!(temp_f21_2 > 0.0f)) {
        var_v0 = FFindSurfaceAlongUp(sp, 0, 0, 0, temp_f21_2, PosLoWorld(arg0));
    }
    return var_v0;
}
