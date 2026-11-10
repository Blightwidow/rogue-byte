/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct Bis;
#include "alloc.h"
struct IKLIMB { int pad0; void *a; void *b; void *c; };
#include "murray.h"
extern "C" {
extern char D_002C0270[];
void LoadStepFromBrx(MURRAY *, Bis *);
void SetSoProperties(MURRAY *, int, void *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *func_001F4C58(MURRAY *, int, int);
void InitIkLimb(IKLIMB *);
}
extern "C" void LoadMurrayFromBrx(MURRAY *murray, Bis *bis)
{
    LoadStepFromBrx(murray, bis);
    SetSoProperties(murray, 0x89, D_002C0270);
    ALLOCREQ req;
    req.cb = 0xE0;
    req.cbAlign = 0x10;
    murray->pikLimbA = (IKLIMB *)PvAllocSwClearImpl__Fi(&req);
    murray->pikLimbA->a = func_001F4C58(murray, 0x200, 6);
    murray->pikLimbA->b = func_001F4C58(murray, 0x201, 6);
    murray->pikLimbA->c = func_001F4C58(murray, 0x202, 1);
    InitIkLimb(murray->pikLimbA);
    req.cb = 0xE0;
    req.cbAlign = 0x10;
    murray->pikLimbB = (IKLIMB *)PvAllocSwClearImpl__Fi(&req);
    murray->pikLimbB->a = func_001F4C58(murray, 0x203, 6);
    murray->pikLimbB->b = func_001F4C58(murray, 0x204, 6);
    murray->pikLimbB->c = func_001F4C58(murray, 0x205, 1);
    InitIkLimb(murray->pikLimbB);
    murray->field_0x15F0 = murray->pikLimbA->c;
    murray->field_0x15F4 = func_001F4C58(murray, 0x202, 6);
    murray->field_0x15F8 = murray->pikLimbB->c;
    murray->field_0x15FC = func_001F4C58(murray, 0x205, 6);
}
