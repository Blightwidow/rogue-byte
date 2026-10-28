#include "sly2.h"
extern "C" void *PvAllocStackImpl__Fi(void *);
extern int *B_003DD010;
extern int *B_003DD018;
extern int B_003DD00C;
extern int B_003DD014;
extern "C" void InitIdHashTables_1ed3a8()
{
    int req[2];
    req[0] = 0xfff4;
    req[1] = 0x10;
    B_003DD010 = (int *)PvAllocStackImpl__Fi(req);
    memset(B_003DD010, 0, 0xfff4);
    req[0] = 0xfff4;
    req[1] = 0x10;
    B_003DD018 = (int *)PvAllocStackImpl__Fi(req);
    memset(B_003DD018, 0, 0xfff4);
    B_003DD00C = B_003DD014 = 0;
}
