#include "m2c_macros.h"

s32 NewEmitter(M2C_UNK);                            /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
M2C_UNK SetJtZapState(s32, M2C_UNK);                /* extern */
M2C_UNK SetZapContinuation(s32, M2C_UNK);           /* extern */

void func_001A2028(s32 arg0) {
    SetEmitterUnpositioned(NewEmitter(0x6A), 0);
    SetJtZapState(arg0, 6);
    M2C_ERROR(/* unknown instruction: ldl $a1, %lo(RO_002A6797)($v0) */);
    SetZapContinuation(arg0, M2C_ERROR(/* unknown instruction: ldr $a1, %lo(RO_002A6790)($v0) */));
}
