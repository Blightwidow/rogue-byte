#include "m2c_macros.h"

s32 CFileLocation_Cb(void *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, s32 *, 8) == 2) {
        var_a1 = M2C_FIELD(arg0, s32 *, 4);
    }
    return var_a1;
}
