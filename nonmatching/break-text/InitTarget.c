#include "m2c_macros.h"

M2C_UNK InitXfm();                                  /* extern */
M2C_UNK func_001A6CA8(void *, M2C_UNK);             /* extern */

void InitTarget(void *arg0) {
    InitXfm();
    func_001A6CA8(arg0, 3);
    M2C_FIELD(arg0, s32 *, 0xE8) = 0x17E;
    M2C_FIELD(arg0, s32 *, 0xF4) = -1;
    M2C_FIELD(arg0, f32 *, 0xEC) = 25.0f;
}
