/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct IKLIMB { int xf0; int pxfUpper; int pxfLower; int pxfEnd; char pad[0xA0 - 0x10]; QW posTarget; QW posEffector; char pad2[0xE0 - 0xC0]; };
struct VT { short delta; short index; int (*fn)(void *, int); };
struct ALO { char pad[0xC]; char *vt; char pad1[0x148 - 0x10]; unsigned long flags; };
extern "C" {
unsigned U8Read__18CBinaryInputStream(Bis *);
int S16Read__18CBinaryInputStream(Bis *);
void ReadVector__18CBinaryInputStreamP6VECTOR(Bis *, void *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void InitIkLimb(void *);
void func_0012DD28(ALO *, int, int, void *);
}
static inline int ReadXf(ALO *palo, Bis *pbis)
{
    VT *vt = (VT *)(palo->vt + 0x198);
    return vt->fn((char *)palo + vt->delta, S16Read__18CBinaryInputStream(pbis));
}
extern "C" void LoadAloIkLimbs(ALO *palo, Bis *pbis)
{
    int count = U8Read__18CBinaryInputStream(pbis);
    if (count == 0)
        return;
    palo->flags |= 0x1000000000UL;
    if (count <= 0)
        return;
    ALLOCREQ req;
    int cbRec = 0xE0;
    int cbAlign = 0x10;
    int remaining = count;
    do {
        req.cb = cbRec;
        req.cbAlign = cbAlign;
        remaining--;
        IKLIMB *rec = (IKLIMB *)PvAllocSwClearImpl__Fi(&req);
        rec->pxfUpper = ReadXf(palo, pbis);
        rec->pxfLower = ReadXf(palo, pbis);
        rec->pxfEnd = ReadXf(palo, pbis);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, &rec->posEffector);
        rec->xf0 = ReadXf(palo, pbis);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, &rec->posTarget);
        InitIkLimb(rec);
        func_0012DD28(palo, rec->pxfUpper, -1, rec);
        func_0012DD28(palo, rec->pxfLower, -1, rec);
    } while (remaining != 0);
}
