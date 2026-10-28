/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SAPEP { float g; unsigned short fMin; unsigned short islot; };
int IepSweepPathzoneCursor(float g, SAPEP *aep, int iep, unsigned *agrf, unsigned fMin)
{
    SAPEP *pep = &aep[iep];
    if (g <= pep->g) {
        do {
            if (pep->fMin == fMin) {
                unsigned *pgrf = &agrf[pep->islot >> 5];
                if (fMin == 0)
                    *pgrf = *pgrf | (1u << (pep->islot & 0x1f));
                else
                    *pgrf = *pgrf - (1u << (pep->islot & 0x1f));
            }
            pep--;
            iep--;
        } while (g <= pep->g);
        return iep;
    }
    pep = &aep[iep + 1];
    int iepNext = iep + 1;
    while (pep->g <= g) {
        if (pep->fMin == fMin) {
            unsigned *pgrf = &agrf[pep->islot >> 5];
            if (fMin == 0)
                *pgrf = *pgrf - (1u << (pep->islot & 0x1f));
            else
                *pgrf = *pgrf | (1u << (pep->islot & 0x1f));
        }
        pep++;
        iep = iepNext;
        iepNext++;
    }
    return iep;
}
