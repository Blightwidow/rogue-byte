#include "m2c_macros.h"

M2C_UNK func_00131B10(s32, void *, s32);            /* extern */

void HandleLookRigMessage(void *arg0, s32 arg1, void *arg2) {
    s32 temp_a0;
    s32 temp_a2;
    void *temp_a1;

    if ((arg1 == 9) && (temp_a0 = M2C_FIELD(arg2, s32 *, 0), (temp_a0 == M2C_FIELD(arg0, s32 *, 0xE0)))) {
        temp_a2 = M2C_FIELD(arg2, s32 *, 8);
        switch (temp_a2) {                          /* irregular */
        case 0x16E:
            temp_a1 = M2C_FIELD(arg0, void **, 0);
            func_00131B10(temp_a0, temp_a1, M2C_FIELD(temp_a1, s32 *, 0x10B8));
            M2C_FIELD(arg0, s32 *, 0x10) = 1;
            return;
        case 0x242:
            M2C_FIELD(arg0, s32 *, 0xC) = 1;
            break;
        }
    }
}
