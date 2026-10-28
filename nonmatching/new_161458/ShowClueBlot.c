#include "m2c_macros.h"

M2C_UNK func_00212A30(void *);                      /* extern */

void ShowClueBlot(void *arg0) {
    void *temp_s0;
    void *temp_v0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x3BB8);
    if (temp_s0 != NULL) {
        temp_v0 = M2C_FIELD(temp_s0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x18C)(temp_s0 + M2C_FIELD(temp_v0, s16 *, 0x188), -1);
        func_00212A30(temp_s0);
    }
}
