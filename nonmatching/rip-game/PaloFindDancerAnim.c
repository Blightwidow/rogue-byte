#include "m2c_macros.h"

void *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK B_003DD490;

void *PaloFindDancerAnim(s32 arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, arg1, arg0);
    if (temp_v0 != NULL) {
        temp_v0_2 = M2C_FIELD(temp_v0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x4C)(temp_v0 + M2C_FIELD(temp_v0_2, s16 *, 0x48));
    }
    return temp_v0;
}
