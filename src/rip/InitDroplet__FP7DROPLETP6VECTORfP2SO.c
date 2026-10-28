#include "m2c_macros.h"

M2C_UNK InitRip__FP3RIPP6VECTORfP2SO();             /* extern */
extern s128 D_002C1F40;

void InitDroplet__FP7DROPLETP6VECTORfP2SO(void *arg0) {
    InitRip__FP3RIPP6VECTORfP2SO();
    M2C_FIELD(arg0, f32 *, 0x18) = 5.0f;
    M2C_FIELD(arg0, s128 *, 0xA0) = (s128) D_002C1F40;
}
