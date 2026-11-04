#include "m2c_macros.h"

M2C_UNK SeekSpriteInstanceTime(M2C_UNK, f32);       /* extern */

void SeekSpriteInstanceFraction(void *arg0, s32 arg1) {
    s16 temp_v0;

    M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f12 */);
    temp_v0 = M2C_FIELD(((arg1 * 0x18) + M2C_FIELD(arg0, s32 *, 8)), s16 *, 8);
    if (temp_v0 >= 0) {
        SeekSpriteInstanceTime(0x18, M2C_FIELD(((temp_v0 * 0x18) + M2C_FIELD(arg0, s32 *, 4)), f32 *, 8) * M2C_ERROR(/* unknown instruction: min.s $f0, $f1, $f0 */));
    }
}
