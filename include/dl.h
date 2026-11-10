/* SPDX-License-Identifier: GPL-3.0-or-later */
/* DL, the game's intrusive doubly linked list (docs/ROADMAP.md "Next", item 1). The type existed under this name: retail's
   mangled InitDl__FP2DLi, ClearDl__FP2DL, FIsDlEmpty__FP2DL and ClearDle__FP3DLE take a DL or a DLE. Names from the Sly 1
   decompilation (source: sly1 include/dl.h, CC0; THIRD_PARTY_NOTICES.md); layout from Sly 2's own matched code:
   AppendDlEntry, FFindDlEntry, CPvDl (head 0x0, tail 0x4, ibDle 0x8), RemoveDlEntry (DLE next 0x0, prev 0x4; DLI 0x4 and 0xC).
   An entry is the DLE at ibDle bytes into each element. C and C++. */
#ifndef SLY2_DL_H
#define SLY2_DL_H
#include "types.h"

struct DL {
    void *head;     /* the first element, 0 when empty */
    void *tail;     /* the last element */
    s32 ibDle;      /* where each element keeps its DLE */
};
typedef struct DL DL;

struct DLE {
    void *next;
    void *prev;
};
typedef struct DLE DLE;

struct DLI {        /* an iterator, kept in a global list so RemoveDlEntry can fix it up */
    struct DL *m_pdl;
    void **m_ppv;
    s32 m_ibDle;
    struct DLI *m_pdliNext;
};
typedef struct DLI DLI;

#ifdef __cplusplus
/* The iterators in use, newest first; RemoveDlEntry moves any that point at the entry it removes. */
extern DLI *g_2dd2fc;

/* Iterating a DL safely (an element may be removed while the loop runs). The same helpers appeared word for word in five
   matched functions (OnRipgRemove, CGc_Shutdown, ObstacleGroup_Dissolve, StopJsg, UpdateJsg): push an iterator, step it
   until it returns 0, pop it. */
inline void PushDli(DLI *pdli, DL *pdl)
{
    pdli->m_pdl = pdl;
    pdli->m_ppv = (void **)pdl;
    pdli->m_ibDle = pdl->ibDle;
    pdli->m_pdliNext = g_2dd2fc;
    g_2dd2fc = pdli;
}
inline void *PvFirst(DLI *pdli)
{
    void *pv = pdli->m_pdl->head;
    int ibDle = pdli->m_ibDle;
    pdli->m_ppv = (void **)((char *)pv + ibDle);
    return pv;
}
inline void *PvStep(DLI *pdli)
{
    void *pv = *pdli->m_ppv;
    pdli->m_ppv = (void **)((char *)pv + pdli->m_ibDle);
    return pv;
}
inline void PopDli(DLI *pdli)
{
    g_2dd2fc = pdli->m_pdliNext;
}
#endif

#if defined(__mips__)
typedef char check_DL_size[(sizeof(struct DL) == 0xC) ? 1 : -1];
typedef char check_DLE_size[(sizeof(struct DLE) == 0x8) ? 1 : -1];
typedef char check_DLI_size[(sizeof(struct DLI) == 0x10) ? 1 : -1];
#endif
#endif
