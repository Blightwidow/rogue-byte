// SPDX-License-Identifier: GPL-3.0-or-later
struct CRV { char pad0[0xE8]; int ccv; float *mpicvu; char pad1[0x88]; int icvHint; };
extern "C" float UWrapCrv(CRV *, float);

extern "C" int IcvFindCrvU(CRV *pcrv, float u, float *pdu, float *pduSeg)
{
    u = UWrapCrv(pcrv, u);
    int icv = pcrv->icvHint;
    float *mpicvu = pcrv->mpicvu;
    if (mpicvu[icv] < u) {
        int icvLast = pcrv->ccv - 1;
        for (; icv < icvLast; icv++) {
            if (u < mpicvu[icv])
                break;
        }
        icv--;
    } else if (icv > 0) {
        while (icv > 0) {
            if (!(u < mpicvu[icv]))
                break;
            icv--;
        }
    }
    float uSeg = pcrv->mpicvu[icv];
    if (pdu != 0)
        *pdu = u - uSeg;
    if (pduSeg != 0)
        *pduSeg = pcrv->mpicvu[icv + 1] - uSeg;
    pcrv->icvHint = icv;
    return icv;
}
