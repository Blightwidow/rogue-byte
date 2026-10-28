#include "m2c_macros.h"

M2C_UNK UpdateRopeSimChain(void *, void *);         /* extern */
M2C_UNK UpdateRopeSimFree(void *, void *);          /* extern */
M2C_UNK func_001A5E80(void *, void *);              /* extern */

void func_001E6340(void *arg0) {
    s32 temp_v1;
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x17C);
    if (temp_a0 != NULL) {
        temp_v1 = M2C_FIELD(temp_a0, s32 *, 0x4C);
        if (temp_v1 >= 3) {
            if (temp_v1 == 3) {
                goto block_8;
            }
        } else if (temp_v1 <= 0) {
            if (temp_v1 != 0) {
                return;
            }
block_8:
            UpdateRopeSimFree(M2C_FIELD(arg0, void **, 0x17C), arg0);
        } else {
            UpdateRopeSimChain(temp_a0, arg0);
        }
    } else {
        func_001A5E80(arg0, arg0);
    }
}
