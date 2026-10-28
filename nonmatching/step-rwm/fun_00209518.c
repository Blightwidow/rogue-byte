#include "m2c_macros.h"

void *func_00209518(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_v1 != 1) {
        if (temp_v1 < 2) {
            if (temp_v1 != 0) {
                return NULL;
            }
            return M2C_FIELD(arg0, void **, 8);
        }
        switch (temp_v1) {                          /* irregular */
        case 2:
            return M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0x38);
        case 3:
            return M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0x24);
        default:
            return NULL;
        }
    } else {
        return M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0x30);
    }
}
