#include "m2c_macros.h"

s32 CFileLocation_Cb(void *);                       /* extern */
M2C_UNK Clear__13CFileLocation(void *, s32);        /* extern */

s32 FUN_0018c1e8(void *arg0) {
    char sp[0x400];
    s32 var_v0;
    s32 var_v0_2;

    Clear__13CFileLocation(sp, 2);
    if (arg0 != NULL) {
        var_v0_2 = M2C_FIELD(arg0, s32 *, 4) != M2C_FIELD(arg0, s32 *, 0x3C);
    } else {
        var_v0_2 = 0;
    }
    var_v0 = 0;
    if (var_v0_2 != 0) {
        var_v0 = CFileLocation_Cb(sp);
    }
    return var_v0;
}
