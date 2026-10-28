#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK RequestTaskState(s32, M2C_UNK, void *);     /* extern */
M2C_UNK func_0019D948(s32);                         /* extern */
extern M2C_UNK B_003DD490;

void SetReconTargetDone(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0xEC);
    if (temp_a0 == 0) {
        M2C_FIELD(arg0, s32 *, 0xF0) = arg1;
        return;
    }
    RequestTaskState(temp_a0, 2, arg0);
    temp_v0 = PpoSwFocusBase(&B_003DD490);
    if ((temp_v0 != 0) && (FIsBasicDerivedFrom(temp_v0, 0x34) != 0)) {
        func_0019D948(temp_v0 + 0xF24);
    }
}
