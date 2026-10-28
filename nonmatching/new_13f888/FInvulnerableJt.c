#include "m2c_macros.h"

s32 FIsPoSwFocusBase(s32);                          /* extern */
s32 ZapFInvulnerable(void *, s32);                  /* extern */
extern s32 B_003D4A54;

s32 FInvulnerableJt(void *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 1;
    if (M2C_FIELD(arg0, s32 *, 0xF20) != 1) {
        if (M2C_FIELD(arg0, s32 *, 0x2DC) == 0x15) {
            return 1;
        }
        if ((B_003D4A54 == 0) || (var_v0 = 1, (FIsPoSwFocusBase(B_003D4A54) == 0))) {
            var_v0 = ZapFInvulnerable(arg0 + 0xDF0, arg1);
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
