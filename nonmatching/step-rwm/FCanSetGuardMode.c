#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 FIsGuardInSgs(s32, M2C_UNK);                    /* extern */
s32 FIsGuardSpecialClass(s32);                      /* extern */
void *func_00205458(s32, M2C_UNK);                  /* extern */

s32 FCanSetGuardMode(s32 arg0, s32 arg1) {
    M2C_UNK var_a1;
    s32 var_v0;
    u32 var_v1;
    void *temp_v0;

    if (arg1 == -1) {
        goto block_1;
    }
    var_v0 = 0;
    if (FIsGuardInSgs(arg0, 7) == 0) {
        temp_v0 = func_00205458(arg0, 0xA9);
        var_v1 = arg1 - 8;
        if (temp_v0 != NULL) {
            var_v0 = 0;
            if (M2C_FIELD(temp_v0, s32 *, 0x4C) == 0) {
                var_v1 = arg1 - 8;
                goto block_6;
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        }
block_6:
        switch (var_v1) {
        case 0:
        case 5:
        case 6:
block_1:
            return 1;
        case 13:
            var_a1 = 0x3E;
block_17:
            var_v0 = 0;
            if (FIsBasicDerivedFrom(arg0, var_a1) == 0) {
                if (FIsBasicDerivedFrom(arg0, 0x42) != 0) {
                    return 0;
                }
                return FIsBasicDerivedFrom(arg0, 0x43) == 0;
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        case 26:
        case 29:
            return FIsGuardSpecialClass(arg0) == 0;
        case 3:
            var_v0 = 0;
            if (FIsBasicDerivedFrom(arg0, 0x3B) == 0) {
                var_v0 = 0;
                if (FIsBasicDerivedFrom(arg0, 0x3D) == 0) {
                    var_v0 = 0;
                    if (FIsBasicDerivedFrom(arg0, 0x40) == 0) {
                        var_v0 = 0;
                        if (FIsBasicDerivedFrom(arg0, 0x3E) == 0) {
                            var_v0 = 0;
                            if (FIsBasicDerivedFrom(arg0, 0x41) == 0) {
                                var_v0 = 0;
                                if (FIsBasicDerivedFrom(arg0, 0x3F) == 0) {
                                    var_a1 = 0x3C;
                                    goto block_17;
                                }
                            }
                        }
                    }
                }
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        default:
            var_v0 = 0;
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        }
    } else {
        return var_v0;
    }
}
