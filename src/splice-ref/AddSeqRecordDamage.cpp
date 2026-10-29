#include "sly2.h"
extern "C" {

char *PjsgeAllocJsg(void *, int, int);

void AddSeqRecordDamage(void *arg0, int arg1, int arg2, int arg3, int arg4)
{
    char *block;
    block = PjsgeAllocJsg(arg0, 0x1C, arg3);
    *(int *)(block + 0x10) = arg1;
    *(int *)(block + 0x14) = arg2;
    *(int *)(block + 0x18) = arg4;
}
}
