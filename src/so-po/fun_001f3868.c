#include "m2c_macros.h"

QW PosLoWorld();                                    /* extern */
s32 PpathzoneFindPos(QW, s32);                      /* extern */
void func_001F37C8(s32, s32);                       /* extern */

void func_001F3868(s32 arg0) {
    func_001F37C8(arg0, PpathzoneFindPos(PosLoWorld(), 1));
}
