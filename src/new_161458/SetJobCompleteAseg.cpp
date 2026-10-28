#include "sly2.h"

void SetJobCompleteAseg(int *arg0, int arg1, int arg2, int arg3)
{
    *(int *)((char *)arg0 + 0xAC) = arg1;
    *(int *)((char *)arg0 + 0xB0) = arg2;
    *(int *)((char *)arg0 + 0xB4) = arg3;
}
