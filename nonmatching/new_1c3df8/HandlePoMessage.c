#include "m2c_macros.h"

M2C_UNK HandleLoMessage();                          /* extern */
M2C_UNK StopAmb(s32, M2C_UNK);                      /* extern */
M2C_UNK VirtualRefPtr_Assign(s32, M2C_UNK);         /* extern */

void HandlePoMessage(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_s0;

    HandleLoMessage();
    if (arg1 == 5) {
        temp_s0 = arg0 + 0x174;
        if (temp_s0 != 0) {
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x174);
            if (temp_a0 != 0) {
                StopAmb(temp_a0, 0);
                VirtualRefPtr_Assign(temp_s0, 0);
            }
        }
    }
}
