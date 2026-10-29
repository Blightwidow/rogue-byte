#include "sly2.h"

void RemoveSoLoHierarchy(void *);
void RetractSmaRef(void *);

void RemoveGadgetObjLoHierarchy(char *arg0)
{
    char *temp;
    RemoveSoLoHierarchy(arg0);
    temp = *(char **)(arg0 + 0xC);
    ((void (*)(char *, int))(*(void **)(temp + 0x264)))(arg0 + *(short *)(temp + 0x260), -1);
    RetractSmaRef(arg0 + 0x168);
}
