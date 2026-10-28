#include "m2c_macros.h"

M2C_UNK InitStackImpl__Fv();                        /* extern */

s32 CStackFrame_Construct(s32 arg0) {
    InitStackImpl__Fv();
    return arg0;
}
