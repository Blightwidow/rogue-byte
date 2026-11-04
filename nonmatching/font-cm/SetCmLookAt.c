#include "m2c_macros.h"

M2C_UNK DecomposeSphere(M2C_UNK, f32 *, f32 *, M2C_UNK); /* extern */
M2C_UNK LoadRotateMatrixPanTilt(void *, f32, f32);  /* extern */
M2C_UNK UpdateCmMat4(void *);                       /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s32, s128);        /* extern */

void SetCmLookAt(void *arg0, f32 fparg0, f32 fparg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    f32 sp30;
    f32 sp34;
    s128 sp40;
    void *temp_s0;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */);
    sp40 = M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    temp_s0 = arg0 + 0x60;
    DecomposeSphere(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), &sp30, &sp34, 0);
    LoadRotateMatrixPanTilt(sp, sp30 + fparg0, sp34 + fparg1);
    __as__6VECTORG9VU_VECTOR(arg0 + 0x90, sp40);
    M2C_FIELD(arg0, s128 *, 0x60) = sp0;
    M2C_FIELD(temp_s0, s128 *, 0x10) = sp10;
    M2C_FIELD(temp_s0, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_s0, s128 *, 0x20) = sp20;
    M2C_FIELD(temp_s0, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_s0, s32 *, 0xC) = 0;
    M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
    UpdateCmMat4(arg0);
}
