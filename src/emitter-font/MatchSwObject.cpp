// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LO_15E3E8 {
    int oid;
    LO_15E3E8 *pnext;
    char pad0[0x10 - 0x8];
    LO_15E3E8 *paloParent;
    char pad1[0x28 - 0x14];
    union {
        unsigned long grf;
        struct { int unk28; signed char depth; };
    };
};
extern "C" int IsetFromCloneId(int);

extern "C" void MatchSwObject(void *psw, LO_15E3E8 *plo, LO_15E3E8 *ploMatch, unsigned grffso, LO_15E3E8 *ploContext,
                              LO_15E3E8 *plst, int cploMax, int *pcploMatch, LO_15E3E8 **aplo, int *pipsl)
{
    if (!(grffso & 0x400)) {
        switch ((long)(plo->grf << 12) >> 60) {
        case 0: {
            LO_15E3E8 *p = plst;
            for (;;) {
                if (p == 0)
                    return;
                if (IsetFromCloneId(p->oid) == IsetFromCloneId(ploMatch->oid))
                    break;
                if (grffso & 0x800)
                    return;
                p = p->pnext;
            }
            break;
        }
        case -1:
            for (; plst != ploMatch; plst = plst->pnext) {
                if (plst == 0)
                    return;
                if (grffso & 0x800)
                    return;
            }
            break;
        case 1:
            break;
        }
    }
match:
    LO_15E3E8 *p;
    switch (grffso & 0xFF) {
    case 2:
        if (plo->paloParent == ploContext)
            goto add;
        return;
    case 1:
        p = plo;
        if (p == 0)
            return;
        for (; p != 0; p = p->paloParent) {
            int depth = p->depth;
            if (depth != 0) {
                if (depth == 1)
                    goto add;
                return;
            }
        }
        return;
    case 3:
        if (plo->depth >= 2)
            goto add;
        return;
    case 4: {
        p = plo;
        int ipsl = *pipsl;
        for (; p != 0; p = p->paloParent) {
            if (p->depth != 0 && p->depth < *pipsl) {
                if ((grffso & 0x100) && ((plo->grf >> 60) & 1) == 0)
                    return;
                *pipsl = p->depth;
                *pcploMatch = 0;
                goto store;
            }
        }
        if (ipsl != 0x7FFFFFFF || p != 0)
            return;
    }
    case 5:
    add:
        if ((grffso & 0x100) && ((plo->grf >> 60) & 1) == 0)
            return;
    store:
        if (*pcploMatch < cploMax)
            aplo[*pcploMatch] = plo;
        (*pcploMatch)++;
        return;
    }
}
