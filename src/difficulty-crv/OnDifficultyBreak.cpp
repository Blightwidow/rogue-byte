#include "sly2.h"
extern "C" char B_002DE578;
extern "C" char B_003DD490;
extern "C" float GetSuck(void *);
extern "C" int NRandInRange(int, int);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int CpdprizeAttractSwDprizes(void *, int, QW, void *, int);
struct DIFFPARAMS_154E10 {
    char pad0[0x10];
    int cBreakMin;
    int cBreakMax;
    int cBreakMinLow;
    int cBreakMaxLow;
    char pad20[8];
    struct { int nMin[2]; int nMax[2]; } arange[2];
};
struct DIFF_154E10 {
    int nBreak;
    int nPrize;
    char pad8[0xC];
    DIFFPARAMS_154E10 *pparams;
};
static inline int NSuckLerp(DIFF_154E10 *pdiff, int irange, int i)
{
    float g = GetSuck(&B_002DE578);
    int nMin = pdiff->pparams->arange[irange].nMin[i];
    int nMax = pdiff->pparams->arange[irange].nMax[i];
    if (nMin == nMax)
        return nMax;
    if (nMin < nMax)
        return nMin + (int)(g * (((float)nMax + 0.999f) - (float)nMin));
    return nMax + (int)((1.0f - g) * (((float)nMin + 0.999f) - (float)nMax));
}
extern "C" void OnDifficultyBreak(DIFF_154E10 *pdiff, QW pos, int cprize, int dPrize, void *pso)
{
    if (pdiff->nBreak <= 0) {
        int nLow = NSuckLerp(pdiff, 0, 0);
        int nHigh = NSuckLerp(pdiff, 0, 1);
        pdiff->nBreak = NRandInRange(nLow, nHigh);
    }
    if (pdiff->nPrize <= 0) {
        int nLow = NSuckLerp(pdiff, 1, 0);
        int nHigh = NSuckLerp(pdiff, 1, 1);
        pdiff->nPrize = NRandInRange(nLow, nHigh);
    }
    int dBreak = FIsBasicDerivedFrom(pso, 0x38) ? -2 : -1;
    pdiff->nBreak += dBreak;
    pdiff->nPrize += dPrize;
    if (cprize < 0) {
        if (pdiff->nBreak <= 0)
            cprize = NRandInRange(pdiff->pparams->cBreakMin, pdiff->pparams->cBreakMax);
        else
            cprize = NRandInRange(pdiff->pparams->cBreakMinLow, pdiff->pparams->cBreakMaxLow);
    }
    if (cprize > 0)
        CpdprizeAttractSwDprizes(&B_003DD490, 0x5B, pos, pso, cprize);
    if (pdiff->nPrize <= 0)
        CpdprizeAttractSwDprizes(&B_003DD490, 0x5D, pos, pso, 1);
}
