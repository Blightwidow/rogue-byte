#include "sly2.h"

extern "C" void* PguardanimBestMatch(void* p0, unsigned long a1);

// 0x209BC0 PguardanimCurrent
void* PguardanimCurrent(void* pstepguard)
{
    unsigned long arg1 = *(unsigned long*)((char*)pstepguard + 0x2C0);
    return PguardanimBestMatch(pstepguard, arg1);
}