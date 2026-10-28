#include "m2c_macros.h"

M2C_UNK UnsubscribeLoObject(s32, void *);           /* extern */

void HandleExplsMessage(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 1) {
        if (arg2 != M2C_FIELD(arg0, s32 *, 0x100)) {
            if (arg2 == M2C_FIELD(arg0, s32 *, 0x104)) {
                UnsubscribeLoObject(arg2, arg0);
                M2C_FIELD(arg0, s32 *, 0x104) = 0;
            }
        } else {
            UnsubscribeLoObject(arg2, arg0);
            M2C_FIELD(arg0, s32 *, 0x100) = 0;
        }
    }
}
