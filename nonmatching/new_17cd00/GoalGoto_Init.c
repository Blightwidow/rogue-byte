#include "m2c_macros.h"

M2C_UNK func_001EEF68();                            /* extern */
extern void *B_003E1A5C;

void GoalGoto_Init(void *arg0) {
    func_001EEF68();
    M2C_FIELD(arg0, s32 *, 0x38) = -1;
    M2C_FIELD(arg0, f32 *, 0xA0) = -3.4028235e38f;
    M2C_FIELD(arg0, s32 *, 0x30) = -1;
    M2C_FIELD(arg0, s32 *, 0xA4) = (s32) M2C_FIELD(B_003E1A5C, s32 *, 0x28);
}
