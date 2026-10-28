#include "m2c_macros.h"

M2C_UNK FindCrvcClosestPointFromU();                /* extern */
M2C_UNK FindCrvlClosestPointFromU();                /* extern */

void FindCrvClosestPointFromU(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xE0) == 0) {
        FindCrvlClosestPointFromU();
        return;
    }
    FindCrvcClosestPointFromU();
}
