#include "m2c_macros.h"

M2C_UNK Goal_Pop(void *);                           /* extern */
s32 PcmdFindScriptLabel(s32, s32);                  /* extern */

void JumpGuardScript(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
            Goal_Pop(arg0 + 0x18);
            M2C_FIELD(arg0, s32 *, 0x40) = 0;
        }
        M2C_FIELD(arg0, s32 *, 0x38) = PcmdFindScriptLabel(M2C_FIELD(arg0, s32 *, 0x30), arg1);
    }
}
