#include "m2c_macros.h"

f32 SMinCrv(void *arg0) {
    return *M2C_FIELD(arg0, f32 **, 0xF0);
}
