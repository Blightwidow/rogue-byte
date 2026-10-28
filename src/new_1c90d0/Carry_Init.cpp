#include "sly2.h"

void Carry_Init(struct _carry* pcarry)
{
    int v0 = -1;
    *(int*)((char*)pcarry + 0xA4) = v0;
    *(int*)((char*)pcarry + 0x90) = v0;
}
