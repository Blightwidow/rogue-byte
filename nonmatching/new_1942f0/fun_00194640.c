#include "m2c_macros.h"

s32 func_00194640(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 8);
    switch (temp_v1) {                              /* irregular */
    case 8:
        if ((u32) (M2C_FIELD(arg0, s32 *, 0xC) - 9) < 2U) {
        case 12:
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}
