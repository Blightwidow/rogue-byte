#include "m2c_macros.h"

s32 CbFill__10CByteQueueiP11CQueueInput(s32, void *, M2C_UNK *, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_002CBE20;

s32 CbFill__10CByteQueueiPUc(s32 arg1, s32 arg2) {
    char sp[0x400];
    s32 var_v0;

    var_v0 = 0;
    if (arg1 != 0) {
        var_v0 = CbFill__10CByteQueueiP11CQueueInput(arg1, sp, &D_002CBE20, arg2, arg1, 0, arg1);
    }
    return var_v0;
}
