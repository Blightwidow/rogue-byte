#include "sly2.h"

extern "C" void WakeXf(void *a0, void *a1, float a2);

void func_001F8898(void *a0, float f12)
{
    const float f0 = 1000.0f;
    float  f2;
    int f0i = (int)f2;
    f2 = f12 * f0;
    int short f0u = (unsigned short)f0i;

    void * v1;
    *(unsigned short *)((unsigned char *)v1 + 0xAC) = f0u;
    v1 = *(void **)((unsigned char *)a0 + 0x24);

    void *v0 = *(void **)((unsigned char *)a0 + 0x20);
    WakeXf(v0, v1, f12);
}

