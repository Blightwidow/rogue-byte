#include "dl.h"
extern "C" void ClearDl__FP2DL(DL *pdl)
{
    pdl->tail = 0;
    pdl->head = 0;
}
