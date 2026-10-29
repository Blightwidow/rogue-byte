#include "sly2.h"
extern "C" void RemoveLoHierarchy();
extern "C" void RevokeCmPolicy(char *, int, int, char *, void *, void *);
extern "C" char B_002DDF40[];

extern "C" void Camobj_RemoveLoHierarchy(char *arg0)
{
    RemoveLoHierarchy();
    if (*(int *)(arg0 + 0x124) != 0) {
        RevokeCmPolicy(B_002DDF40, 0xF, 0xA, B_002DDF40 + 0x4A8, 0, arg0);
    }
}
