#include "m2c_macros.h"

M2C_UNK GoalFollowCrv_Init();                       /* extern */
extern f32 g_2be694;

void GoalFollowCrvAnim_Init(void *arg0) {
    GoalFollowCrv_Init();
    M2C_FIELD(arg0, s32 *, 0xC0) = 9;
    M2C_FIELD(arg0, f32 *, 0xE0) = (f32) g_2be694;
    M2C_FIELD(arg0, f32 *, 0xC4) = 1.0f;
}
