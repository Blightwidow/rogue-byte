#include "m2c_macros.h"

M2C_UNK RebuildLight(void *);                       /* extern */
M2C_UNK func_001A3B38();                            /* extern */

void SetLightKind(void *arg0, s32 arg1) {
    func_001A3B38();
    M2C_FIELD(arg0, s32 *, 0xE0) = arg1;
    RebuildLight(arg0);
}
