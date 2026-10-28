#include "m2c_macros.h"

M2C_UNK CSo_Clone();                                  /* extern */
M2C_UNK InferExpl(s32, s32);                        /* extern */

void LoadBombFromBrx(s32 arg0) {
    CSo_Clone();
    InferExpl(arg0, arg0);
}
