// SPDX-License-Identifier: GPL-3.0-or-later
struct CRV { char pad0[0xE8]; int ccv; char pad1[4]; float *mpicvs; char pad2[0x84]; int icvHint; };
extern "C" float SWrapCrv(CRV *, float);

extern "C" int IcvFindCrvS(CRV *pcrv, float s, float *pds, float *pdsSeg)
{
    s = SWrapCrv(pcrv, s);
    int icv = pcrv->icvHint;
    if (pcrv->mpicvs[icv] < s) {
        int icvLast = pcrv->ccv - 1;
        for (; icv < icvLast; icv++) {
            if (s < pcrv->mpicvs[icv])
                break;
        }
        icv--;
    } else if (icv > 0) {
        while (icv > 0) {
            if (!(s < pcrv->mpicvs[icv]))
                break;
            icv--;
        }
    }
    if (pds != 0)
        *pds = s - pcrv->mpicvs[icv];
    if (pdsSeg != 0)
        *pdsSeg = pcrv->mpicvs[icv + 1] - pcrv->mpicvs[icv];
    pcrv->icvHint = icv;
    return icv;
}
