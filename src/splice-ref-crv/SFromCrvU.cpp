// SPDX-License-Identifier: GPL-3.0-or-later
struct CRV { char pad0[0xE0]; int crvk; char pad1[0xC]; float *mpicvs; char pad2[0x58]; float mpisamps[1]; };
extern "C" int IcvFindCrvU(CRV *, float, float *, float *);
extern "C" void FillCrvcCache(CRV *, int);

extern "C" float SFromCrvU(CRV *pcrv, float u)
{
    float du;
    float duSeg;
    int icv = IcvFindCrvU(pcrv, u, &du, &duSeg);
    float result;
    if (pcrv->crvk == 0) {
        float t = du / duSeg;
        result = (1.0f - t) * pcrv->mpicvs[icv] + t * pcrv->mpicvs[icv + 1];
    } else {
        FillCrvcCache(pcrv, icv);
        float gSample = du * 10.0f / duSeg;
        int isamp = (int)gSample;
        float t = gSample - (float)isamp;
        float s0 = pcrv->mpisamps[isamp];
        float s1 = pcrv->mpisamps[isamp + 1];
        result = (1.0f - t) * s0 + t * s1;
        result += pcrv->mpicvs[icv];
    }
    return result;
}
