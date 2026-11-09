extern "C" {
#include "types.h"
void RebuildLight(void *);
void func_001A3B38(void *);
void SetLightKind(void *arg0, s32 arg1)
{
    func_001A3B38(arg0);
    *(s32 *)((char *)arg0 + 0xE0) = arg1;
    RebuildLight(arg0);
}
}
