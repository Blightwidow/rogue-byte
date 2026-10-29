#include "m2c_macros.h"
extern "C" {

void *PjsgeAllocJsg(s32, s32, s32);                  /* extern */

void AddSeqRecordCallAnimation(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(arg0, 0xA, arg3);
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg4;
}
}
