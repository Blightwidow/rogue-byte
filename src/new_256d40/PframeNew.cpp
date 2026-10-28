/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SLOTHEAP { int pad[3]; void *freelist; };
extern "C" {
void *PvAllocSlotheapImpl(SLOTHEAP *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void CGc_Collect(void *);
void InitFrameNode(void *);
extern SLOTHEAP B_004520F8;
extern void *B_004520E8[];
extern unsigned B_002DD2A4;
extern int B_003E0EA4;
extern char g_2dd598;
void *PframeNew(void)
{
    if (!B_004520F8.freelist) {
        if (!B_003E0EA4 || B_002DD2A4 >= 4) CGc_Collect(&g_2dd598);
        if (!B_004520F8.freelist) {
            void *chunk = PvAllocSlotheapImpl(&B_004520F8);
            if (B_002DD2A4) FreeSlotheapPv(&B_004520F8, chunk);
            B_004520E8[B_002DD2A4++] = chunk;
        }
    }
    char *p = (char *)PvAllocSlotheapImpl(&B_004520F8);
    InitFrameNode(p);
    int *q = (int *)(p + 0xC);
    int n = 3;
    do { *q++ = 0; } while (--n != -1);
    *(int *)(p + 0x1C) = 0;
    return p;
}
}
