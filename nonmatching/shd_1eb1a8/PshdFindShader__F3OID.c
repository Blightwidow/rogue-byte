#include "m2c_macros.h"

extern s32 B_003DCFE8;
extern s32 *B_003DCFEC;

s32 *PshdFindShader__F3OID(s32 arg0) {
    s32 *var_a1;
    s32 *var_v1;
    s32 var_a2;

    if (arg0 == -1) {
        return NULL;
    }
    var_a2 = 0;
    if (B_003DCFE8 > 0) {
        var_a1 = B_003DCFEC;
        var_v1 = var_a1;
loop_5:
        var_a2 += 1;
        if (*var_v1 != arg0) {
            var_v1 += 0x2C;
            var_a1 += 0x2C;
            if (var_a2 >= B_003DCFE8) {
                /* Duplicate return node #7. Try simplifying control flow for better match */
                return NULL;
            }
            goto loop_5;
        }
        return var_a1;
    }
    return NULL;
}
