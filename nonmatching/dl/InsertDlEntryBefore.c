#include "m2c_macros.h"

M2C_UNK AppendDlEntry();                    /* extern */
M2C_UNK PrependDlEntry();                   /* extern */

void InsertDlEntryBefore(void *arg0, s32 arg1, s32 arg2) {
    u8 *temp_v0;
    s32 temp_v1;
    void *temp_a0;
    void *temp_a1;

    if (arg1 == 0) {
        AppendDlEntry(arg2, arg1);
        return;
    }
    if (arg1 != M2C_FIELD(arg0, s32 *, 0)) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 8);
        temp_a1 = arg1 + temp_v1;
        temp_a0 = arg2 + temp_v1;
        temp_v0 = M2C_FIELD(temp_a1, s32 *, 4);
        M2C_FIELD(temp_a0, s32 *, 0) = arg1;
        M2C_FIELD(temp_a0, s32 *, 4) = temp_v0;
        M2C_FIELD(temp_a1, s32 *, 4) = arg2;
        *(temp_v0 + temp_v1) = arg2;
        return;
    }
    PrependDlEntry(arg2, arg1);
}
