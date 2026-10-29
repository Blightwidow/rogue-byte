#include "sly2.h"
extern "C" void GetPathPosFromS(char *, QW *, int);
extern "C" void func_001CBB58(char *a, char *b, QW *out)
{
    QW pos;
    GetPathPosFromS(a, &pos, 0);
    if (out) {
        int fence;
        int fence2;
        asm volatile("lqc2 vf1, %1" : "=r"(fence) : "m"(pos));
        asm("lqc2 vf2, %1\n\tvsub.xyzw vf1, vf1, vf2" : "=r"(fence2) : "m"(*(QW *)(b + 0x240)), "m"(*(QW *)(b + 0x240)), "m"(*(QW *)(b + 0x240)), "r"(fence));
        asm("sqc2 vf1, %0" : "=m"(*out) : "r"(fence2));
    }
}
