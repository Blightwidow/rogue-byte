#include "m2c_macros.h"

M2C_UNK CloneXfm();                                 /* extern */

void CloneSuv(void *arg0) {
    s32 *temp_v1;

    CloneXfm();
    temp_v1 = M2C_FIELD(arg0, s32 **, 0xE4);
    *temp_v1 += 1;
}
