#include "m2c_macros.h"

M2C_UNK CloneAnimref(void *);                       /* extern */
M2C_UNK CloneAnimrefArray(void *, void *);          /* extern */

void CloneGuardAnimrefs(void *arg0) {
    s32 var_s2;
    void *var_s0;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x4C0) > 0) {
        var_s0 = arg0 + 0x4D0;
        do {
            var_s2 += 1;
            CloneAnimref(var_s0);
            var_s0 += 0x20;
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x4C0));
    }
    CloneAnimrefArray(arg0, arg0 + 0xC10);
    CloneAnimrefArray(arg0, arg0 + 0x8D0);
    CloneAnimrefArray(arg0, arg0 + 0xA70);
}
