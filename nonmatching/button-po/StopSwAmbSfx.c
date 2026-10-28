#include "m2c_macros.h"

M2C_UNK StopAmb(void *, M2C_UNK);                   /* extern */
M2C_UNK VirtualRefPtr_Assign(void **, M2C_UNK);     /* extern */

void StopSwAmbSfx(s32 arg0, s32 arg1, s32 arg2, void **arg3) {
    void *temp_a0;

    temp_a0 = *arg3;
    if ((temp_a0 != NULL) && ((arg1 == -1) || (M2C_FIELD(temp_a0, s32 *, 0x60) == arg1))) {
        StopAmb(temp_a0, 0);
        VirtualRefPtr_Assign(arg3, 0);
    }
}
