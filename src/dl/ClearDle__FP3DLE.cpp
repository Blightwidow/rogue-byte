#include "dl.h"
extern "C" void ClearDle__FP3DLE(DLE *pdle)
{
    pdle->prev = 0;
    pdle->next = 0;
}
