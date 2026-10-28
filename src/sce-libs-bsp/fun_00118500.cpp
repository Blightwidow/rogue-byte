// 0x118500 FUN_00118500
#include "sly2.h"

void func_00118500(void *a0, int a1, int a2, int a3)
{
    void *p = a0;
    *(int *)((char *)p + 0x34) = a1;
    *(int *)((char *)p + 0x38) = a2;
    *(int *)((char *)p + 0) = a3;
}
