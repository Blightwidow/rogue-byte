#include "m2c_macros.h"

s32 func_00162050(s32);                             /* extern */

s32 AddTaskToggle(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp_v1;
    void *temp_s0;

    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xA8);
        if (temp_v1 < 0x20) {
            M2C_FIELD(arg0, s32 *, 0xA8) = (s32) (temp_v1 + 1);
            temp_s0 = M2C_FIELD(arg0, s32 *, 0xAC) + (temp_v1 * 0x10);
            M2C_FIELD(temp_s0, s32 *, 0) = arg1;
            M2C_FIELD(temp_s0, s32 *, 4) = arg3;
            temp_v0 = func_00162050(arg2);
            M2C_FIELD(temp_s0, s32 *, 0xC) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
            M2C_FIELD(temp_s0, s32 *, 8) = temp_v0;
        }
    }
}
