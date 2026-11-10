/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SW;
#include "so.h"
struct XA { int unk0; SO *so; XA *nextSo; XA *next; };
extern char B_003DD490[];
void RemoveSoXa(SO *, XA *);
void AddSoXa(SO *, XA *);
void FreeSwXaList(SW *, XA *);
void UpdateSwXaList(SW *sw, XA **first)
{
    XA *freeList = 0;
    XA *xa = *first;
    while (xa) {
        SO *so = xa->so;
        XA *next = xa->next;
        long grf = so->grfso;
        int was = (int)(grf >> 31) & 1;
        int is = (int)(grf >> 32) & 1;
        if (was != is) {
            if (grf & (0x8000L << 16))
                RemoveSoXa(so, xa);
            else
                AddSoXa(so, xa);
        }
        if (xa->so->grfso & (0x8000L << 17)) {
            first = &xa->next;
        } else {
            *first = next;
            xa->next = freeList;
            freeList = xa;
        }
        SO *so2 = xa->so;
        unsigned long g = so2->grfso;
        g &= ~(0x8000L << 17);
        g &= ~(0x8000L << 16);
        so2->grfso = g;
        xa = next;
    }
    FreeSwXaList((SW *)B_003DD490, freeList);
}
