#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CRef_SetS32(void *, s32);                   /* extern */
s32 NGetSensorLoState(s32, s32);                    /* extern */
M2C_UNK RefSetArgsFromSplice__FiP4CRefP4OTYPe(void *, M2C_UNK, s32, s32 *); /* extern */

s32 RefPchzFriendlyFromWidOwner(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    s32 sp10;
    s32 sp14;

    sp10 = 0x2002;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(sp, 1, arg3, &sp10);
    CRef_SetS32(sp, NGetSensorLoState(M2C_FIELD(arg1, s32 *, 0xF64), sp14));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
