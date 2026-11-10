#include "dl.h"
extern "C" int CPvDl__FP2DL(DL *pdl)
{
    int count = 0;
    for (void *pv = pdl->head; pv != 0; pv = ((DLE *)((char *)pv + pdl->ibDle))->next)
        count++;
    return count;
}
