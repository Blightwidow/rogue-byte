#include "m2c_macros.h"
extern "C" {

M2C_UNK BuildRotateVectorsMatrix(void *, s128, M2C_UNK); /* extern */
M2C_UNK ConvertXfPos(s32, s32, s128);               /* extern */
s128 DecomposeRotateMatrixEuler(void *);            /* extern */

void func_0020ACC0(void *arg0) {
    char sp[0x30];
    void *temp_s1;

    ConvertXfPos(M2C_FIELD(arg0, s32 *, 0xF10), M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0xF08), void **, 0xA0), s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0xF20));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($a2) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
    BuildRotateVectorsMatrix(sp, M2C_FIELD(M2C_FIELD(arg0, void **, 0xF08), s128 *, 0x90), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */));
    temp_s1 = M2C_FIELD(arg0, void **, 0xF0C);
    M2C_FIELD(temp_s1, s128 *, 0x20) = DecomposeRotateMatrixEuler(sp);
}
}
