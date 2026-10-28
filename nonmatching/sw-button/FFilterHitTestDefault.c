#include "m2c_macros.h"

s32 FFilterOxaBasic();                              /* extern */

s32 FFilterHitTestDefault(void *arg1) {
    s32 var_v0;
    void *temp_a1;
    void *temp_v1;

    var_v0 = 0;
    if (FFilterOxaBasic() != 0) {
        temp_a1 = M2C_FIELD(arg1, void **, 4);
        temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
        var_v0 = M2C_FIELD(temp_v1, s32 (**)(void *, void *), 0x1F4)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x1F0), temp_a1);
    }
    return var_v0;
}
