// SPDX-License-Identifier: GPL-3.0-or-later
struct CRV { char pad0[0xE0]; int crvk; char pad1[8]; float *mpicvu; char pad2[0x5C]; float mpisamps[10]; };
extern "C" int IcvFindCrvS(CRV *, float, float *, float *);
extern "C" void FillCrvcCache(CRV *, int);

extern "C" float UFromCrvS(CRV *pcrv, float s)
{
    float ds;
    float dsSeg;
    float result;
    int icv = IcvFindCrvS(pcrv, s, &ds, &dsSeg);
    if (pcrv->crvk == 0) {
        float t = ds / dsSeg;
        result = (1.0f - t) * pcrv->mpicvu[icv] + t * pcrv->mpicvu[icv + 1];
    } else {
        FillCrvcCache(pcrv, icv);
        int isamp;
        for (isamp = 1; isamp < 10; isamp++) {
            if (ds < pcrv->mpisamps[isamp])
                break;
        }
        isamp--;
        float lo = pcrv->mpisamps[isamp];
        float hi = pcrv->mpisamps[isamp + 1];
        float t = (ds - lo) / (hi - lo);
        t = ((float)isamp + t) * 0.1f;
        result = (1.0f - t) * pcrv->mpicvu[icv] + t * pcrv->mpicvu[icv + 1];
    }
    return result;
}
