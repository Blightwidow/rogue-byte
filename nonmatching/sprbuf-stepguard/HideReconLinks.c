#include "m2c_macros.h"

void HideReconLinks(void *arg0) {
    s32 var_s1;
    void **var_s0;
    void *temp_a1;
    void *temp_v0;

    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x30) > 0) {
        var_s0 = arg0 + 0x34;
        do {
            temp_a1 = M2C_FIELD(*var_s0, void **, 0x100);
            if (temp_a1 != NULL) {
                temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x48), temp_a1);
            }
            var_s1 += 1;
            var_s0 += 4;
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0x30));
    }
}
