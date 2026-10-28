#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, M2C_UNK *);         /* extern */
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
M2C_UNK RefOpHitTestObjectsImpl(M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK __as__4CRefRC4CRef(M2C_UNK *, M2C_UNK *);   /* extern */

s32 RefOpHitTestObjects(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    M2C_UNK sp10;

    RefOpHitTestObjectsImpl(&sp10, 0x7B, arg1, arg2, -1);
    __as__4CRefRC4CRef(sp, &sp10);
    CRef_Destruct(&sp10);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
