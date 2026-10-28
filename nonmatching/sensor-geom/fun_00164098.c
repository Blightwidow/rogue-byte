#include "m2c_macros.h"

s32 func_00164098(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x54);
    if (temp_v1 != 1) {
        if (temp_v1 < 2) {
            if (temp_v1 != 0) {
                return -1;
            }
            return 0x612;
        }
        switch (temp_v1) {                          /* irregular */
        case 2:
            return 0x614;
        case 3:
            return 0x615;
        default:
            return -1;
        }
    } else {
        return 0x613;
    }
}
