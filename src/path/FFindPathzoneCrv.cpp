// SPDX-License-Identifier: GPL-3.0-or-later
struct PATHZONE_1C02D0 { char pad0[0xE8]; int cSteps; char pad1[0xF4 - 0xEC]; int iLimit; };
extern "C" {
int CposFindPath__FP2CGP6VECTORT1iT1(void *, void *, void *, int, int);
void MeasureCrv(void *);
}

extern "C" int FFindPathzoneCrv(char *pcg, void *pFrom, void *pTo, PATHZONE_1C02D0 *ppathzone)
{
    int cSteps = CposFindPath__FP2CGP6VECTORT1iT1(pcg + 0xE0, pFrom, pTo, 0x10, ppathzone->iLimit);
    if (cSteps < 2) return 0;
    ppathzone->cSteps = cSteps;
    MeasureCrv(ppathzone);
    return 1;
}
