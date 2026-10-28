#include "m2c_macros.h"

void AddVifFlush__4VIFS(void *arg0) {
    s32 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_v1 + 4);
    *temp_v1 = 0x11000000;
}
