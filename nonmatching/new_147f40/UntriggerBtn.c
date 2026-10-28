#include "m2c_macros.h"

M2C_UNK RunBtnAsegs(void **, M2C_UNK);              /* extern */

void UntriggerBtn(void **arg0) {
    void *temp_a3;
    void *temp_t2;
    void *temp_v0;
    void *temp_v0_2;

    temp_t2 = *arg0;
    temp_v0 = M2C_FIELD(temp_t2, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_t2 + M2C_FIELD(temp_v0, s16 *, 0x18), 6, 0, 0);
    RunBtnAsegs(arg0, 1);
    temp_a3 = *arg0;
    temp_v0_2 = M2C_FIELD(temp_a3, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void **, void *), 0x24)(temp_a3 + M2C_FIELD(temp_v0_2, s16 *, 0x20), 7, arg0, temp_a3);
}
