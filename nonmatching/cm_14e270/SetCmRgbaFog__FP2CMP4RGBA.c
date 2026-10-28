#include "m2c_macros.h"

M2C_UNK FilterColorRgba8_1ed278(void *);            /* extern */
M2C_UNK RecalcCmFrustrum__FP2CM(void *);            /* extern */

void SetCmRgbaFog__FP2CMP4RGBA(void *arg0, void *arg1) {
    M2C_FIELD(arg0, M2C_UNK *, 0x24C) = M2C_UNALIGNED32(M2C_FIELD(arg1, M2C_UNK *, 0));
    RecalcCmFrustrum__FP2CM(arg0);
    FilterColorRgba8_1ed278(arg0 + 0x24C);
}
