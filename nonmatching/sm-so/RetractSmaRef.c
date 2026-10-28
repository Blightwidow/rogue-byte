#include "m2c_macros.h"

M2C_UNK RetractSma(void *);                         /* extern */

void RetractSmaRef(void **arg0) {
    void *temp_a0;
    void *temp_a1;
    void *temp_v0;

    temp_a0 = *arg0;
    if (temp_a0 != NULL) {
        RetractSma(temp_a0);
        temp_a1 = *arg0;
        temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x14)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x10), temp_a1);
        *arg0 = NULL;
    }
}
