#include "m2c_macros.h"

s128 PosLoWorld(void *);                            /* extern */
M2C_UNK ProjectSoTransform(void *);                 /* extern */

void ProjectJtTransform(void *arg0) {
    s128 temp_v0;

    temp_v0 = PosLoWorld(M2C_FIELD(arg0, void **, 0x19A4));
    M2C_FIELD(arg0, s32 *, 0x1880) = 0;
    M2C_FIELD(arg0, s128 *, 0x18A0) = temp_v0;
    ProjectSoTransform(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x18D8) != 0) {
        M2C_FIELD(arg0, s32 *, 0x1880) = 0;
        return;
    }
    M2C_FIELD(arg0, s128 *, 0x1890) = PosLoWorld(arg0);
    M2C_FIELD(arg0, s128 *, 0x18B0) = PosLoWorld(M2C_FIELD(arg0, void **, 0x19A4));
    M2C_FIELD(arg0, s32 *, 0x1880) = 3;
}
