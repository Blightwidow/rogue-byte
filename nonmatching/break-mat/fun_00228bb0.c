#include "m2c_macros.h"

M2C_UNK func_001F3590();                            /* extern */
M2C_UNK func_001F68A8(void *, M2C_UNK);             /* extern */

void func_00228BB0(void *arg0) {
    void *temp_v0;

    func_001F3590();
    func_001F68A8(arg0, 1);
    temp_v0 = M2C_FIELD(arg0, void **, 0xE8);
    M2C_FIELD(temp_v0, f32 *, 0xD4) = 1.0f;
    M2C_FIELD(temp_v0, f32 *, 0xD8) = 1.0f;
}
