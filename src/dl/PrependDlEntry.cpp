#include "dl.h"
void PrependDlEntry(DL *pdl, void *pv)
{
    int ibDle = pdl->ibDle;
    char *pvHead = (char *)pdl->head;
    DLE *pdle = (DLE *)((char *)pv + ibDle);
    if (pvHead == 0) {
        pdl->tail = pv;
        pdl->head = pv;
    } else {
        pdle->next = pvHead;
        pvHead += ibDle;
        ((DLE *)pvHead)->prev = pv;
        pdl->head = pv;
    }
}
