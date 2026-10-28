#include "sly2.h"
struct SLOTHEAP { int pad[3]; void *freelist; };
extern "C" {
void *PvAllocSlotheapImpl(SLOTHEAP *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void CGc_Collect(void *);
void InitVarbNode(void *);
extern SLOTHEAP B_004520D0;
extern void *B_004520C0[];
extern unsigned B_002DD294;
extern int B_003E0EA4;
extern char g_2dd598;
void *PvarbNew(void)
{
    if (!B_004520D0.freelist) {
        if (!B_003E0EA4 || B_002DD294 >= 4) CGc_Collect(&g_2dd598);
        if (!B_004520D0.freelist) {
            void *chunk = PvAllocSlotheapImpl(&B_004520D0);
            if (B_002DD294) FreeSlotheapPv(&B_004520D0, chunk);
            B_004520C0[B_002DD294++] = chunk;
        }
    }
    char *p = (char *)PvAllocSlotheapImpl(&B_004520D0);
    InitVarbNode(p);
    *(int *)(p + 0xC) = -1;
    *(int *)(p + 0x14) = 0;
    return p;
}
}
