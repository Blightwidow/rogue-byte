#include "m2c_macros.h"

M2C_UNK InitRip__FP3RIPP6VECTORfP2SO();             /* extern */
extern s128 D_002BBB50;

void InitMatch__FP5MATCHP6VECTORfP2SO(void *arg0, f32 fparg0) {
    InitRip__FP3RIPP6VECTORfP2SO();
    M2C_FIELD(arg0, f32 *, 0x20) = fparg0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) D_002BBB50;
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (1.0f - fparg0);
}
