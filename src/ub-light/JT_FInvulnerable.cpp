#include "sly2.h"
extern "C" int FInvulnerableJt(void *, int);
extern "C" int func_00194640(void *, int);
extern "C" int JT_FInvulnerable(char *self, int arg)
{
    switch (*(int *)(self + 0x18C8)) {
    case 3: case 8: case 21: case 22:
        if (arg != 0x4000) goto call;
        return 1;
    case 7:
        if (func_00194640(self + 0x4C0, arg) != 0) return 1;
    default:
    call:
        return FInvulnerableJt(self, arg);
    }
}
