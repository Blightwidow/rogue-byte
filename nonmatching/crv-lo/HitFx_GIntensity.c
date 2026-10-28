#include "m2c_macros.h"

extern M2C_UNK g_2bdcf0;

f32 HitFx_GIntensity(void *arg0) {
    f32 temp_f1;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x14);
    if (!(M2C_FIELD(temp_a1, f32 *, 0x60) > 0.0f)) {
        return M2C_FIELD(temp_a1, f32 *, 0x54);
    }
    M2C_ERROR(/* unknown instruction: min.s $f0, $f2, $f0 */);
    temp_f1 = M2C_ERROR(/* unknown instruction: min.s $f1, $f1, $f4 */);
    return M2C_FIELD(temp_a1, f32 *, 0x54) * (M2C_FIELD(&g_2bdcf0, f32 *, 0) + (temp_f1 * (M2C_FIELD(&g_2bdcf0, f32 *, 4) + (temp_f1 * M2C_FIELD(&g_2bdcf0, f32 *, 8)))));
}
