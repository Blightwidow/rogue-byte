#include "m2c_macros.h"

f32 MarkClockTickRealOnly__FP5CLOCK(M2C_UNK *);     /* extern */
extern M2C_UNK B_003DD040;
extern M2C_UNK g_2bbb60;

f32 GAccuracyRhythmCue(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 var_f0;
    f32 var_f1;

    temp_f0_2 = MarkClockTickRealOnly__FP5CLOCK(&B_003DD040);
    temp_f0_3 = M2C_FIELD(arg1, f32 *, 0xC);
    if (!(temp_f0_2 < temp_f0_3)) {
        var_f1 = temp_f0_2 - temp_f0_3;
        var_f0 = M2C_FIELD(arg0, f32 *, 0x5C);
    } else {
        var_f1 = temp_f0_3 - temp_f0_2;
        var_f0 = M2C_FIELD(arg0, f32 *, 0x58);
    }
    temp_f0 = 1.0f - (var_f1 / var_f0);
    return ((1.0f - temp_f0) * M2C_FIELD(&g_2bbb60, f32 *, 0)) + (temp_f0 * M2C_FIELD(&g_2bbb60, f32 *, 4));
}
