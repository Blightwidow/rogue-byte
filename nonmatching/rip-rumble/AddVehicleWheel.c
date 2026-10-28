#include "m2c_macros.h"

void AddVehicleWheel(void *arg0, s32 arg1, f32 fparg0) {
    u32 temp_a3;
    void *temp_v0;

    temp_a3 = M2C_FIELD(arg0, u32 *, 0x190);
    if (temp_a3 < 8U) {
        M2C_FIELD(arg0, u32 *, 0x190) = (u32) (temp_a3 + 1);
        temp_v0 = arg0 + ((temp_a3 * 0x60) + 0x1A0);
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, f32 *, 0x20) = fparg0;
        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a2) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, ($a2) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x2b($v0) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0x24($v0) */);
    }
}
