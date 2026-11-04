#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
f32 SRadiusCrv(void *);                             /* extern */
M2C_UNK SetTnTnsOverride(s32, M2C_UNK);             /* extern */
extern f32 D_FLT_002BE8B4;

void AttachCrv_PostLoad(void *arg0) {
    s32 temp_a0;

    PostLoLoad();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x190);
    if (temp_a0 != 0) {
        SetTnTnsOverride(temp_a0, 0);
    }
    if (M2C_FIELD(arg0, f32 *, 0x38) == 1e10f) {
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) (SRadiusCrv(arg0) + D_FLT_002BE8B4);
    }
}
