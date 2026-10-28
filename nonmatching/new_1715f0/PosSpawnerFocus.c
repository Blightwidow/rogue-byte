#include "m2c_macros.h"

s128 PosLoWorld(s32);                               /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;

s128 PosSpawnerFocus(void) {
    if (PpoSwFocusBase(&B_003DD490) == 0) {
        return M2C_FIELD(&B_002DDF40, s128 *, 0x90);
    }
    return PosLoWorld(PpoSwFocusBase(&B_003DD490));
}
