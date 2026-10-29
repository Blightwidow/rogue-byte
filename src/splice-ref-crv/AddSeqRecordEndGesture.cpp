#include "sly2.h"
#include "m2c_macros.h"
s8 *PjsgeAllocJsg(s32, s32, s32);

void AddSeqRecordEndGesture(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s8 *temp = PjsgeAllocJsg(arg0, 0x48, 1);
    *(s32 *)(temp + 0x10) = arg1;
    *(s32 *)(temp + 0x14) = arg2;
    *(s32 *)(temp + 0x18) = arg3;
}
