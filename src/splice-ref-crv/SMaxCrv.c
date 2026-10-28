#include "m2c_macros.h"

f32 SMaxCrv(void *arg0) {
    return M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0xE8) * 4) + M2C_FIELD(arg0, s32 *, 0xF0)), f32 *, -4);
}
