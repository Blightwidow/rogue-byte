#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK FFindBinding__6CFrameUiiP4CRef(s32, s32, M2C_UNK, void *, s32); /* extern */

s32 RefEvalSymbol(s32 arg0, void *arg1, s32 arg2) {
    char sp[0x400];
    FFindBinding__6CFrameUiiP4CRef(arg2, M2C_FIELD(arg1, s32 *, 0xC), 1, sp, -1);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
