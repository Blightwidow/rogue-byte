#include "sly2.h"
struct THREADPARAM { int status; void *entry; void *stack; int size; void *gp; int priority; int pad[6]; };
extern char B_003D3A50[];
extern char B_002E5270[];
extern int B_004425D0[];
extern int B_003D3A3C;
extern int B_003D3A40;
extern int B_003D3A44;
extern "C" void LoadingLogoThread();
extern "C" int CreateThread(THREADPARAM *);
extern "C" int NewSema(int, int);
extern "C" void func_002355E0(int, int);
extern "C" void InitLoadingLogoThread()
{
    THREADPARAM param;
    memset(&param, 0, sizeof(param));
    param.size = 0x1000;
    param.stack = B_003D3A50;
    param.gp = B_002E5270;
    param.priority = 4;
    param.entry = (void *)LoadingLogoThread;
    B_004425D0[4] = CreateThread(&param);
    B_003D3A3C = NewSema(0, 1);
    B_003D3A40 = NewSema(0, 1);
    B_003D3A44 = NewSema(0, 1);
    func_002355E0(B_004425D0[4], 0);
}
