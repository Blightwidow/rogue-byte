#include "m2c_macros.h"

M2C_UNK ReleaseJtLookHold(void *);                  /* extern */

void SetJtLookTarget(void *arg0, s32 arg1, s32 arg2) {
    if ((arg2 != M2C_FIELD(arg0, s32 *, 0x10F8)) || (arg1 != M2C_FIELD(arg0, s32 *, 0x10FC))) {
        M2C_FIELD(arg0, s32 *, 0x10FC) = arg1;
        M2C_FIELD(arg0, s32 *, 0x10F8) = arg2;
        if (arg2 != 0) {
            if (M2C_FIELD(arg0, f32 *, 0x114C) != 3.4028235e38f) {
                M2C_FIELD(arg0, s32 *, 0x1148) = 1;
                ReleaseJtLookHold(arg0);
            }
        }
    }
}
