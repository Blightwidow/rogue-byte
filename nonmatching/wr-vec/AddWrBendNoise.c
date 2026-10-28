#include "m2c_macros.h"

M2C_UNK AddOnzOnze__FP3ONZffff(s32, f32, f32, f32, f32); /* extern */
s32 PwreGetWrBend__FP2WR4ENSK(M2C_UNK);             /* extern */

void AddWrBendNoise(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    AddOnzOnze__FP3ONZffff(PwreGetWrBend__FP2WR4ENSK(1) + 0x30, fparg0, fparg1, fparg2, fparg3);
}
