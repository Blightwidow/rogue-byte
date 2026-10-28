#include "m2c_macros.h"

M2C_UNK func_001EEF70();                            /* extern */
void *func_00205438(s32, M2C_UNK);                  /* extern */

void func_0017D2E0(void *arg0) {
    void *temp_a1;
    void *temp_v0;

    func_001EEF70();
    temp_v0 = func_00205438(M2C_FIELD(arg0, s32 *, 0x10), 0x9D);
    temp_a1 = M2C_FIELD(temp_v0, void **, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x3C) = 2;
    M2C_FIELD(temp_a1, M2C_UNK (**)(void *, void *), 0x44)(temp_v0 + M2C_FIELD(temp_a1, s16 *, 0x40), temp_a1);
}
