#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefSetArgsFromSplice__FiP4CRefP4OTYPe(void *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK SetTag__4CRef4TAGK(void *, M2C_UNK);        /* extern */
M2C_UNK func_002289B0(s32);                         /* extern */

s32 func_0010B8F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(sp, 0, arg3, 0);
    CRef_Destruct(sp);
    SetTag__4CRef4TAGK(sp, 0x24);
    func_002289B0(arg1);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
