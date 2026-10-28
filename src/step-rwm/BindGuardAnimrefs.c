#include "m2c_macros.h"

M2C_UNK BindAnimref(void *, void *);                /* extern */
M2C_UNK BindAnimrefArray(void *, void *);           /* extern */

void BindGuardAnimrefs(void *arg0) {
    s32 var_s2;
    void *var_s1;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x4C0) > 0) {
        var_s1 = arg0 + 0x4D0;
        do {
            BindAnimref(var_s1, arg0);
            var_s2 += 1;
            var_s1 += 0x20;
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x4C0));
    }
    BindAnimrefArray(arg0, arg0 + 0xC10);
    BindAnimrefArray(arg0, arg0 + 0x8D0);
    BindAnimrefArray(arg0, arg0 + 0xA70);
}
