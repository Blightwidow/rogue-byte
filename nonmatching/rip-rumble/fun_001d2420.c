#include "m2c_macros.h"

M2C_UNK PosLoWorld();                               /* extern */

void func_001D2420(void *arg0) {
    s32 temp_v0;
    s32 var_a0;

    M2C_FIELD(arg0, s32 *, 0x5B0) = 0;
    PosLoWorld();
    M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */);
    var_a0 = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x5AC), s32 *, 0xE8) > 0) {
        do {
            temp_v0 = var_a0 * 0x10;
            var_a0 += 1;
            M2C_FIELD((temp_v0 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x5AC), s32 *, 0xF4)), f32 *, 8) = (f32) M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $a1 */);
        } while (var_a0 < M2C_FIELD(M2C_FIELD(arg0, void **, 0x5AC), s32 *, 0xE8));
    }
}
