#include "m2c_macros.h"

M2C_UNK ProjectSoTransform(void *);                 /* extern */

void ProjectSlotSoTransform(void *arg0) {
    s32 temp_v1;
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x220);
    if ((temp_v1 < 4) && (temp_v1 >= 2)) {
        temp_v1_2 = M2C_FIELD(arg0, void **, 0x58);
        temp_v0 = temp_v1_2 + 0xF0;
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
        M2C_FIELD(temp_v0, s32 *, 8) = 0;
        M2C_FIELD(temp_v1_2, s32 *, 0xF0) = 0;
        temp_a0 = M2C_FIELD(arg0, void **, 0x5C);
        temp_v0_2 = temp_a0 + 0xF0;
        M2C_FIELD(temp_v0_2, s32 *, 4) = 0;
        M2C_FIELD(temp_v0_2, s32 *, 8) = 0;
        M2C_FIELD(temp_a0, s32 *, 0xF0) = 0;
        temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *), 0x234)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x230));
    }
    ProjectSoTransform(arg0);
}
