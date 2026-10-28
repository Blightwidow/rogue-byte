#include "m2c_macros.h"

void CbWrite__15CQueueOutputIpuiPv(s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = arg1 & 0xFFFFFFF0;
    *(u32 *)0x1000B420 = (u32) ((temp_v0 >= 0x1001) ? 0x1000 : temp_v0) >> 4;
    *(s32 *)0x1000B410 = arg2 & 0x0FFFFFFF;
    *(s32 *)0x1000B400 = 0x101;
    M2C_SYNC();
}
