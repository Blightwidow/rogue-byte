#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CRef_SetBasic(void *, M2C_UNK *, s32);      /* extern */
extern M2C_UNK B_003DD040;

s32 func_00124690(s32 arg0) {
    char sp[0x400];
    CRef_SetBasic(sp, &B_003DD040, -1);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
