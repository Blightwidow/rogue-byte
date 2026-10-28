#include "m2c_macros.h"

M2C_UNK func_001F4DA8(void *, s32, void *);         /* extern */
M2C_UNK func_001F5988();                            /* extern */

void NotifyVehicleXpEnded(void *arg0, s32 arg1) {
    s32 var_s2;
    void *var_s0;

    func_001F5988();
    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x190) > 0) {
        var_s0 = arg0 + 0x1A8;
        do {
            var_s2 += 1;
            func_001F4DA8(arg0, arg1, var_s0);
            var_s0 += 0x60;
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x190));
    }
}
