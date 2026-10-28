#include "m2c_macros.h"

M2C_UNK __as__4CRefRC4CRef(s32, void *);            /* extern */

s32 FFindBinding__8CSidebagiP4CRef(void *arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    void *var_v1;

    var_v1 = M2C_FIELD(arg0, void **, 8);
    if (var_v1 != NULL) {
loop_1:
        if (M2C_FIELD(var_v1, s32 *, 8) != arg1) {
            var_v1 = M2C_FIELD(var_v1, void **, 0x14);
            if (var_v1 == NULL) {
                goto block_7;
            }
            goto loop_1;
        }
        var_v0 = 1;
        if (arg2 != 0) {
            __as__4CRefRC4CRef(arg2, var_v1 + 0xC);
            return 1;
        }
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return var_v0;
    }
block_7:
    var_v0 = 0;
    return var_v0;
}
