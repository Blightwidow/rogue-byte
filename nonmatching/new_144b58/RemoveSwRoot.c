#include "m2c_macros.h"

s32 FFindDlEntry(s32);                              /* extern */
M2C_UNK RemoveDlEntry(s32, void *);                 /* extern */

void RemoveSwRoot(void *arg0, void *arg1) {
    s32 temp_s2;

    temp_s2 = arg0 + 0x20;
    if (FFindDlEntry(temp_s2) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x39A4) == arg1) {
            M2C_FIELD(arg0, s32 *, 0x39A4) = (s32) M2C_FIELD(arg1, s32 *, 4);
        }
        RemoveDlEntry(temp_s2, arg1);
    }
}
