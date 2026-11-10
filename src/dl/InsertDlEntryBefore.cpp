#include "dl.h"
extern "C" {
void AppendDlEntry(DL *, void *);
void PrependDlEntry(DL *, void *);
void InsertDlEntryBefore(DL *pdl, void *pvBefore, void *pv)
{
    if (pvBefore == 0) {
        AppendDlEntry(pdl, pv);
        return;
    }
    if (pvBefore == pdl->head) {
        PrependDlEntry(pdl, pv);
        return;
    }
    int ibDle = pdl->ibDle;
    DLE *pdleBefore = (DLE *)((char *)pvBefore + ibDle);
    DLE *pdle = (DLE *)((char *)pv + ibDle);
    void *pvPrev = pdleBefore->prev;
    pdle->next = pvBefore;
    pdle->prev = pvPrev;
    pdleBefore->prev = pv;
    ((DLE *)((char *)pvPrev + ibDle))->next = pv;
}
}
