#include "m2c_macros.h"

M2C_UNK CloneGuardAnimrefs(void *);                 /* extern */
M2C_UNK CloneStep();                                /* extern */
M2C_UNK func_00209770(void *, void *);              /* extern */

void CloneGuard(void *arg0, void *arg1) {
    void *temp_s1;
    void *temp_v0;

    temp_s1 = M2C_FIELD(arg0, void **, 0xF64);
    CloneStep();
    func_00209770(arg0 + 0xFD0, arg0);
    M2C_FIELD(arg0, void **, 0xF64) = temp_s1;
    temp_v0 = M2C_FIELD(temp_s1, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s32), 0x14C)(temp_s1 + M2C_FIELD(temp_v0, s16 *, 0x148), M2C_FIELD(arg1, s32 *, 0xF64));
    CloneGuardAnimrefs(arg0);
}
