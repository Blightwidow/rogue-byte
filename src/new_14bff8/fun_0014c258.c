#include "m2c_macros.h"

M2C_UNK EquipJtGadget(s32, s32, M2C_UNK);           /* extern */
s32 IslotJtGadget(s32, M2C_UNK);                    /* extern */
M2C_UNK SetGadgetAcquired(M2C_UNK, M2C_UNK);        /* extern */
extern s32 g_2e1e40;

void func_0014C258(void) {
    s32 temp_v0;

    if (g_2e1e40 != 0) {
        temp_v0 = IslotJtGadget(g_2e1e40, 0x1F);
        if (temp_v0 != -1) {
            EquipJtGadget(g_2e1e40, temp_v0, -1);
        }
        SetGadgetAcquired(0x1F, 0);
    }
}
