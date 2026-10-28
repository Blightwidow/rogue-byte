// 0x148718 InitBtn
#include "sly2.h"
void InitBtn(void* pbtn)
{
    char* p = (char*)pbtn;
    *(int*)(p + 0x90) = -1;
    *(float*)(p + 0x8C) = 1.0f;
    *(float*)(p + 0x98) = 1.0f;
}