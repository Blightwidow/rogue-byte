#include "m2c_macros.h"

M2C_UNK CbFill__10CByteQueueiPUc(void *, u32, s32); /* extern */

s32 FMpegAcceptVideo__FP7sceMpegP16sceMpegCbDataStrP5CMpeg(s32 arg0, void *arg1, void *arg2) {
    s32 var_v0;
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg1, u32 *, 0xC);
    var_v0 = 0;
    if ((u32) M2C_FIELD(arg2, u32 *, 0x170) >= temp_v1) {
        CbFill__10CByteQueueiPUc(arg2 + 0x160, temp_v1, M2C_FIELD(arg1, s32 *, 8));
        var_v0 = 1;
    }
    return var_v0;
}
