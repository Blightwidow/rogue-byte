struct CRV { char pad[0xE4]; int cknot; int cpt; float *apt1; float *apt; };
extern "C" float GModPositive__Fff(float, float);
extern "C" float SWrapCrv(CRV *crv, float s)
{
    if (crv->cknot == 0)
        return s;
    float last = crv->apt[crv->cpt - 1];
    if (0.0f <= s) {
        if (s <= last)
            return s;
    }
    return GModPositive__Fff(s, last);
}
