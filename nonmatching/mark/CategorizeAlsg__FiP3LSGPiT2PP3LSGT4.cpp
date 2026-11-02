#include "sly2.h"
struct LSG {
    VECTOR pos0;
    VECTOR pos1;
    VECTOR posA;
    VECTOR posB;
    float s0;
    float s1;
    int unk48;
    int fBlock0;
    int fBlock1;
    unsigned short *aipos;
    int iipos;
    LSG *plsgNext;
};
extern "C" void *memmove(void *, const void *, unsigned int);

template <class T> static inline void Swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

void CategorizeAlsg(int clsg, LSG *alsg, int *pcpos, int *apos, LSG **aplsg, LSG **pplsgFree)
{
    int ilsg;
    int ipos;
    LSG *plsgBoth = 0;
    int cpos = 0;
    *pplsgFree = 0;
    for (ilsg = 0; ilsg < clsg; ilsg++) {
        LSG *plsg = &alsg[ilsg];
        if (plsg->fBlock0 != 0) {
            if (plsg->fBlock1 != 0) {
                plsg->plsgNext = *pplsgFree;
                *pplsgFree = plsg;
                continue;
            }
        } else {
            if (plsg->fBlock1 == 0) {
                plsg->plsgNext = plsgBoth;
                plsgBoth = plsg;
                continue;
            }
            goto LSearch;
        }
        Swap(plsg->pos0, plsg->pos1);
        Swap(plsg->posA, plsg->posB);
        Swap(plsg->s0, plsg->s1);
        Swap(plsg->fBlock0, plsg->fBlock1);
        plsg->iipos = 1;
    LSearch:
        for (ipos = 0; ipos < cpos; ipos++) {
            if (plsg->aipos[plsg->iipos] == apos[ipos])
                break;
        }
        if (ipos >= cpos) {
            apos[ipos] = plsg->aipos[plsg->iipos];
            cpos++;
        } else {
            plsg->plsgNext = aplsg[ipos];
        }
        aplsg[ipos] = plsg;
    }
    for (ipos = 0; ipos < cpos; ipos++) {
        LSG **pplsg = &aplsg[ipos];
        int *pipos = &apos[ipos];
        if ((*pplsg)->plsgNext == 0) {
            LSG *plsg = plsgBoth;
            if (plsg) {
                int iposT = *pipos;
                do {
                    unsigned short *aipos = plsg->aipos;
                    if (aipos[0] == iposT || aipos[1] == iposT)
                        goto LNext;
                    plsg = plsg->plsgNext;
                } while (plsg);
            }
            {
                int cb = (cpos - ipos) * sizeof(int) - sizeof(int);
                (*pplsg)->plsgNext = *pplsgFree;
                *pplsgFree = *pplsg;
                memmove(pplsg, pplsg + 1, cb);
                memmove(pipos, pipos + 1, cb);
                cpos--;
                ipos--;
            }
        }
    LNext:;
    }
    *pcpos = cpos;
}
