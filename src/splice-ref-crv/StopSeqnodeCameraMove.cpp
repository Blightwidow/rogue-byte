#include "sly2.h"
extern "C" void RevokeCmPolicy(char *, int, int, char *, void *, void *);
extern "C" char B_002DDF40[];

extern "C" void StopSeqnodeCameraMove(char *arg0, int arg1)
{
    *(int *)(arg0 + 0x90) = arg1;
    *(int *)(arg0 + 0x9C) = 0;
    RevokeCmPolicy(B_002DDF40, 2, 0xA, B_002DDF40 + 0x500, 0, arg0 + 0x84);
}
