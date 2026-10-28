#include "m2c_macros.h"

M2C_UNK PlayRootSpriteLabelIndex(s32, s32, u16);    /* extern */

void PlayRootSpriteLabel(void *arg0, s32 arg1, u16 arg3) {
    s32 *var_v1;
    s32 var_a1;
    u16 temp_v0;
    u16 var_a3;
    void *temp_v1;

    var_a3 = arg3;
    if (M2C_FIELD(arg0, s32 *, 0x28) != 0) {
        var_a1 = 0;
        if (arg1 != 0x314) {
            temp_v0 = M2C_FIELD(arg0, u16 *, 0);
            if (temp_v0 != 0) {
                temp_v1 = M2C_FIELD(arg0, void **, 4);
                var_v1 = temp_v1 + 0x14;
                if (arg1 != M2C_FIELD(temp_v1, s32 *, 0x14)) {
                    var_a3 = temp_v0;
                    var_a1 = 1;
loop_5:
                    var_v1 += 0x18;
                    if (var_a1 < (s32) var_a3) {
                        if (arg1 != *var_v1) {
                            var_a1 += 1;
                            goto loop_5;
                        }
                    }
                }
            }
            var_a1 = (var_a1 >= (s32) temp_v0) ? 0 : var_a1;
        }
        PlayRootSpriteLabelIndex(var_a1, arg1, var_a3);
    }
}
