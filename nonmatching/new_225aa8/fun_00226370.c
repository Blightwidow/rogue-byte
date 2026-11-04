#include "m2c_macros.h"

s32 func_0012DC18(s32, M2C_UNK, M2C_UNK, s128);     /* extern */
M2C_UNK func_0012E460(void *);                      /* extern */

void func_00226370(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x1CC) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x1CC) = arg1;
        if (arg1 != 0) {
            M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
            M2C_ERROR(/* unknown instruction: por $t1, $zero, $v0 */);
            M2C_FIELD(arg0, s32 *, 0x1D8) = func_0012DC18(M2C_FIELD(arg0, s32 *, 0x5C), 1, 5, M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */));
            return;
        }
        func_0012E460(arg0 + 0x1D8);
    }
}
