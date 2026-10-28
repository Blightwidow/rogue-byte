#include "sly2.h"
extern "C" void ClonePo();

void CloneTank(void *ptank, void *ptankBase)
{
    ClonePo();
    if (*(void **)((char *)ptank + 0x1d0) == ptankBase)
        *(void **)((char *)ptank + 0x1d0) = ptank;
}
