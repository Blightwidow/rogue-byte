#include "m2c_macros.h"

M2C_UNK LoadRotateMatrixRad(void *, s128);          /* extern */
extern s128 g_2a2dc0;

void SetSlotSoHeading(void *arg0, f32 fparg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_FIELD(arg0, f32 *, 0x1D8) = fparg0;
    LoadRotateMatrixRad(sp, g_2a2dc0);
    M2C_FIELD(arg0, s128 *, 0x1E0) = sp0;
    M2C_FIELD(arg0, s128 *, 0x200) = sp20;
    M2C_FIELD(arg0, s128 *, 0x1F0) = sp10;
}
