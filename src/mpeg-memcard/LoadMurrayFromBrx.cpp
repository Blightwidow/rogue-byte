/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct SET { int pad0; void *a; void *b; void *c; };
struct MURRAY {
    char pad[0x15F0]; void *p15F0; void *p15F4; void *p15F8; void *p15FC; char pad2[0x1610 - 0x1600]; SET *setA; SET *setB;
};
extern "C" {
extern char D_002C0270[];
void LoadStepFromBrx(MURRAY *, Bis *);
void SetSoProperties(MURRAY *, int, void *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *func_001F4C58(MURRAY *, int, int);
void InitIkLimb(SET *);
}
extern "C" void LoadMurrayFromBrx(MURRAY *murray, Bis *bis)
{
    LoadStepFromBrx(murray, bis);
    SetSoProperties(murray, 0x89, D_002C0270);
    ALLOCREQ req;
    req.cb = 0xE0;
    req.cbAlign = 0x10;
    murray->setA = (SET *)PvAllocSwClearImpl__Fi(&req);
    murray->setA->a = func_001F4C58(murray, 0x200, 6);
    murray->setA->b = func_001F4C58(murray, 0x201, 6);
    murray->setA->c = func_001F4C58(murray, 0x202, 1);
    InitIkLimb(murray->setA);
    req.cb = 0xE0;
    req.cbAlign = 0x10;
    murray->setB = (SET *)PvAllocSwClearImpl__Fi(&req);
    murray->setB->a = func_001F4C58(murray, 0x203, 6);
    murray->setB->b = func_001F4C58(murray, 0x204, 6);
    murray->setB->c = func_001F4C58(murray, 0x205, 1);
    InitIkLimb(murray->setB);
    murray->p15F0 = murray->setA->c;
    murray->p15F4 = func_001F4C58(murray, 0x202, 6);
    murray->p15F8 = murray->setB->c;
    murray->p15FC = func_001F4C58(murray, 0x205, 6);
}
