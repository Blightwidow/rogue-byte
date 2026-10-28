#include "m2c_macros.h"

void *PpoSwFocusBase(M2C_UNK *);                    /* extern */
M2C_UNK SetTnTnsOverride(s32, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD490;

void func_00140C88(s32 arg0, s32 arg1) {
    s32 temp_a0;
    void *temp_v0;

    temp_v0 = PpoSwFocusBase(&B_003DD490);
    if (temp_v0 == arg0) {
        temp_a0 = M2C_FIELD(temp_v0, s32 *, 0x1024);
        if (temp_a0 != 0) {
            SetTnTnsOverride(temp_a0, 0);
        }
        M2C_FIELD(temp_v0, s32 *, 0x1024) = arg1;
        if (arg1 != 0) {
            SetTnTnsOverride(arg1, 1);
        }
    }
}
