#include "m2c_macros.h"

M2C_UNK AddAlertGuard(s32, void *);                 /* extern */
s32 PalertEnsure(s32);                              /* extern */
M2C_UNK RemoveAlertGuard(s32, void *);              /* extern */

void func_00208540(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x38C);
    if (arg1 != temp_v0) {
        if (temp_v0 != 0) {
            RemoveAlertGuard(M2C_FIELD(arg0, s32 *, 0x3CC), arg0);
            M2C_FIELD(arg0, s32 *, 0x3CC) = 0;
        }
        M2C_FIELD(arg0, s32 *, 0x38C) = arg1;
        if (arg1 != 0) {
            temp_v0_2 = PalertEnsure(arg1);
            M2C_FIELD(arg0, s32 *, 0x3CC) = temp_v0_2;
            AddAlertGuard(temp_v0_2, arg0);
        }
    }
}
