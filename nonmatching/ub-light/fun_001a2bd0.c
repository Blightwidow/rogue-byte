#include "m2c_macros.h"

M2C_UNK func_001A2C48(void *, s32 **);              /* extern */
extern s32 B_002E1E54;

void func_001A2BD0(s32 arg0) {
    char sp[0x400];
    s32 *sp4;

    if (arg0 == -1) {
        func_001A2C48(sp, &sp4);
        B_002E1E54 = *sp4;
        return;
    }
    B_002E1E54 = arg0;
}
