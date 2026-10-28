#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
M2C_UNK RequestTaskState(s32, s32, s32);            /* extern */
extern M2C_UNK B_003DD490;

void ApplyTaskStateRequests(s32 arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 temp_v0;
    s32 var_s1;
    void *var_s0;

    if (arg1 > 0) {
        var_s0 = arg2;
        var_s1 = arg1;
        do {
            temp_v0 = PloFindSwObject_thunk(&B_003DD490, 0x105, M2C_FIELD(var_s0, s32 *, 0), arg3);
            if (temp_v0 != 0) {
                RequestTaskState(temp_v0, M2C_FIELD(var_s0, s32 *, 4), arg3);
            }
            var_s1 -= 1;
            var_s0 += 8;
        } while (var_s1 != 0);
    }
}
