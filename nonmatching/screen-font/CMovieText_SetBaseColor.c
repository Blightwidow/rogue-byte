#include "m2c_macros.h"

M2C_UNK CMovieText_UpdateFont(void *);              /* extern */

void CMovieText_SetBaseColor(void *arg0, void *arg1) {
    M2C_FIELD(arg0, M2C_UNK *, 0x18) = M2C_UNALIGNED32(M2C_FIELD(arg1, M2C_UNK *, 0));
    M2C_FIELD(arg0, M2C_UNK *, 0x14) = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x18));
    CMovieText_UpdateFont(arg0);
}
