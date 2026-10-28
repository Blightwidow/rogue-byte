#include "m2c_macros.h"

M2C_UNK FFindSaveVar(void *);                       /* extern */
extern M2C_UNK D_002C2D90;

s32 PvFindSaveVar(s32 arg2) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp4;
    FFindSaveVar(sp);
    return arg2 + (M2C_FIELD(sp0, u16 *, 4) + (sp4 * *((M2C_FIELD(sp0, s8 *, 2) * 4) + &D_002C2D90)));
}
