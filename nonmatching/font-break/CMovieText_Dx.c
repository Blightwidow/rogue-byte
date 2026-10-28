#include "m2c_macros.h"

s32 CMovieText_ChNext(void *);                      /* extern */
M2C_UNK CMovieText_Reset(M2C_UNK);                  /* extern */
f32 DxFromFontCh(s32, s32);                         /* extern */

f32 CMovieText_Dx(void *arg0) {
    f32 var_f20;
    s32 temp_v0;

    var_f20 = 0.0f;
    CMovieText_Reset(0);
loop_2:
    temp_v0 = CMovieText_ChNext(arg0);
    if (temp_v0 != 0) {
        var_f20 += DxFromFontCh(M2C_FIELD(arg0, s32 *, 8), temp_v0) * M2C_FIELD(arg0, f32 *, 0x88);
        goto loop_2;
    }
    return var_f20;
}
