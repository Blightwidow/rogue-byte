#include "sly2.h"
extern "C" void GetPathPosFromS(char *, QW *, int);
extern "C" void func_001CBB58(char *a, char *b, QW *out)
{
    QW pos;
    GetPathPosFromS(a, &pos, 0);
    if (out) {
        QW result;
        QW other = *(QW *)(b + 0x240);
        asm("vsub.xyzw %0, %1, %2" : "=j"(result) : "j"(pos), "j"(other));
        *out = result;
    }
}
