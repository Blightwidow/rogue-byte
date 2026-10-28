#include "m2c_macros.h"

M2C_UNK UnsubscribeLoObject(s32, void *);           /* extern */

void HandleEmitterMessage(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 1) {
        if (arg2 != M2C_FIELD(arg0, s32 *, 0x14C)) {
            if (arg2 == M2C_FIELD(arg0, s32 *, 0x150)) {
                UnsubscribeLoObject(arg2, arg0);
                M2C_FIELD(arg0, s32 *, 0x150) = 0;
            }
        } else {
            UnsubscribeLoObject(arg2, arg0);
            M2C_FIELD(arg0, s32 *, 0x14C) = 0;
        }
    }
}
