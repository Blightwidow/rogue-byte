#include "sly2.h"
#include "m2c_macros.h"
void func_00185E30(char *arg0, QW arg1, QW arg2, QW arg3)
{
    *(QW *)(arg0 + 0x1F30) = arg1;
    *(QW *)(arg0 + 0x1F40) = arg2;
    *(QW *)(arg0 + 0x1F50) = arg3;
}
