#include "m2c_macros.h"

s128 PosLoWorld(s32);                               /* extern */

void ProjectGlintTransform(void *arg0) {
    M2C_FIELD(arg0, s128 *, 0x80) = (s128) M2C_FIELD(arg0, s128 *, 0x70);
    M2C_FIELD(arg0, s128 *, 0x70) = PosLoWorld(M2C_FIELD(arg0, s32 *, 0xF0));
}
