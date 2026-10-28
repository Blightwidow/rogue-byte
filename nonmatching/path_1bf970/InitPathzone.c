#include "m2c_macros.h"

M2C_UNK InitDl__FP2DLi(void *, M2C_UNK);            /* extern */
M2C_UNK InitXfm();                                  /* extern */

void InitPathzone(void *arg0) {
    InitXfm();
    M2C_FIELD(arg0, s32 *, 0x110) = -1;
    InitDl__FP2DLi(arg0 + 0x118, 0x60);
    M2C_FIELD(arg0, s32 *, 0x124) = -1;
}
