#include "m2c_macros.h"

M2C_UNK RemoveLoHierarchy();                        /* extern */
M2C_UNK SetVolbtnButtons(void *, M2C_UNK);          /* extern */

void RemoveVolbtn(void *arg0) {
    void *temp_v1;

    RemoveLoHierarchy();
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x1C0) - 1) < 2U) {
        SetVolbtnButtons(arg0, 0);
        if (M2C_FIELD(arg0, s32 *, 0x2C8) != 0) {
            M2C_FIELD(arg0, s32 *, 0x2C0) = 0;
            temp_v1 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 9, 0, 0);
        }
    }
}
