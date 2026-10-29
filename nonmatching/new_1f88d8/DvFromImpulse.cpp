#include "sly2.h"
extern "C" void ApplyConstrLocal(char *, int, QW);
extern "C" void DvFromImpulse(char *obj, QW impulse)
{
    QW keep;
    QW scaled;
    int fence;
    int fence2;
    int fence3;
    asm("qmtc2.ni %1, vf3" : "=r"(fence) : "r"(impulse));
    char *p = *(char **)(obj + 0xE8);
    int mass = *(int *)(p + 0xD0);
    asm("qmtc2.ni %2, vf2\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q" : "=r"(fence2), "+r"(obj) : "r"(mass), "r"(fence));
    char *args = p + 0xB0;
    int field = *(int *)(obj + 0x58);
    asm("qmfc2.ni %0, vf1" : "=r"(scaled), "=r"(fence3) : "r"(fence2), "r"(field));
    asm("sqc2 vf2, %0" : "=m"(keep) : "r"(fence3));
    ApplyConstrLocal(args, field, scaled);
}
