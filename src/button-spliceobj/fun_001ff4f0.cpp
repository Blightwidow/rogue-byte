#include "sly2.h"
extern "C" QW PosLoWorld(char *);
extern "C" void func_001FF4F0(char *a, char *b, QW *out)
{
    if (out) {
        QW pos = PosLoWorld(a);
        asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf3\n\tvsub.xyzw vf2, vf3, vf1\n\tsqc2 vf2, %0"
            : "=m"(*out) : "m"(*(QW *)(b + 0x240)), "r"(pos));
    }
}
