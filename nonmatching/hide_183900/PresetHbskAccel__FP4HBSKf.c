#include "m2c_macros.h"

M2C_UNK AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(void *, void *, M2C_UNK *, s128); /* extern */
M2C_UNK AddSoGravityAcceleration();                 /* extern */
s32 PmatLoWorld(void *);                            /* extern */
M2C_UNK TiltMatUpright__FP7MATRIX3N20(s32, M2C_UNK, void *); /* extern */
extern M2C_UNK D_002BE8D0;
extern s128 g_2a2dd0;

void PresetHbskAccel__FP4HBSKf(void *arg0) {
    char sp[0x400];
    AddSoGravityAcceleration();
    if ((M2C_FIELD(arg0, s32 *, 0x18C) != 0) && (M2C_FIELD(arg0, s32 *, 0x17C) == 0)) {
        TiltMatUpright__FP7MATRIX3N20(PmatLoWorld(arg0), 0, sp);
        AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(arg0, sp, &D_002BE8D0, g_2a2dd0);
    }
}
