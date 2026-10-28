#include "m2c_macros.h"

M2C_UNK TranslateStepToPos();                       /* extern */

void JT_TranslateToPos(void *arg0) {
    TranslateStepToPos();
    M2C_FIELD(arg0, s32 *, 0x9E4) = 0;
}
