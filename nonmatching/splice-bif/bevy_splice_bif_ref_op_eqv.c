#include "m2c_macros.h"

void *bevy_splice_bif_ref_op_eqv(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 var_a3;
    u32 temp_v1;

    var_a3 = arg3;
    temp_v1 = M2C_FIELD(arg2, u32 *, 0);
    if (temp_v1 != M2C_FIELD(arg2, s32 *, 8)) {
        var_a3 = 0;
    } else {
        switch (temp_v1) {
        case 21:
        case 23:
        case 24:
        case 25:
        case 31:
        case 32:
        case 33:
        case 34:
            var_a3 = M2C_FIELD(arg2, s32 *, 4) == M2C_FIELD((arg2 + 8), s32 *, 4);
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 36:
            var_a3 = 1;
            break;
        }
    }
    M2C_FIELD(arg0, s32 *, 4) = var_a3;
    M2C_FIELD(arg0, s32 *, 0) = 0x17;
    return arg0;
}
