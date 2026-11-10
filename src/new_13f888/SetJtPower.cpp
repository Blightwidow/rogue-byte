#include "jt.h"
void SetJtPower(JT *pjt, int nPower)
{
    int *pn = pjt->pnPower;
    if (pn) {
        int nMax = pjt->nPowerMax;
        *pn = nPower < nMax ? nPower : nMax;
    }
}
