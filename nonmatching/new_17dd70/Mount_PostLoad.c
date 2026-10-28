#include "m2c_macros.h"

M2C_UNK SetXfKind(void *, s32, M2C_UNK);            /* extern */
M2C_UNK func_0017F138();                            /* extern */
M2C_UNK func_0017F408(void *, M2C_UNK, void *);     /* extern */
M2C_UNK func_0017F770(void *);                      /* extern */

void Mount_PostLoad(void *arg0) {
    void *temp_v0;

    func_0017F138();
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x27C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x278), 0);
    SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 2);
    SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 2);
    func_0017F770(arg0);
    func_0017F408(arg0, 5, arg0 + 0x1C8);
}
