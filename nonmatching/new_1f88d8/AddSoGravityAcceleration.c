#include "m2c_macros.h"

M2C_UNK AddSoAcceleration(void *, M2C_UNK);         /* extern */
M2C_UNK ApplyConstrLocal(void *, s32, s128);        /* extern */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
M2C_UNK UpdateSoDriven(void *);                     /* extern */
extern s128 g_2a2dd0;

void AddSoGravityAcceleration(void *arg0) {
    s32 var_s3;
    s32 var_s4;
    void *temp_a0;

    var_s3 = 0;
    var_s4 = 0;
    if ((FFloatsNear__Ffff(g_2a2dd0, M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), s128 *, 0x80), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), 0x38D1B717) != 0)) {
        var_s3 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), 0x38D1B717) != 0;
    }
    if (var_s3 == 0) {
        var_s4 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), s32 *, 0xC0) != 3;
    }
    if (var_s4 != 0) {
        temp_a0 = M2C_FIELD(arg0, void **, 0xE8);
        ApplyConstrLocal(temp_a0 + 0xB0, M2C_FIELD(arg0, s32 *, 0x58), M2C_FIELD(temp_a0, s128 *, 0x80));
        AddSoAcceleration(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    }
    if (M2C_FIELD(arg0, s32 *, 0x138) != 0) {
        UpdateSoDriven(arg0);
    }
}
