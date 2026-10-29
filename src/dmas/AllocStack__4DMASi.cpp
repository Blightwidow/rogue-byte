#include "sly2.h"

void *PvAllocStackImpl__Fi(void *, int);

void AllocStack__4DMASi(char *arg0, int arg1)
{
    int sp[4];
    int size;
    char *block;
    size = arg1 << 4;
    sp[0] = size;
    sp[1] = 0x10;
    block = (char *)PvAllocStackImpl__Fi(sp, arg1);
    *(char **)(arg0 + 0xC) = block;
    *(char **)(arg0 + 0) = block + size;
    *(char **)(arg0 + 4) = block;
}
