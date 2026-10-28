#include "m2c_macros.h"

void AddTaskAnim(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v1;
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xB0);
        if (temp_v1 < 0x20) {
            M2C_FIELD(arg0, s32 *, 0xB0) = (s32) (temp_v1 + 1);
            temp_v0 = M2C_FIELD(arg0, s32 *, 0xB4) + (temp_v1 * 0x18);
            M2C_FIELD(temp_v0, s32 *, 0x14) = (s32) M2C_ERROR(/* Read from unset register $t2 */);
            M2C_FIELD(temp_v0, s32 *, 0) = arg1;
            M2C_FIELD(temp_v0, s32 *, 4) = arg2;
            M2C_FIELD(temp_v0, s32 *, 8) = arg3;
            M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
            M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_ERROR(/* Read from unset register $t1 */);
        }
    }
}
