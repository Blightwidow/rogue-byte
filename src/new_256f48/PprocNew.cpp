#include "sly2.h"
struct SLOTHEAP { int pad[3]; void *freelist; };
extern "C" {
void *PvAllocSlotheapImpl(SLOTHEAP *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void CGc_Collect(void *);
void InitProcNode(void *);
extern SLOTHEAP B_00452120;
extern void *B_00452110[];
extern unsigned B_002DD2B4;
extern int B_003E0EA4;
extern char g_2dd598;
void *PprocNew(void)
{
    if (!B_00452120.freelist) {
        if (!B_003E0EA4 || B_002DD2B4 >= 4) CGc_Collect(&g_2dd598);
        if (!B_00452120.freelist) {
            void *chunk = PvAllocSlotheapImpl(&B_00452120);
            if (B_002DD2B4) FreeSlotheapPv(&B_00452120, chunk);
            B_00452110[B_002DD2B4++] = chunk;
        }
    }
    char *p = (char *)PvAllocSlotheapImpl(&B_00452120);
    InitProcNode(p);
    *(int *)(p + 8) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    return p;
}
}
