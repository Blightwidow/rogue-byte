#include "sly2.h"
struct CLOCK { char pad0[8]; float unk8; float unkC; char pad10[8]; float af[9]; char pad[0xC]; long unk48; long unk50; };
extern "C" CLOCK g_2dded0;
extern "C" long TickReadCount(CLOCK *);
extern "C" void InitClock(CLOCK *);

void StaticInitClock()
{
    long count;
    asm volatile("mfc0 %0, $9" : "=r"(count));
    volatile long saved = count;
    g_2dded0.unk50 = count;
    g_2dded0.unk48 = TickReadCount(&g_2dded0);
    float *pf = g_2dded0.af;
    unsigned i = 0;
    do {
        *pf = 1.0f;
        i++;
        pf++;
    } while (i < 9);
    g_2dded0.unk8 = 1.0f;
    g_2dded0.unkC = 1.0f;
    InitClock(&g_2dded0);
}
