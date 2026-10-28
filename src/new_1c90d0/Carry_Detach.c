#include "m2c_macros.h"

M2C_UNK func_0012E460(void *);                      /* extern */

void Carry_Detach(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xA0) != 0) {
        func_0012E460(arg0 + 0x94);
        func_0012E460(arg0 + 0x98);
        func_0012E460(arg0 + 0x9C);
        M2C_FIELD(arg0, s32 *, 0xA0) = 0;
    }
}
