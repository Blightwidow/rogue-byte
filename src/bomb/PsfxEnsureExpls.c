#include "m2c_macros.h"

s32 NewSfx__FPP3SFX();                              /* extern */

s32 PsfxEnsureExpls(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xF0) == 0) {
        M2C_FIELD(arg0, s32 *, 0xF0) = NewSfx__FPP3SFX();
    }
    return M2C_FIELD(arg0, s32 *, 0xF0);
}
