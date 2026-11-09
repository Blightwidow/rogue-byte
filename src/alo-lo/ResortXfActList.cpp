/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct ALO;
struct ACT;
struct ACTVT { char pad[8]; short deltaActivate; short i0; void (*activate)(void *); short deltaDeactivate; short i1; void (*deactivate)(void *); short deltaReselect; short i2; void (*reselect)(void *); };
struct ACT { char pad0[0xC]; int priority; ACT *next; char pad14[4]; ACTVT *vt; };
#include "xf.h"
void InvalidateXfSegment(ALO *, XF *);
void ResortXfActList(ALO *alo, XF *xf)
{
    ACT *acts[16];
    int count = 0;
    ACT *act0 = xf->pactFirst;
    while (act0) {
        acts[count++] = act0;
        act0 = act0->next;
    }
    ACT *oldTop = xf->pactFirst;
    xf->pactFirst = 0;
    for (count--; count >= 0; count--) {
        ACT *act = acts[count];
        ACT **link = &xf->pactFirst;
        ACT *cur = xf->pactFirst;
        while (cur) {
            if (!(cur->priority > act->priority)) break;
            link = &cur->next;
            cur = cur->next;
        }
        act->next = *link;
        *link = act;
    }
    if (xf->pactFirst != oldTop) {
        InvalidateXfSegment(alo, xf);
        if (oldTop)
            oldTop->vt->deactivate((char *)oldTop + oldTop->vt->deltaDeactivate);
        if (xf->pactFirst)
            xf->pactFirst->vt->activate((char *)xf->pactFirst + xf->pactFirst->vt->deltaActivate);
    } else if (oldTop) {
        oldTop->vt->reselect((char *)oldTop + oldTop->vt->deltaReselect);
    }
}
