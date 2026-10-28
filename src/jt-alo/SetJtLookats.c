#include "m2c_macros.h"

M2C_UNK AddLookat(s32);                             /* extern */
M2C_UNK RemoveLookat(s32);                          /* extern */

void SetJtLookats(void *arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x19E4);
    if (temp_a0 != 0) {
        if (arg1 & 1) {
            AddLookat(temp_a0);
        } else {
            RemoveLookat(temp_a0);
        }
        if (arg1 & 2) {
            AddLookat(M2C_FIELD(arg0, s32 *, 0x19E8));
        } else {
            RemoveLookat(M2C_FIELD(arg0, s32 *, 0x19E8));
        }
        if (arg1 & 4) {
            AddLookat(M2C_FIELD(arg0, s32 *, 0x19EC));
        } else {
            RemoveLookat(M2C_FIELD(arg0, s32 *, 0x19EC));
        }
        if (arg1 & 8) {
            AddLookat(M2C_FIELD(arg0, s32 *, 0x19F0));
        } else {
            RemoveLookat(M2C_FIELD(arg0, s32 *, 0x19F0));
        }
        if (arg1 & 0x10) {
            AddLookat(M2C_FIELD(arg0, s32 *, 0x19F4));
        } else {
            RemoveLookat(M2C_FIELD(arg0, s32 *, 0x19F4));
        }
        if (arg1 & 0x20) {
            AddLookat(M2C_FIELD(arg0, s32 *, 0x19FC));
        } else {
            RemoveLookat(M2C_FIELD(arg0, s32 *, 0x19FC));
        }
        if (arg1 & 0x40) {
            AddLookat(M2C_FIELD(arg0, s32 *, 0x19F8));
            return;
        }
        RemoveLookat(M2C_FIELD(arg0, s32 *, 0x19F8));
    }
}
