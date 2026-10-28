#include "m2c_macros.h"

M2C_UNK AppendDlEntry(s32, s32);                    /* extern */
M2C_UNK RemoveDlEntry(s32);                         /* extern */

void RetractSwRoot(void *arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = arg0 + 0x20;
    RemoveDlEntry(temp_s2);
    if (M2C_FIELD(arg0, s32 *, 0x39A4) == 0) {
        M2C_FIELD(arg0, s32 *, 0x39A4) = arg1;
    }
    AppendDlEntry(temp_s2, arg1);
}
