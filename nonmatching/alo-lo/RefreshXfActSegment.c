#include "m2c_macros.h"

M2C_UNK SetXfKind(s32, void *, M2C_UNK);            /* extern */
M2C_UNK func_0022C818(s32, void *);                 /* extern */

void RefreshXfActSegment(s32 arg0, void *arg1) {
    f32 temp_f1;
    s16 temp_v1;
    u16 temp_v1_2;
    void *temp_a1;
    void *temp_v0;

    temp_f1 = *M2C_FIELD(arg1, f32 **, 0x88);
    if ((temp_f1 < M2C_FIELD(arg1, f32 *, 0x80)) || (M2C_FIELD(arg1, f32 *, 0x84) < temp_f1) || (M2C_FIELD(arg1, s16 *, 0x9A) >= 3)) {
        temp_a1 = M2C_FIELD(arg1, void **, 0x90);
        if (temp_a1 == NULL) {
            M2C_FIELD(arg1, s16 *, 0x9A) = 0;
            func_0022C818(arg0, arg1);
            SetXfKind(arg0, arg1, 0);
        } else {
            temp_v0 = M2C_FIELD(temp_a1, void **, 0x18);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x24)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x20), temp_a1);
            temp_v1 = M2C_FIELD(arg1, s16 *, 0x98);
            switch (temp_v1) {                      /* irregular */
            case 6:
                if ((u32) ((u16) M2C_FIELD(arg1, s16 *, 0x9A) - 3) < 2U) {
block_21:
                    SetXfKind(arg0, arg1, 7);
                    return;
                }
                break;
            case 19:
                if (M2C_FIELD(arg1, s16 *, 0x9A) != 2) {
                    SetXfKind(arg0, arg1, 0x12);
                    return;
                }
                break;
            case 10:
                temp_v1_2 = (u16) M2C_FIELD(arg1, s16 *, 0x9A);
                if ((u32) (temp_v1_2 - 3) >= 2U) {
                    if ((s16) temp_v1_2 != 2) {
                        SetXfKind(arg0, arg1, 6);
                        return;
                    }
                } else {
                    goto block_21;
                }
                break;
            case 12:
                if (M2C_FIELD(arg1, s16 *, 0x9A) != 2) {
                    SetXfKind(arg0, arg1, 0xB);
                    return;
                }
                break;
            }
        }
    }
}
