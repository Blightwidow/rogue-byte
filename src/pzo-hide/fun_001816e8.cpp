#include "sly2.h"

extern "C" {
void FAddRsmg__FP4RSMGiPii3OIDN24(const void *, unsigned char *, int, int *, int, int, int, int);
typedef struct { char pad[0x20]; } SwStub;
extern SwStub B_003DD490;
}

extern "C" void func_001816E8(void *pthis, int a1, int a2, int a3, int a4)
{
    FAddRsmg__FP4RSMGiPii3OIDN24(&B_003DD490, (unsigned char *)((char *)pthis + 0x204), 4, (int *)((char *)pthis + 0x200), a1, a2, a3, a4);
}
