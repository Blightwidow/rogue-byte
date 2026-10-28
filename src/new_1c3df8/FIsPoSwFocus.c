#include "m2c_macros.h"

s32 PpoSwFocus(M2C_UNK *);                          /* extern */
extern M2C_UNK B_003DD490;

s32 FIsPoSwFocus(s32 arg0) {
    return arg0 == PpoSwFocus(&B_003DD490);
}
