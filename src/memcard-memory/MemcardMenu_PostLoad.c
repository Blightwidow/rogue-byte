#include "m2c_macros.h"

M2C_UNK MemcardMenu_SetState(void *, s32);          /* extern */
M2C_UNK Menu_PostLoad();                            /* extern */

void MemcardMenu_PostLoad(void *arg0) {
    s32 temp_a1;
    void *temp_a0;

    Menu_PostLoad();
    temp_a0 = M2C_FIELD(arg0, void **, 0x24);
    if (temp_a0 != NULL) {
        M2C_FIELD(temp_a0, s32 *, 0xB0) = 1;
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x40);
        if (temp_a1 != -1) {
            MemcardMenu_SetState(arg0, temp_a1);
        }
    }
}
