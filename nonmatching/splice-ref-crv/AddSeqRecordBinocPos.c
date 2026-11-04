#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK, M2C_UNK);              /* extern */

void func_001E1488(f32 fparg0) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x3F, 1);
    M2C_FIELD(temp_v0, f32 *, 0x30) = fparg0;
    M2C_FIELD(temp_v0, s128 *, 0x10) = (s128) M2C_ERROR(/* unknown instruction: por $s1, $zero, $a1 */);
    M2C_FIELD(temp_v0, f32 *, 0x28) = (f32) (M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $s0 */) * 0.017453294f);
    M2C_FIELD(temp_v0, f32 *, 0x20) = (f32) (M2C_ERROR(/* unknown instruction: por $s0, $zero, $a2 */) * 0.017453294f);
    M2C_FIELD(temp_v0, f32 *, 0x24) = (f32) (M2C_ERROR(/* unknown instruction: prot3w $v1, $s0 */) * 0.017453294f);
}
