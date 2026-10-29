#include "sly2.h"
extern "C" void SetJmpState(void *, int, int, int);
extern "C" void func_00205008(void *, int, void *, QW);
extern "C" void func_00140C30(char *self, int a1, char *obj, QW pos)
{
    int fence;
    unsigned long flag = (*(unsigned long *)(obj + 0x28) >> 60) & 1;
    asm volatile("qmtc2.ni %1, vf2" : "=r" (fence) : "r" (pos));
    if (flag == 0) {
        SetJmpState(self + 0x2C0, 0, 0, 0);
    } else {
        QW delta;
        asm("lqc2 vf1, %2\n\tvsub.xyzw vf3, vf2, vf1" : "=r" (fence) : "r" (fence), "m" (*(QW *)(self + 0x1010)));
        asm("qmfc2.ni %0, vf3" : "=r" (delta) : "r" (fence));
        func_00205008(self, a1, obj, delta);
    }
}
