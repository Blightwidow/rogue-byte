#include "m2c_macros.h"

M2C_UNK FreeSlotheapPv(M2C_UNK *, void *, s32);     /* extern */
extern M2C_UNK B_003E1144;

void UnsubscribeLoObject(s32 arg0, s32 arg1) {
    s32 temp_v0;
    void **var_v1;
    void *temp_a1;

    var_v1 = arg0 + 8;
loop_1:
    temp_a1 = *var_v1;
    if (temp_a1 != NULL) {
        if (M2C_FIELD(temp_a1, s32 *, 0) != arg1) {
            var_v1 = temp_a1 + 8;
            goto loop_1;
        }
        temp_v0 = M2C_FIELD(temp_a1, s32 *, 4) - 1;
        M2C_FIELD(temp_a1, s32 *, 4) = temp_v0;
        if (temp_v0 <= 0) {
            *var_v1 = M2C_FIELD(temp_a1, void **, 8);
            FreeSlotheapPv(&B_003E1144, temp_a1, arg1);
        }
    }
}
