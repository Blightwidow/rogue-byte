// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; union { int n; float *pg; float g; }; };
struct CFrame;
extern "C" {
void CRef_RefCoerceF32(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpClqEvaluateLm(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    const float *pclq = aref[0].pg;
    const float *plm = aref[1].pg;
    CRef refT;
    CRef_RefCoerceF32(&refT, &aref[2]);
    float gValue = pclq[0] + refT.g * (pclq[1] + refT.g * pclq[2]);
    float gLo = plm[0];
    float gHi = plm[1];
    if (gValue < gLo)
        gValue = gLo;
    else if (gHi < gValue)
        gValue = gHi;
    pret->g = gValue;
    pret->tagk = 0x16;
    CRef_Destruct(&refT);
    return pret;
}
