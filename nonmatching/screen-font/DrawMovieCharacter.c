#include "m2c_macros.h"

M2C_UNK DrawMovieBitmapCharacter(void *);           /* extern */
M2C_UNK DrawMovieShapeCharacter(void *);            /* extern */
M2C_UNK DrawMovieTextCharacter(void *);             /* extern */

void DrawMovieCharacter(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    switch (temp_v1) {
    case 3:
        DrawMovieTextCharacter(arg0);
        return;
    case 1:
        DrawMovieShapeCharacter(arg0);
        return;
    case 6:
    case 7:
        DrawMovieBitmapCharacter(arg0);
        /* fallthrough */
    default:
        return;
    }
}
