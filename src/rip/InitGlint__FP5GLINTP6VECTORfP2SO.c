#include "m2c_macros.h"

M2C_UNK InitRip__FP3RIPP6VECTORfP2SO();             /* extern */
extern s128 D_002C1F90;
extern s128 D_002C1FA0;

void InitGlint__FP5GLINTP6VECTORfP2SO(void *arg0) {
    InitRip__FP3RIPP6VECTORfP2SO();
    M2C_FIELD(arg0, f32 *, 0x18) = 0.5f;
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) D_002C1F90;
    M2C_FIELD(arg0, s128 *, 0x20) = (s128) D_002C1FA0;
}
