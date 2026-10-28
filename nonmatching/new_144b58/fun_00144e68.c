#include "m2c_macros.h"

M2C_UNK GoalGotoPos_SetPos(void *, s128);           /* extern */
M2C_UNK func_001EEF70();                            /* extern */
void *func_00205438(s32, M2C_UNK);                  /* extern */

void func_00144E68(void *arg0) {
    void *temp_v0;
    void *temp_v0_2;

    func_001EEF70();
    temp_v0 = func_00205438(M2C_FIELD(arg0, s32 *, 0x10), 0xA8);
    M2C_FIELD(temp_v0, s32 *, 0x40) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(temp_v0, f32 *, 0x64) = (f32) M2C_FIELD(arg0, f32 *, 0x34);
    M2C_FIELD(temp_v0, s32 *, 0xCC) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(temp_v0, f32 *, 0xD0) = (f32) M2C_FIELD(arg0, f32 *, 0x3C);
    GoalGotoPos_SetPos(arg0, M2C_FIELD(arg0, s128 *, 0x40));
    temp_v0_2 = M2C_FIELD(temp_v0, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x44)(temp_v0 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
}
