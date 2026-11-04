#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, M2C_UNK, s128, s128); /* extern */
void *PloNew(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_001A3610(void *, M2C_UNK);             /* extern */
M2C_UNK func_001A3630(void *, M2C_UNK);             /* extern */
extern void *B_003E04F8;
extern s128 g_2a2dc0;

void func_001A3260(void) {
    char sp[0x400];
    M2C_UNK sp50;
    M2C_UNK sp60;
    s128 sp40;
    void *temp_s0;
    void *temp_v0;
    void *var_s0;

    var_s0 = B_003E04F8;
loop_1:
    if (var_s0 != NULL) {
        if (M2C_FIELD(var_s0, s32 *, 0x160) != 0) {
            var_s0 = M2C_FIELD(var_s0, void **, 0x20);
            goto loop_1;
        }
        if (var_s0 == NULL) {
            goto block_7;
        }
    } else {
block_7:
        temp_s0 = PloNew(4, 0, 0x188, -1);
        M2C_ERROR(/* unknown instruction: pextlw $v0, $a0, $v0 */);
        BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp40, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), g_2a2dc0, M2C_ERROR(/* unknown instruction: pcpyld $v0, $a0, $v0 */));
        temp_v0 = M2C_FIELD(temp_s0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *, s128, s128, s128), 0xF4)(temp_s0 + M2C_FIELD(temp_v0, s16 *, 0xF0), sp, sp40, sp50, sp60);
        func_001A3610(temp_s0, 0x437F0000);
        func_001A3630(temp_s0, 0x43700000);
    }
}
