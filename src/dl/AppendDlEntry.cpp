#include "dl.h"
void AppendDlEntry(DL *pdl, void *pv)
{
    int ibDle = pdl->ibDle;
    char *pvTail = (char *)pdl->tail;
    DLE *pdle = (DLE *)((char *)pv + ibDle);
    if (pvTail == 0) {
        pdl->tail = pv;
        pdl->head = pv;
    } else {
        pdle->prev = pvTail;
        pvTail += ibDle;
        ((DLE *)pvTail)->next = pv;
        pdl->tail = pv;
    }
}
