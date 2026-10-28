struct ASEG { char pad[0x74]; float tMax; };
struct ASEGA { char pad0[0x14]; ASEG *paseg; char pad1[0x24]; unsigned grf; char pad2[4]; float svt; };
extern "C" float fmodf(float, float);
extern "C" float GModPositive__Fff(float, float);

extern "C" int FWrapAsegaTime(ASEGA *pasega, float *ptLocal, float *psvtLocal)
{
    float tMax = pasega->paseg->tMax;
    float tFold;
    int fWrapped = 0;
    float tPeriod;
    unsigned grf;
    if (*ptLocal >= tMax) {
        if (*psvtLocal > 0.0f)
            fWrapped = 1;
        grf = pasega->grf;
        if (grf & 8) {
            *ptLocal = fmodf(*ptLocal, tMax);
        } else if (!(grf & 0x10)) {
            *ptLocal = tMax;
            float svt = *psvtLocal;
            *psvtLocal = svt < 0.0f ? svt : 0.0f;
        } else {
            tFold = *ptLocal;
            goto pingpong;
        }
    } else if (*ptLocal < 0.0f) {
        if (*psvtLocal < 0.0f)
            fWrapped = 1;
        grf = pasega->grf;
        if (grf & 8) {
            *ptLocal = GModPositive__Fff(*ptLocal, tMax);
        } else if (grf & 0x10) {
            tFold = -*ptLocal;
        pingpong:
            tPeriod = tMax + tMax;
            *ptLocal = fmodf(tFold, tPeriod);
            *psvtLocal = __builtin_fabsf(*psvtLocal);
            pasega->svt = __builtin_fabsf(pasega->svt);
            if (*ptLocal >= tMax) {
                *ptLocal = tPeriod - *ptLocal;
                *psvtLocal = -*psvtLocal;
                pasega->svt = -pasega->svt;
            }
        } else {
            *ptLocal = 0.0f;
            float svt = *psvtLocal;
            *psvtLocal = svt > 0.0f ? svt : 0.0f;
        }
    }
    return fWrapped;
}
