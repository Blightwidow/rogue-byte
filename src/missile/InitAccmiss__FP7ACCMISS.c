#include "m2c_macros.h"

M2C_UNK InitXfm();                                  /* extern */
extern s128 g_2a2da0;
extern s128 g_2a2dc0;

void InitAccmiss__FP7ACCMISS(void *arg0) {
    InitXfm();
    M2C_FIELD(arg0, s128 *, 0x100) = (s128) g_2a2da0;
    M2C_FIELD(arg0, s128 *, 0x110) = (s128) g_2a2dc0;
}
