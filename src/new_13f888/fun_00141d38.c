#include "m2c_macros.h"

M2C_UNK SetJmpState(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SpendJtGadgetPower(void *, M2C_UNK);        /* extern */
M2C_UNK StartAttach(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_00141D38(void *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 14:
    case 21:
    case 23:
        M2C_FIELD(arg0, s32 *, 0x9BC) = arg1;
        StartAttach(arg0 + 0x4C0, 0xB, 0, 0);
        return;
    case 12:
        SpendJtGadgetPower(arg0, 0xC);
        SetJmpState(arg0 + 0x2C0, 0x11, 0, 0);
        return;
    }
}
