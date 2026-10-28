#include "m2c_macros.h"

M2C_UNK LoadOptionFromBrx(s32, void *, s32, s32);   /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
extern M2C_UNK D_002AC880;

void LoadOptionsFromBrx__FPvP18CBinaryInputStream(s32 arg0, s32 arg1) {
    s32 temp_v0;
    void *temp_a1;

loop_2:
    temp_v0 = S16Read__18CBinaryInputStream(arg1);
    temp_a1 = (temp_v0 * 0x28) + &D_002AC880;
    if (temp_v0 >= 0) {
        LoadOptionFromBrx(arg0, temp_a1, M2C_FIELD(temp_a1, s32 *, 4) & 0x2580, arg1);
        goto loop_2;
    }
}
