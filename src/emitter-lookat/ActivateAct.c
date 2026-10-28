#include "m2c_macros.h"

M2C_UNK InvalidateXfSegment(s32, s32);              /* extern */
M2C_UNK SetXfKind(s32, s32, s32);                   /* extern */

void ActivateAct(void *arg0) {
    SetXfKind(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x14));
    InvalidateXfSegment(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8));
}
