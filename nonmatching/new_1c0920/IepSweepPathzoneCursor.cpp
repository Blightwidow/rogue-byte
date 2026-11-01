/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SAPEP { float g; unsigned short fMin; unsigned short islot; };
int IepSweepPathzoneCursor(float g, SAPEP *aep, int iep, unsigned *agrf, unsigned fMin)
{
    SAPEP *pep = &aep[iep];
    if (g <= pep->g) {
        SAPEP *cur = pep;
        for (;;) {
            if (pep->g < g)
                break;
            if (cur->fMin == fMin) {
                unsigned islot = cur->islot;
                unsigned word = islot >> 5;
                unsigned bit = islot - (word << 5);
                if (fMin == 0)
                    agrf[word] = agrf[word] | (1u << bit);
                else
                    agrf[word] = agrf[word] - (1u << bit);
            }
            pep--;
            iep--;
            cur = pep;
        }
        return iep;
    }
    iep++;
    pep = &aep[iep];
    SAPEP *cur = pep;
    for (;;) {
        if (g < pep->g)
            break;
        if (cur->fMin == fMin) {
            unsigned islot = cur->islot;
            unsigned word = islot >> 5;
            unsigned bit = islot - (word << 5);
            if (fMin == 0)
                agrf[word] = agrf[word] - (1u << bit);
            else
                agrf[word] = agrf[word] | (1u << bit);
        }
        pep++;
        iep++;
        cur = pep;
    }
    return iep - 1;
}
