#include "m2c_macros.h"

M2C_UNK RemoveDlEntry(s32, void *);                 /* extern */
M2C_UNK func_001A5448(s32, void *, s32 **);         /* extern */

void func_001A57A8(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    s32 *sp4;

    func_001A5448(M2C_FIELD(arg0, s32 *, 0x10), sp, &sp4);
    if (*sp4 == arg0) {
        *sp4 = M2C_FIELD(arg0, s32 *, 0x24);
    }
    RemoveDlEntry(sp0, arg0);
}
