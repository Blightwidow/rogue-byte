#include "sly2.h"
struct ThreadParam {
    int attr;
    void (*entry)(void *);
    void *stack;
    int stackSize;
    void *gpReg;
    int priority;
    int pad[6];
};
extern "C" int NewSema(int, int);
extern "C" int CreateThread(ThreadParam *);
extern "C" void func_002355E0(int, int);
extern "C" void MpegDisplayThread(void *);
struct MPEGSTATE { char pad[0x114]; int a114; char pad2[0x23C - 0x118]; int sema; };
extern MPEGSTATE B_002F66B0;
extern char B_002E5270[];
extern char B_002F6900[];
extern int B_004425DC;
void func_001B2940()
{
    ThreadParam param;
    B_002F66B0.sema = NewSema(0, 1);
    B_002F66B0.a114 = 0;
    memset(&param, 0, 0x30);
    param.entry = MpegDisplayThread;
    param.stack = B_002F6900;
    param.stackSize = 0x1000;
    param.gpReg = B_002E5270;
    param.priority = 2;
    B_004425DC = CreateThread(&param);
    func_002355E0(B_004425DC, 0);
}
