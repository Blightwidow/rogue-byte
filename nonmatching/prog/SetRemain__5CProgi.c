#include "m2c_macros.h"

M2C_UNK ClearFrameBuffers__Fv();                    /* extern */
M2C_UNK Draw__5CProg(void *);                       /* extern */

void SetRemain__5CProgi(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        if (M2C_FIELD(arg0, s32 *, 8) != 0) {
            if (M2C_FIELD(arg0, s32 *, 0xC) != arg1) {
                M2C_FIELD(arg0, s32 *, 0x50) = 0;
            } else {
                M2C_FIELD(arg0, s32 *, 0x50) = (s32) (M2C_FIELD(arg0, s32 *, 0x50) + 1);
            }
        } else {
            M2C_FIELD(arg0, s32 *, 8) = arg1;
            M2C_FIELD(arg0, s32 *, 4) = (s32) (arg1 * 2);
            ClearFrameBuffers__Fv();
        }
        M2C_FIELD(arg0, s32 *, 0xC) = arg1;
        Draw__5CProg(arg0);
    }
}
