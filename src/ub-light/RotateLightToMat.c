#include "m2c_macros.h"

M2C_UNK RebuildLight(s32);                          /* extern */
M2C_UNK RotateXfmToMat();                           /* extern */

void RotateLightToMat(s32 arg0) {
    RotateXfmToMat();
    RebuildLight(arg0);
}
