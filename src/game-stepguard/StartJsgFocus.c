#include "m2c_macros.h"

s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK StartJsg(s32, s32);                         /* extern */
extern M2C_UNK B_003DD490;

void StartJsgFocus(s32 arg0) {
    StartJsg(arg0, PpoSwFocusBase(&B_003DD490));
}
