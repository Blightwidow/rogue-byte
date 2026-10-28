#include "m2c_macros.h"

M2C_UNK sprintf(s32, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */

void BuildSlotFilePath(s32 arg0, s32 arg1, s32 arg2) {
    sprintf(arg2, "/%s/%s%d", "BASCUS-97316YAOTWTD!", "save\0\0\0\0/%s/%s");
}
