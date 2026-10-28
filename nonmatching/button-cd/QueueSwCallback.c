#include "m2c_macros.h"

M2C_UNK AppendSlEntry(s32, void *);                 /* extern */
void *PvAllocSlotheapImpl(s32, s64);                /* extern */

void QueueSwCallback(s32 arg0, s32 arg1, s64 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = PvAllocSlotheapImpl(arg0 + 0x3C90, arg2);
    M2C_FIELD(temp_v0, s32 *, 0) = arg1;
    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, ($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0xb($v0) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, 0x4($v0) */);
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg3;
    AppendSlEntry(arg0 + 0x3CA8, temp_v0);
}
