#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefSetArgsFromSplice__FiP4CRefP4OTYPe(void *, M2C_UNK, s32, s32 *); /* extern */
M2C_UNK SetTag__4CRef4TAGK(void *, M2C_UNK);        /* extern */
M2C_UNK SnapAsega(s32, s32);                        /* extern */

s32 RefCallSnapAsega(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    s32 sp10;
    s32 sp14;

    sp10 = 0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(sp, 1, arg3, &sp10);
    CRef_Destruct(sp);
    SetTag__4CRef4TAGK(sp, 0x24);
    SnapAsega(arg1, sp14);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
