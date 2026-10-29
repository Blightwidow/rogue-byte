#include "m2c_macros.h"
extern "C" {

M2C_UNK GoalAnim_Update();                          /* extern */
s128 PosLoWorld(s32);                            /* extern */
void SetJumperTarget(s32, s128);              /* extern */

void func_00175258(void *arg0) {
    void *temp_s0;
    s128 vec;

    void *temp_v0;

    GoalAnim_Update();
    temp_v0 = M2C_FIELD(arg0, void **, 0x40);
    if ((temp_v0 == NULL) || (M2C_FIELD(temp_v0, s32 *, 8) == 0)) {
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x50) != 0) {
        temp_s0 = M2C_FIELD(arg0, void **, 0x40);
        vec = PosLoWorld(M2C_FIELD(arg0, s32 *, 0x38));
        SetJumperTarget(M2C_FIELD(temp_s0, s32 *, 8), vec);
    }
}
}
