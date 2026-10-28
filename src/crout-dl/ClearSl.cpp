#include "sly2.h"

// ClearSl
void ClearSl(void* psl)
{
    *(void**)((char*)psl + 4) = 0;
    *(void**)psl = 0;
}