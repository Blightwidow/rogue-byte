#include "m2c_macros.h"

void *PloNew(s32, s32, s32, M2C_UNK);               /* extern */

void *PloCloneLo(void *arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    if (arg0 != NULL) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        temp_v0 = PloNew(M2C_FIELD(M2C_FIELD(temp_v1, void *(**)(void *), 0x34)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x30)), s32 *, 4), arg1, M2C_FIELD(arg0, s32 *, 0x18), -1);
        temp_v0_2 = M2C_FIELD(temp_v0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x144)(temp_v0 + M2C_FIELD(temp_v0_2, s16 *, 0x140), arg0);
        return temp_v0;
    }
    return NULL;
}
