#include "dl.h"
extern DLI *g_2dd2fc;

void RemoveDlEntry(DL *pdl, void *pv)
{
    DLE *pdle = (DLE *)((char *)pv + pdl->ibDle);
    DLI *pdli;
    for (pdli = g_2dd2fc; pdli != 0; pdli = pdli->m_pdliNext) {
        if (pdli->m_ppv == (void **)pdle) {
            if (pdle->prev != 0)
                pdli->m_ppv = (void **)((char *)pdle->prev + pdl->ibDle);
            else
                pdli->m_ppv = (void **)pdl;
        }
    }
    if (pdle->prev != 0)
        ((DLE *)((char *)pdle->prev + pdl->ibDle))->next = pdle->next;
    else
        pdl->head = pdle->next;
    if (pdle->next != 0)
        ((DLE *)((char *)pdle->next + pdl->ibDle))->prev = pdle->prev;
    else
        pdl->tail = pdle->prev;
    pdle->next = 0;
    pdle->prev = 0;
}
