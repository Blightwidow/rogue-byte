#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK PsmaApplySm(void *, s32, s32, s32);         /* extern */
extern M2C_UNK B_003DD490;

void PostSmLoad(void *arg0) {
    void *temp_a2;
    void *temp_v1;

    PostLoLoad();
    temp_a2 = M2C_FIELD(arg0, void **, 0x74);
    if (temp_a2 != NULL) {
        temp_v1 = M2C_FIELD(arg0, void **, 0x74);
        PsmaApplySm(arg0, PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(temp_a2, s32 *, 0), arg0), M2C_FIELD(temp_v1, s32 *, 4), M2C_FIELD(temp_v1, s32 *, 8));
    }
}
