#include "m2c_macros.h"

M2C_UNK CloneXfm();                                 /* extern */

void CloneVolbtn__FP6VOLBTNT0(void *arg0) {
    CloneXfm();
    M2C_FIELD(arg0, void **, 0x130) = arg0;
}
