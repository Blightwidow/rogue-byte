#include "m2c_macros.h"

M2C_UNK func_00213B00();             /* extern */
extern f32 g_2ddf0c;

void SetEpselHint(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x12C) != arg1) {
        if (arg1 != 0) {
            if (arg1 == 1) {
                func_00213B00((void *)0x5BD);
            }
        } else {
            func_00213B00(arg0, 0x5BE);
        }
        M2C_FIELD(arg0, s32 *, 0x12C) = arg1;
        M2C_FIELD(arg0, f32 *, 0x130) = (f32) g_2ddf0c;
    }
}
