#include "m2c_macros.h"

M2C_UNK func_00155788(void *, M2C_UNK);             /* extern */
s32 func_00155868(void *);                          /* extern */
M2C_UNK func_001EEF70();                            /* extern */
M2C_UNK func_00208540(void *, s32);                 /* extern */

void func_001555E0(void *arg0) {
    void *temp_v0;

    func_001EEF70();
    func_00208540(M2C_FIELD(arg0, void **, 0x10), M2C_FIELD(arg0, s32 *, 0x38));
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    if ((M2C_FIELD(temp_v0, s32 *, 0x1018) - M2C_FIELD(temp_v0, s32 *, 0x33C)) >= 0x5A) {
        M2C_FIELD(arg0, s32 *, 0x3C) = func_00155868(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_00155788(arg0, 0);
        return;
    }
    func_00155788(arg0, 1);
}
