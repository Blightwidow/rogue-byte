#include "m2c_macros.h"

void *PpoSwFocusBase(M2C_UNK *);                    /* extern */
extern M2C_UNK B_003DD490;

void func_00228170(void *arg0) {
    void *temp_t1;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = PpoSwFocusBase(&B_003DD490);
    if (temp_v0 != NULL) {
        temp_v0_2 = M2C_FIELD(temp_v0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *, void *), 0x134)(temp_v0 + M2C_FIELD(temp_v0_2, s16 *, 0x130), arg0, temp_v0);
        temp_t1 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_t1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_t1, s16 *, 0x18), 5, 0, 0);
    }
}
