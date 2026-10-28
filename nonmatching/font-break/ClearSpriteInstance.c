#include "m2c_macros.h"

M2C_UNK InitDepthSlot(void *);                      /* extern */
M2C_UNK func_002158C0(s32, void *);                 /* extern */

void ClearSpriteInstance(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a1_2;
    s32 var_s1;
    void *temp_a1;
    void *var_s0;

    temp_a1 = (arg1 * 0x18) + M2C_FIELD(arg0, s32 *, 8);
    temp_a1_2 = M2C_FIELD(temp_a1, s32 *, 0);
    var_s0 = M2C_FIELD(temp_a1, void **, 4);
    if (temp_a1_2 > 0) {
        var_s1 = temp_a1_2;
        do {
            temp_a0 = M2C_FIELD(var_s0, s32 *, 0x30);
            if (temp_a0 != 0) {
                func_002158C0(temp_a0, var_s0);
            } else {
                InitDepthSlot(var_s0);
            }
            var_s0 += 0x70;
            var_s1 -= 1;
        } while (var_s1 != 0);
    }
}
