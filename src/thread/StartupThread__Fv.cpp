#include "sly2.h"
struct THREADPARAM { int unk0; void *entry; void *stack; int stackSize; void *gp; int priority; char pad[0x30 - 0x18]; };
struct TIDS { int startup; int render; };
extern TIDS B_004425D0;
extern char B_004425F0[];
extern char B_002E5270[];
extern "C" int GetThreadId();
extern "C" int ChangeThreadPriority(int, int);
extern "C" int CreateThread(THREADPARAM *);
void FrameRenderLoop(void *);

int StartupThread()
{
    THREADPARAM param;
    B_004425D0.startup = GetThreadId();
    ChangeThreadPriority(B_004425D0.startup, 5);
    memset(&param, 0, 0x30);
    param.stackSize = 0x1000;
    param.stack = B_004425F0;
    param.priority = 2;
    param.gp = B_002E5270;
    param.entry = (void *)FrameRenderLoop;
    B_004425D0.render = CreateThread(&param);
}
