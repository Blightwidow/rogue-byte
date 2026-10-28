#include "m2c_macros.h"

s32 PchzStringFromId(M2C_UNK *, M2C_UNK);           /* extern */
M2C_UNK strcpy(s8 *, s32);                          /* extern */
extern s32 B_003DA180;
extern M2C_UNK B_003DD490;

void func_001DCA30(s8 *arg0) {
    M2C_UNK var_a1;

    if (B_003DA180 != 0) {
        if (B_003DA180 <= 0) {
            var_a1 = 0xDE;
            if (B_003DA180 != -1) {
                *arg0 = 0;
                return;
            }
            goto block_8;
        }
        var_a1 = 0xE0;
        if (B_003DA180 != 1) {
            *arg0 = 0;
            return;
        }
        goto block_8;
    }
    var_a1 = 0xDF;
block_8:
    strcpy(arg0, PchzStringFromId(&B_003DD490, var_a1));
}
