#include "m2c_macros.h"

M2C_UNK Goal_Pop(s32);                              /* extern */

void Goal_Deactivate(s32 arg0) {
    Goal_Pop(arg0 + 0x18);
}
