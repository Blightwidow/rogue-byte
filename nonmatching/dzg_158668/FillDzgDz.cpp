// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "alloc.h"
#include "ps2inline.h"
#include "vu0inline.h"
extern "C" {
void *PvAllocStackImpl__Fi(ALLOCREQ *);
}
typedef void (*Visit)(char *, char *, char *, int, int);
typedef void (*Evaluate)(char *, char *, QW, QW *);
extern "C" void FillDzgDz(char *pdzs, int arg1, char *arg2, char *pgroup)
{
    ALLOCREQ request;
    QW pair[2];
    char *pnodes = *(char **)(pgroup + 0x50);
    char *ppnode = pnodes + 8;
    int slot;
    for (slot = 0; slot < 2; slot++, ppnode += 0x40) {
        char *pnode = *(char **)ppnode;
        if (pnode != 0) {
            char *pvtable = *(char **)(pnode + 0xC);
            ((Visit)*(void **)(pvtable + 0x224))(pnode + *(short *)(pvtable + 0x220), arg2, pgroup, arg1, slot);
        }
    }
    request.cb = *(int *)(pdzs + 0x50) * 0x10;
    request.cbAlign = 0x10;
    QW *pdifference = (QW *)PvAllocStackImpl__Fi(&request);
    *(QW **)(pgroup + 0x54) = pdifference;
    for (int index = 0; index < *(int *)(pdzs + 0x50); pdifference++, index++) {
        char *pentry = *(char **)(*(char **)(pdzs + 0x54) + index * 4);
        QW *pout = pair;
        for (slot = 1; slot >= 0; slot--, pout++, pentry += 0x40) {
            char *pnode = *(char **)(pentry + 8);
            char *pcontext;
            if (pnode != 0 && (pnode == *(char **)(pnodes + 8) ? (pcontext = pgroup, 1) : (pnode == *(char **)(pnodes + 0x48) ? (pcontext = pgroup + 0x20, 1) : 0))) {
                char *pvtable = *(char **)(pnode + 0xC);
                ((Evaluate)*(void **)(pvtable + 0x22C))(pnode + *(short *)(pvtable + 0x228), pcontext, *(QW *)(pentry + 0x10), pout);
            } else {
                ((int *)pout)[2] = 0;
                ((int *)pout)[1] = 0;
                ((int *)pout)[0] = 0;
            }
        }
        *pdifference = VectorSub(pair[0], pair[1]);
    }
    request.cb = *(int *)(pdzs + 4) * 4;
    request.cbAlign = 0x10;
    float *pdistance = (float *)PvAllocStackImpl__Fi(&request);
    *(float **)(arg2 + 0x18) = pdistance;
    for (int index = 0; index < *(int *)(pdzs + 4); index++) {
        char *precord = *(char **)(pdzs + 0x60) + index * 0x60;
        char *pnode = *(char **)(precord + 0x50);
        QW direction = *(QW *)(precord + 0x40);
        QW difference = ((QW *)*(char **)(pgroup + 0x54))[*(int *)(pnode + 0xA8)];
        *(u32 *)pdistance++ = VectorWordX(DotProduct(direction, difference));
    }
}
