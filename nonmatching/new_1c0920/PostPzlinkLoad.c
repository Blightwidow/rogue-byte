#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
s32 PpathzoneFindPos(M2C_UNK, M2C_UNK);             /* extern */
s128 func_001C1F28(void *);                         /* extern */

void PostPzlinkLoad(void *arg0) {
    PostLoLoad();
    M2C_FIELD(arg0, s128 *, 0x130) = func_001C1F28(arg0 + 0x60);
    M2C_FIELD(arg0, s32 *, 0x124) = PpathzoneFindPos(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), 0);
    M2C_FIELD(arg0, s128 *, 0x140) = func_001C1F28((M2C_FIELD(arg0, s32 *, 0x50) << 5) + arg0 + 0x40);
    M2C_FIELD(arg0, s32 *, 0x128) = PpathzoneFindPos(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), 0);
}
