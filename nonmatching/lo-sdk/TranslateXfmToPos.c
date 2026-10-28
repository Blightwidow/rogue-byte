#include "m2c_macros.h"

M2C_UNK ConvertXfPos(M2C_UNK, s32, M2C_UNK);        /* extern */
M2C_UNK InvalidateXfmMatWorld(void *);              /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(void *, M2C_UNK);  /* extern */

void TranslateXfmToPos(void *arg0) {
    ConvertXfPos(0, M2C_FIELD(arg0, s32 *, 0x50), M2C_ERROR(/* unknown instruction: por $a2, $zero, $a1 */));
    __as__6VECTORG9VU_VECTOR(arg0 + 0x90, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    M2C_FIELD((arg0 + 0x60), f32 *, 0x3C) = 1.0f;
    InvalidateXfmMatWorld(arg0);
}
