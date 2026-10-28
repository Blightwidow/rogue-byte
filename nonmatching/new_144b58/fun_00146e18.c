#include "m2c_macros.h"

M2C_UNK func_001EEFC0(void *);                      /* extern */
M2C_UNK func_001EF038();                            /* extern */
extern f32 g_2dded0;

void func_00146E18(void *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x30);
    if (arg1 != temp_v1) {
        if ((temp_v1 < 5) && (temp_v1 >= 2)) {
            func_001EF038();
        }
        M2C_FIELD(arg0, s32 *, 0x30) = arg1;
        M2C_FIELD(arg0, f32 *, 0x34) = (f32) g_2dded0;
        if ((arg1 < 5) && (arg1 >= 2)) {
            func_001EEFC0(arg0);
        }
    }
}
