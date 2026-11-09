#include "dl.h"
int FFindDlEntry(DL *pdl, void *pv)
{
    int found = 0;
    if (((DLE *)((char *)pv + pdl->ibDle))->next != 0 || pdl->tail == pv)
        found = 1;
    return found;
}
