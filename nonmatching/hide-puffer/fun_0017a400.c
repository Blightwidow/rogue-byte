#include "m2c_macros.h"

M2C_UNK GoalAnim_Update();                          /* extern */
M2C_UNK func_00209840(s32, void *);                 /* extern */

void func_0017A400(void *arg0) {
    GoalAnim_Update();
    if ((M2C_FIELD(arg0, s32 *, 0x6C) != 0) && (M2C_FIELD(arg0, s32 *, 0x30) == 0) && (M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 8), s32 *, 0x10) >= 2)) {
        func_00209840(M2C_FIELD(arg0, s32 *, 0x10) + 0xFD0, arg0 + 0x70);
    }
}
