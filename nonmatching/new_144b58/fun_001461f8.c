#include "m2c_macros.h"

M2C_UNK func_00146650(void *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF70();                            /* extern */

void func_001461F8(void *arg0) {
    void *temp_a0;
    void *temp_t1;
    void *temp_v0;

    func_001EEF70();
    func_00146650(arg0, 0);
    temp_t1 = M2C_FIELD(arg0, void **, 0x10);
    temp_v0 = M2C_FIELD(temp_t1, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, s32, M2C_UNK), 0x2FC)(temp_t1 + M2C_FIELD(temp_v0, s16 *, 0x2F8), 4, M2C_FIELD(arg0, s32 *, 0x38), 4);
    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_a0, s32 *, 0x10E0) = (s32) (M2C_FIELD(temp_a0, s32 *, 0x10E0) | 1);
}
