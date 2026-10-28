#include "sly2.h"

int BusyMenu_FShowing(void* pmenu)
{
    int v1 = *(int*)((int)pmenu + 0x24);
    if (v1 == 0)
        return 0;
    int v0 = *(int*)((int)v1 + 0x58);
    if (v0 >= 2)
        return 0;
    int v2 = *(int*)((int)v1 + 0x64);
    if (v2 >= 2)
        return 0;
    return 1;
}