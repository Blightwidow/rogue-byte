#include "m2c_macros.h"

s32 CMovieText_ChNext(void *);                      /* extern */
M2C_UNK CMovieText_Reset(M2C_UNK);                  /* extern */

void CMovieText_Trim(void *arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = arg1;
    CMovieText_Reset(0);
loop_1:
    if (CMovieText_ChNext(arg0) != 0) {
        var_s0 -= 1;
        if (var_s0 != 0) {
            goto loop_1;
        }
    }
    *M2C_FIELD(arg0, s8 **, 4) = 0;
}
