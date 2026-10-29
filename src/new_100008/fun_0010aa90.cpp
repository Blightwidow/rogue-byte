#include "m2c_macros.h"
extern "C" {

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CRef_SetBool(void *, s32);                  /* extern */
M2C_UNK RefSetArgsFromSplice__FiP4CRefP4OTYPe(void *, M2C_UNK, s32, M2C_UNK); /* extern */
s32 func_001424C0(s32);                             /* extern */

s32 func_0010AA90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x10];
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(sp, 0, arg3, 0);
    CRef_SetBool(sp, func_001424C0(arg1) != 0);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
