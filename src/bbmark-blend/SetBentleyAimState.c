#include "m2c_macros.h"

M2C_UNK SetLookRigState(void *, M2C_UNK);           /* extern */
extern f32 g_2dded0;

void SetBentleyAimState(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x16BC)) {
        M2C_FIELD(arg0, s32 *, 0x16BC) = arg1;
        M2C_FIELD(arg0, f32 *, 0x16C0) = (f32) g_2dded0;
        if (arg1 == 0) {
            SetLookRigState(arg0 + 0x1710, -1);
        }
    }
}
