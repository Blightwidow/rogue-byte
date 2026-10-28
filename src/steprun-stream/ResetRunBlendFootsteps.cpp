#include "sly2.h"

void ResetRunBlendFootsteps(void* prunbl)
{
    *(int*)((char*)prunbl + 0xa0) = 0;
    *(int*)((char*)prunbl + 0x9c) = 0;
}