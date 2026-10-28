#include "sly2.h"

extern "C" void *PjsgeAllocJsg(int);
extern "C" void *PrecAddSeq_1e01f8(int, int, int);

void AddSeqRecordShowBrief(int n, float dt, int pseq, int fNoWait)
{
    void *v0 = PjsgeAllocJsg(0x53);
    *(int *)((char *)v0 + 0x10) = n;
    *(float *)((char *)v0 + 0x14) = dt;
}