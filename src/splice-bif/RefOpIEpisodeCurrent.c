#include "m2c_macros.h"

s32 IEpisodeCurrent();                              /* extern */

void *RefOpIEpisodeCurrent(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = IEpisodeCurrent();
    M2C_FIELD(arg0, s32 *, 0) = 0x15;
    return arg0;
}
