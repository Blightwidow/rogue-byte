#include "m2c_macros.h"

f32 GRandInRange(f32, f32);                         /* extern */
extern f32 g_2dded0;

void ScheduleJtGlance(void *arg0) {
    f32 temp_f20;
    f32 var_f12;
    f32 var_f13;

    if (M2C_FIELD(arg0, s32 *, 0x1148) != 0) {
        var_f12 = M2C_FIELD(arg0, f32 *, 0x1138);
        var_f13 = M2C_FIELD(arg0, f32 *, 0x113C);
    } else {
        var_f12 = M2C_FIELD(arg0, f32 *, 0x1140);
        var_f13 = M2C_FIELD(arg0, f32 *, 0x1144);
    }
    temp_f20 = g_2dded0;
    M2C_FIELD(arg0, f32 *, 0x114C) = (f32) (temp_f20 + GRandInRange(var_f12, var_f13));
}
