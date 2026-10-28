#include "m2c_macros.h"

M2C_UNK ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(M2C_UNK, M2C_UNK *, s32 *, f32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK FixStepAngularVelocity__FP4STEP(void *);    /* extern */
M2C_UNK SetStepRadTargetDir(void *, s128);          /* extern */
extern M2C_UNK D_002BF4E0;

void ChooseJtSmashTarget__FP2JT(void *arg0) {
    M2C_UNK sp0;
    s32 sp10;

    ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(4, &D_002BF4E0, &sp10, M2C_FIELD(arg0, f32 *, 0x1A8), 0x3E800000, 0x4049999A);
    M2C_FIELD(arg0, s32 *, 0x18C0) = sp10;
    if (sp10 != 0) {
        SetStepRadTargetDir(arg0, sp0);
        FixStepAngularVelocity__FP4STEP(arg0);
    }
}
