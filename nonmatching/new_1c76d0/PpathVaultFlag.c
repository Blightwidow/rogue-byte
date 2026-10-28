#include "m2c_macros.h"

s32 IdCurrentLevel();                               /* extern */
s32 PpathConcatStack(s32, void *);                  /* extern */
s16 SymidFindSymtab(void *, M2C_UNK *);             /* extern */
s32 func_002109B8(s32, s16 *, s32, s16 *);          /* extern */
extern M2C_UNK B_003E0EA8;

s32 PpathVaultFlag(void) {
    char sp[0x400];
    s16 sp10;
    s32 temp_v0;

    temp_v0 = IdCurrentLevel();
    if (temp_v0 != -1) {
        sp10 = SymidFindSymtab(&B_003E0EA8 + 8, "fVault");
        return PpathConcatStack(func_002109B8(temp_v0, &sp10, 1, &sp10), sp);
    }
    return 0;
}
