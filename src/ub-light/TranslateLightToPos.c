#include "m2c_macros.h"

M2C_UNK RebuildLight(s32);                          /* extern */
M2C_UNK TranslateXfmToPos();                        /* extern */

void TranslateLightToPos(s32 arg0) {
    TranslateXfmToPos();
    RebuildLight(arg0);
}
