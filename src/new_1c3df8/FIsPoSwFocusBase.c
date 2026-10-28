#include "m2c_macros.h"

s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
extern M2C_UNK B_003DD490;

s32 FIsPoSwFocusBase(s32 arg0) {
    return arg0 == PpoSwFocusBase(&B_003DD490);
}
