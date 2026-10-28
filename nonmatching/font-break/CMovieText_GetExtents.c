#include "m2c_macros.h"

s32 CMovieText_ClineWrap();                         /* extern */
f32 CMovieText_DxMaxLine(void *);                   /* extern */

void CMovieText_GetExtents(void *arg0, f32 *arg1, f32 *arg2) {
    f32 temp_f2;
    s32 temp_s1;

    temp_s1 = CMovieText_ClineWrap();
    temp_f2 = CMovieText_DxMaxLine(arg0);
    if (arg1 != NULL) {
        *arg1 = temp_f2;
    }
    if (arg2 != NULL) {
        *arg2 = (f32) temp_s1 * M2C_FIELD(arg0, f32 *, 0x84);
    }
}
