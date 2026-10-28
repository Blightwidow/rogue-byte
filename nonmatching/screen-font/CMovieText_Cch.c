#include "m2c_macros.h"

s32 CMovieText_ChNext(s32);                         /* extern */
M2C_UNK CMovieText_Reset(M2C_UNK);                  /* extern */

s32 CMovieText_Cch(s32 arg0) {
    s32 var_s1;

    var_s1 = 0;
    CMovieText_Reset(0);
loop_1:
    if (CMovieText_ChNext(arg0) != 0) {
        var_s1 += 1;
        goto loop_1;
    }
    return var_s1;
}
