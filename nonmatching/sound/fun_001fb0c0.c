#include "m2c_macros.h"

s32 FFloatsNear__Ffff();    /* extern */
M2C_UNK SetAmbGrf();                /* extern */
extern s128 g_2a2dd0;

void func_001FB0C0(void *arg0) {
    s32 temp_a0;
    s32 temp_s3;
    s32 var_a1;
    s32 var_s4;
    s32 var_v1;

    var_v1 = 0;
    if ((M2C_FIELD(arg0, s32 *, 0x40) == 0) && ((M2C_FIELD(arg0, u16 *, 0x52) != 0) || (var_v1 = 0 ^ 1, ((M2C_FIELD(arg0, u16 *, 0x50) & 1) != 0)))) {
        var_v1 = 1 ^ 1;
    }
    if (var_v1 != 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x1C);
        temp_s3 = (M2C_FIELD(arg0, s16 *, 0x4E) > 0) ? 0x1F3 : 0x1F1;
        if (temp_a0 == 0) {
            var_s4 = 0;
            if ((FFloatsNear__Ffff(temp_a0, g_2a2dd0, M2C_FIELD(arg0, s128 *, 0x20), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), 0x38D1B717) != 0)) {
                var_s4 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), 0x38D1B717) != 0;
            }
            var_a1 = temp_s3;
            if (var_s4 == 0) {
                goto block_10;
            }
        } else {
block_10:
            var_a1 = temp_s3 | 0x200;
        }
        SetAmbGrf(arg0, var_a1, var_a1);
    }
}
