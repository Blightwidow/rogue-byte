#include "m2c_macros.h"
extern "C" {

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefEval(void *);                            /* extern */
M2C_UNK __as__4CRefRC4CRef(s32, void *);            /* extern */

void EvalScriptCall(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x10];
    RefEval(sp);
    if (arg3 != 0) {
        __as__4CRefRC4CRef(arg3, sp);
    }
    CRef_Destruct(sp);
}
}
