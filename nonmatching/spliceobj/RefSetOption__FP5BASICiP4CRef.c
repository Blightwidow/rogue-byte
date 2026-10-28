#include "m2c_macros.h"

M2C_UNK CSidebag_RefSetBinding(s32, s32, s32);      /* extern */
s32 PeopidFind__FP5BASICi(void *, s32);             /* extern */
M2C_UNK RefSetPeopid(s32, void *, s32, s32);        /* extern */

s32 RefSetOption__FP5BASICiP4CRef(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    if (arg2 < 0x4D1) {
        RefSetPeopid(arg0, arg1, PeopidFind__FP5BASICi(arg1, arg2), arg3);
    } else {
        CSidebag_RefSetBinding(arg0, M2C_FIELD(arg1, s32 *, 4), arg3);
    }
    return arg0;
}
