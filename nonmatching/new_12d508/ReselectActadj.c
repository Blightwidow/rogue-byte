#include "m2c_macros.h"

M2C_UNK InvalidateXfSegment(s32, s32);              /* extern */

void ReselectActadj(void *arg0) {
    void *temp_a1;
    void *temp_a1_2;
    void *temp_v0;
    void *temp_v0_2;

    if (M2C_FIELD(arg0, void **, 0x1C) != M2C_FIELD(arg0, void **, 0x10)) {
        InvalidateXfSegment(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8));
        temp_a1 = M2C_FIELD(arg0, void **, 0x1C);
        if (temp_a1 != NULL) {
            temp_v0 = M2C_FIELD(temp_a1, void **, 0x18);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x14)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x10), temp_a1);
        }
        temp_a1_2 = M2C_FIELD(arg0, void **, 0x10);
        M2C_FIELD(arg0, void **, 0x1C) = temp_a1_2;
        if (temp_a1_2 != NULL) {
            temp_v0_2 = M2C_FIELD(temp_a1_2, void **, 0x18);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0xC)(temp_a1_2 + M2C_FIELD(temp_v0_2, s16 *, 8), temp_a1_2);
        }
    }
}
