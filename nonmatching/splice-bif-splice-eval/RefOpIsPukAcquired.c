#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CRef_SetBool(void *, s32);                  /* extern */
s32 FGadgetAcquired(s32, s32);                      /* extern */

s32 RefOpIsPukAcquired(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    CRef_SetBool(sp, FGadgetAcquired(M2C_FIELD(arg2, s32 *, 4), -1) != 0);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
