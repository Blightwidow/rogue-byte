// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct DLE { char *next; char *prev; };
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; DLE *current; int offset; DLI *outer; };
struct VT { char pad[0x10]; short delta; short index; void (*fn)(void *); };
struct FRM { char pad[0x34]; DL dlA; char pad2[0x40 - 0x34 - 12]; DL dlB; };
struct ENTRY { char pad[0xC]; VT *vptr; char pad2[0x1088 - 0x10]; void *extra; };
extern DLI *g_2dd2fc;
extern char B_003E1518, B_003E1530;
extern "C" {
void ClearDl__FP2DL(DL *);
int FIsDlEmpty__FP2DL(DL *);
void FreeSlotheapPv(void *, void *);
void RemoveDlEntry(DL *, char *);
}
static inline void DestroyPending(FRM *frm, DL *dl)
{
    DLI iter;
    int offset = dl->offset;
    DLI *outer = g_2dd2fc;
    g_2dd2fc = &iter;
    iter.outer = outer;
    char *entry = frm->dlA.first;
    iter.list = dl;
    iter.offset = offset;
    iter.current = (DLE *)(entry + offset);
    if (entry) {
        do {
            RemoveDlEntry(dl, entry);
            ENTRY *object = (ENTRY *)entry;
            object->vptr->fn((char *)object + object->vptr->delta);
            entry = iter.current->next;
            iter.current = (DLE *)(entry + iter.offset);
        } while (entry);
    }
    ClearDl__FP2DL(dl);
    g_2dd2fc = iter.outer;
}
static inline void FreePending(FRM *frm, DL *dl)
{
    DLI iter;
    int offset = dl->offset;
    DLI *outer = g_2dd2fc;
    g_2dd2fc = &iter;
    iter.outer = outer;
    char *entry = frm->dlB.first;
    iter.list = dl;
    iter.offset = offset;
    iter.current = (DLE *)(entry + offset);
    if (entry) {
        do {
            ENTRY *object = (ENTRY *)entry;
            if (object->extra)
                FreeSlotheapPv(&B_003E1530, object->extra);
            RemoveDlEntry(dl, entry);
            FreeSlotheapPv(&B_003E1518, entry);
            entry = iter.current->next;
            iter.current = (DLE *)(entry + iter.offset);
        } while (entry);
    }
    ClearDl__FP2DL(dl);
    g_2dd2fc = iter.outer;
}
extern "C" void ClearPendingFrame__FP3FRM(FRM *frm)
{
    if (!FIsDlEmpty__FP2DL(&frm->dlA))
        DestroyPending(frm, &frm->dlA);
    if (!FIsDlEmpty__FP2DL(&frm->dlB))
        FreePending(frm, &frm->dlB);
}
