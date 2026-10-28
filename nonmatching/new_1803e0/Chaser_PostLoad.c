#include "m2c_macros.h"

s32 PcrvNew(M2C_UNK, M2C_UNK);                      /* extern */
M2C_UNK SetXfKind(void *, s32, M2C_UNK);            /* extern */
M2C_UNK func_0017F138();                            /* extern */
M2C_UNK func_0017F408(void *, M2C_UNK, void *);     /* extern */

void Chaser_PostLoad(void *arg0) {
    s32 temp_a1;
    s32 temp_a1_2;

    func_0017F138();
    temp_a1 = M2C_FIELD(arg0, s32 *, 0x58);
    M2C_FIELD(arg0, s32 *, 0x1D8) = PcrvNew(0x2C9, 0x10);
    if (temp_a1 != 0) {
        SetXfKind(arg0, temp_a1, 2);
    }
    temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x5C);
    if (temp_a1_2 != 0) {
        SetXfKind(arg0, temp_a1_2, 2);
    }
    func_0017F408(arg0, 5, arg0 + 0x220);
}
