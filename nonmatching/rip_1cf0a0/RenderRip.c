#include "m2c_macros.h"

s32 FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(s128, void *, s128, s128, s128, s128); /* extern */
M2C_UNK RemoveRip(void *);                          /* extern */

void RenderRip(void *arg0) {
    char sp[0x400];
    s128 temp_a3;

    temp_a3 = M2C_FIELD(arg0, s128 *, 0x50);
    if (FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(M2C_FIELD(arg0, s128 *, 0x70), sp, temp_a3, M2C_FIELD(arg0, s128 *, 0x40), temp_a3, M2C_FIELD(arg0, s128 *, 0x60)) == 0) {
        RemoveRip(arg0);
    }
}
