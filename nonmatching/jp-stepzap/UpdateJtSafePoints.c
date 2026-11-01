#include "m2c_macros.h"

M2C_UNK AddSafePointOnGeom(void *, s32, s128, void *); /* extern */
M2C_UNK AddSafePointOnMember(void *, void *, void *, M2C_UNK); /* extern */
M2C_UNK UpdateJtPipeLook(void *, u32, void *);      /* extern */
M2C_UNK func_001942F0(void *, u32, void *);         /* extern */

void UpdateJtSafePoints(void *arg0) {
    u32 temp_a1;
    void *temp_a1_2;
    void *temp_v1;

    temp_a1 = M2C_FIELD(arg0, u32 *, 0x18C8);
    switch (temp_a1) {
    case 0:
    case 1:
    case 5:
    case 6:
    case 9:
    case 10:
    case 11:
    case 12:
    case 15:
    case 16:
    case 17:
    case 20:
    case 23:
    case 24:
        temp_a1_2 = M2C_FIELD(arg0, void **, 0x208);
        if ((temp_a1_2 != NULL) && (M2C_FIELD(temp_a1_2, f32 *, 0x88) > 0.7f) && !(M2C_FIELD(M2C_FIELD(temp_a1_2, void **, 0x4C), s64 *, 0x148) & 0x20000000) && (M2C_FIELD(arg0, s32 *, 0x108C) == 0)) {
            AddSafePointOnGeom(arg0 + 0x9E0, M2C_FIELD(temp_a1_2, s32 *, 0x40), M2C_FIELD(temp_a1_2, s128 *, 0x60), arg0);
        default:
        }
        break;
    case 3:
    case 22:
        temp_v1 = M2C_FIELD(arg0, void **, 0x18C4);
        if (M2C_FIELD(temp_v1, s32 *, 0x10C) == 0) {
            AddSafePointOnMember(arg0 + 0x9E0, (temp_v1 == NULL) ? NULL : (temp_v1 + 0x100), arg0, 0);
        }
        break;
    case 7:
        func_001942F0(arg0 + 0x4C0, temp_a1, arg0);
        break;
    case 8:
        UpdateJtPipeLook(arg0 + 0xF50, temp_a1, arg0);
        break;
    }
}
