#include "m2c_macros.h"

M2C_UNK SetXfKind(void *, M2C_UNK);                 /* extern */
M2C_UNK func_001F5078(void *);                      /* extern */

void SetSoDvGravity(void *arg0) {
    void *temp_a1;

    if (M2C_FIELD(arg0, void **, 0xE8) != NULL) {
        temp_a1 = M2C_FIELD(arg0, void **, 0x58);
        if ((M2C_FIELD(temp_a1, s32 *, 0x90) == 0) && (M2C_FIELD(temp_a1, s16 *, 0x98) != 2)) {
            SetXfKind(temp_a1, 1);
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), s128 *, 0x80) = (s128) M2C_ERROR(/* unknown instruction: por $s1, $zero, $a1 */);
        func_001F5078(arg0);
    }
}
