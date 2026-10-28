#include "m2c_macros.h"

M2C_UNK SetMurrayState(void *, M2C_UNK);            /* extern */
M2C_UNK func_00131B60(s32, void *, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK D_002C09F8;

void EndMurrayAttack(void *arg0) {
    s32 temp_v0;

    func_00131B60(M2C_FIELD(arg0, s32 *, 0x1030), arg0, 5, &D_002C09F8);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1030);
    M2C_FIELD(arg0, s32 *, 0x1030) = 0;
    M2C_FIELD(arg0, s32 *, 0x190C) = temp_v0;
    SetMurrayState(arg0, 0);
}
