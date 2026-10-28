struct CRV { char pad[0xE4]; int fClosed; };
extern "C" float SWrapCrv(CRV *, float);
extern "C" float SMinCrv(CRV *);
extern "C" float SMaxCrv(CRV *);
extern "C" float func_001E6728(CRV *pcrv, float s)
{
    if (pcrv->fClosed != 0)
        return SWrapCrv(pcrv, s);
    float sMin = SMinCrv(pcrv);
    float sMax = SMaxCrv(pcrv);
    float r;
    if (s < sMin)
        r = sMin;
    else if (sMax < s)
        r = sMax;
    else
        r = s;
    return r;
}
