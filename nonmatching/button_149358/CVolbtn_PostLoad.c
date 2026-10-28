#include "m2c_macros.h"

M2C_UNK PostBtnLoad(s32);                           /* extern */
M2C_UNK PostLoLoad();                               /* extern */
s32 PvAllocSwImpl__Fi(void *, s32, s32);            /* extern */
M2C_UNK SetVolbtnButtons(void *, M2C_UNK);          /* extern */

void PostVolbtnLoad(void *arg0) {
    char sp[0x400];
    PostLoLoad();
    PostBtnLoad(arg0 + 0x130);
    SetVolbtnButtons(arg0, 0);
    if (M2C_FIELD(arg0, s32 *, 0x2C8) != 0) {
        M2C_FIELD(arg0, s32 *, 0x2C4) = PvAllocSwImpl__Fi(sp, 0x100, 0x10);
    }
}
