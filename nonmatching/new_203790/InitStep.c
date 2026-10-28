#include "m2c_macros.h"

M2C_UNK GoalStack_Init(void *, void *);             /* extern */
M2C_UNK InitPo();                                   /* extern */
M2C_UNK SetStepRadTarget(void *, M2C_UNK);          /* extern */
M2C_UNK SetStepSpinRatio__FP4STEPf(void *, M2C_UNK); /* extern */

void InitStep(void *arg0) {
    InitPo();
    M2C_FIELD(arg0, s32 *, 0x264) = -1;
    M2C_FIELD(arg0, f32 *, 0x260) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x200) = 1.0f;
    SetStepSpinRatio__FP4STEPf(arg0, 0x3F800000);
    SetStepRadTarget(arg0, 0);
    M2C_FIELD(arg0, f32 *, 0x220) = 30.0f;
    M2C_FIELD(arg0, f32 *, 0x214) = -50.0f;
    GoalStack_Init(arg0 + 0x26C, arg0);
}
