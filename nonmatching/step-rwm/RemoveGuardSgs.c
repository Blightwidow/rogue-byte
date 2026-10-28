#include "m2c_macros.h"

s32 GrfsgsFromSgs(s32);                             /* extern */
M2C_UNK SetGuardGrfsgs(void *, s32);                /* extern */

void RemoveGuardSgs(void *arg0, s32 arg1) {
    s32 sp10;
    s32 sp14;
    void *temp_v1;

    sp14 = arg1;
    SetGuardGrfsgs(arg0, M2C_FIELD(arg0, s64 *, 0x2C0) & ~GrfsgsFromSgs(arg1));
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    sp10 = -1;
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32 *, s32 *), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 7, 0, 2, &sp10, &sp14);
}
