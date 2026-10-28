#include "m2c_macros.h"

s32 GetJtPower(void *);                             /* extern */
M2C_UNK SetJtHealth(void *, s32);                   /* extern */
M2C_UNK SetJtPower(void *, s32);                    /* extern */
M2C_UNK func_001C4228();                            /* extern */

void bevy_player_p18_gadget_144268(void *arg0, s32 arg1, s32 arg2) {
    func_001C4228();
    SetJtHealth(arg0, *M2C_FIELD(arg0, s32 **, 0xE00) + arg1);
    SetJtPower(arg0, GetJtPower(arg0) + arg2);
}
