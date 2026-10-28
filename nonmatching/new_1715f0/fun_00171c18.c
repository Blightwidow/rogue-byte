#include "m2c_macros.h"

M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void func_00171C18(void *arg0, void *arg1) {
    s32 *temp_v1;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF80);
    if (temp_a2 == -1) {
        temp_v1 = M2C_FIELD(arg0, s32 **, 0x38);
        M2C_FIELD(arg1, s32 **, 0) = temp_v1;
        M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
        if (temp_v1 != NULL) {
            if (*temp_v1 == 6) {
                M2C_FIELD(arg1, f32 *, 8) = (f32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), f32 *, 0x38);
            }
        }
    } else if ((temp_a2 >= -1) && (temp_a2 < 2)) {
        memset(arg1, 0, 0xC);
    }
}
