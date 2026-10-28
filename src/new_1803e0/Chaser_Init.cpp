#include "sly2.h"
extern "C" void func_0017F090(void *);
extern "C" void func_001813C0(void *, float);
extern "C" void func_001813F0(void *, float);
extern "C" void func_0017F3E0(void *, int, void *);
extern "C" void Chaser_Init(char *self)
{
    func_0017F090(self);
    float one = 1.0f;
    *(float *)(self + 0x340) = one;
    *(float *)(self + 0x350) = one;
    *(float *)(self + 0x364) = one;
    *(float *)(self + 0x338) = 250.0f;
    *(float *)(self + 0x370) = -3.402823466e+38f;
    *(float *)(self + 0x374) = 3.402823466e+38f;
    func_001813C0(self, one);
    func_001813F0(self, one);
    func_0017F3E0(self, 5, self + 0x220);
    *(int *)(self + 0x1C0) = -1;
}
