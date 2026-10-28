#include "m2c_macros.h"

s32 FIgnoreSoIntersection(void *arg0, void *arg1) {
    s32 var_v0;
    void *temp_v1;
    void *temp_v1_2;

    if ((!(M2C_FIELD(arg0, s64 *, 0x148) & 0x04000000) && (temp_v1 = M2C_FIELD(arg0, void **, 0xC), (M2C_FIELD(temp_v1, s32 (**)(void *, void *), 0x1F4)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x1F0), arg0) == 0))) || (temp_v1_2 = M2C_FIELD(arg1, void **, 0xC), var_v0 = 1, (M2C_FIELD(temp_v1_2, s32 (**)(void *), 0x1F4)(arg1 + M2C_FIELD(temp_v1_2, s16 *, 0x1F0)) == 0))) {
        var_v0 = 0;
    }
    return var_v0;
}
