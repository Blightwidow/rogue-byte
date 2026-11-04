#include "sly2.h"

extern "C" void WakeXf(void *a0, void *a1, float a2);

void func_001F8898(unsigned char *arg0, float arg1)
{
    float scaled = arg1 * 1000.0f;

    *(short *)((unsigned char *)*(void **)(arg0 + 0x24) + 0xAC) = (short)(int)scaled;
    WakeXf(*(void **)(arg0 + 0x20), *(void **)(arg0 + 0x24), scaled);
}
