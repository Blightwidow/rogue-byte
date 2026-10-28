/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SW;
struct SO { char pad[0x148]; unsigned long grfso; };
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
        unsigned long m7, m6, m5, m4;
        asm("ori %0, $0, 0x8000\n\tdsll %0, %0, 16" : "=r" (m7));
        asm("ori %0, $0, 0x8000\n\tdsll %0, %0, 17" : "=r" (m6));
    asm("lui %0, 0xBFFF\n\tori %0, %0, 0xFFFF\n\tdsll %0, %0, 2\n\tori %0, %0, 3" : "=r" (m5));
    asm("lui %0, 0xBFFF\n\tori %0, %0, 0xFFFF\n\tdsll %0, %0, 1\n\tori %0, %0, 1" : "=r" (m4));
        SO *so = xa->so;
        XA *next = xa->next;
        long grf = so->grfso;
        int was = (int)(grf >> 31) & 1;
        int is = (int)(grf >> 32) & 1;
        if (was != is) {
            if (grf & m7)
                RemoveSoXa(so, xa);
            else
                AddSoXa(so, xa);
        }
        if (xa->so->grfso & m6) {
            first = &xa->next;
        } else {
            *first = next;
            xa->next = freeList;
            freeList = xa;
        }
        SO *so2 = xa->so;
        unsigned long g = so2->grfso;
        g &= m5;
        g &= m4;
        so2->grfso = g;
        xa = next;
    }
    FreeSwXaList((SW *)B_003DD490, freeList);
}
