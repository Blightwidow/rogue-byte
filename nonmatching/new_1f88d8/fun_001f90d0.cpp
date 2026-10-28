/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct VT { char pad[0x2a8]; short delta; short index; int (*fn)(void *); };
struct SOB { char pad[0xc]; VT *vt; };
struct OXA;
struct SO { char pad[0xec]; OXA *poxa; char pad2[0x148 - 0xf0]; unsigned long grfso; };
struct XP { char pad0[8]; SOB *pso; char pad1[0x9c - 0xc]; int kind; char pad2[0xa8 - 0xa0]; int num; XP *next; };
struct NODE { XP *pxp; NODE *next; char pad[4]; SO *pso; };
struct OXA { char pad[0x64]; NODE *first; XP *own; };

int func_001F90D0(void *psw, int grf, int cso, SO **apso, int cxpMax, XP **axp)
{
    int cxp = 0;
    for (int iso = 0; iso < cso; iso++) {
        SO *pso = apso[iso];
        pso->grfso |= 0x10000000UL;
        NODE *node = pso->poxa->first;
        for (;;) {
            while (node != 0 && (node->pso->grfso & 0x10000000UL) != 0)
                node = node->next;
            XP *pxp = node != 0 ? node->pxp : pso->poxa->own;
            for (; pxp != 0; pxp = pxp->next) {
                if (pxp->kind == 0xd)
                    continue;
                if (pxp->kind == 0xe) {
                    VT *vt = pxp->pso->vt;
                    if ((vt->fn((char *)pxp->pso + vt->delta) & 4) == 0)
                        continue;
                }
                if (cxp >= cxpMax)
                    return cxp;
                pxp->num = cxp;
                axp[cxp++] = pxp;
            }
            if (node == 0)
                break;
            node = node->next;
        }
    }
    return cxp;
}
