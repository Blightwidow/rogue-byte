#include "m2c_macros.h"

s32 FAbsorbSoWkr();                                 /* extern */
M2C_UNK SetLootState(void *, M2C_UNK);              /* extern */

s32 FAbsorbLootWkr(void *arg0) {
    if ((FAbsorbSoWkr() == 0) || (M2C_FIELD(arg0, s32 *, 0x184) != 5)) {
        return 0;
    }
    SetLootState(arg0, 0);
    return 1;
}
