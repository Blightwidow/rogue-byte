#include "m2c_macros.h"

f32 GLimitLm__FP2LMf(s32);                          /* extern */
extern M2C_UNK B_003DD490;

void ChangeSuck__FfP10DIFFICULTY(void *arg0) {
    if (M2C_FIELD(&B_003DD490, void **, 0x3B0C) != NULL) {
        *M2C_FIELD(M2C_FIELD(&B_003DD490, void **, 0x3B0C), f32 **, 0xA8) = GLimitLm__FP2LMf(M2C_FIELD(arg0, s32 *, 0x14));
    }
}
