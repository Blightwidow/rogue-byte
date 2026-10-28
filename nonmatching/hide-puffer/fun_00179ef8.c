#include "m2c_macros.h"

f32 GRandInRange(f32, f32);                         /* extern */
extern f32 g_2dded0;

void func_00179EF8(void *arg0) {
    f32 temp_f12;
    f32 temp_f20;
    void *temp_v0;

    if (!(M2C_FIELD(arg0, f32 *, 0x34) < 3.4028235e38f)) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x10);
        temp_f12 = M2C_FIELD(temp_v0, f32 *, 0x2D4);
        if (temp_f12 != 3.4028235e38f) {
            temp_f20 = g_2dded0;
            M2C_FIELD(arg0, f32 *, 0x34) = (f32) (temp_f20 + GRandInRange(temp_f12, M2C_FIELD(temp_v0, f32 *, 0x2D8)));
        } else {
            M2C_FIELD(arg0, f32 *, 0x34) = 3.4028235e38f;
        }
    }
}
