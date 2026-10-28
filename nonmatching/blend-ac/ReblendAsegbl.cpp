struct MRSGC { int ibMrsg; int cmrsg; void *pamrsg; };
struct ASEGA { char pad0[0x1C]; float tLocal; char pad1[0x2C - 0x20]; ASEGA *pnext; };
struct ASEG { char pad[0x74]; float tMax; char pad2[0xA4 - 0x78]; float *paea; };
struct ASEGBL {
    char pad0[0x50]; ASEGA *pasega;
    char pad1[0x74 - 0x54]; float tMax;
    char pad2[0xA0 - 0x78]; int ceaFrame; float *paeaFrame;
    char pad3[0xC0 - 0xA8]; int cbBl; int cbl; char *abl; int cmrsgc; MRSGC *pamrsgc; int unkD4; ASEG *pasegEvents;
};
extern "C" void SetAsegblIpasegDominant(ASEGBL *, int);
extern "C" void CalculateBlendAmrsg__FiiPviiP4MRSGPf(ASEGBL *, int, int, void *, float *);
void ReblendAsegbl(ASEGBL *pasegbl)
{
    volatile int reserved;
    int ipaseg = pasegbl->cbl;
    for (;;) {
        ipaseg--;
        if (ipaseg < 0)
            break;
        if (*(float *)(pasegbl->abl + ipaseg * pasegbl->cbBl) > 0.9999f)
            break;
    }
    SetAsegblIpasegDominant(pasegbl, ipaseg);
    for (ASEGA *pasega = pasegbl->pasega; pasega != 0; pasega = pasega->pnext)
        pasega->tLocal = pasega->tLocal / pasegbl->tMax;
    int i;
    for (i = 0; i < pasegbl->cmrsgc; i++) {
        MRSGC *pmrsgc = &pasegbl->pamrsgc[i];
        CalculateBlendAmrsg__FiiPviiP4MRSGPf(pasegbl, pmrsgc->ibMrsg, pmrsgc->cmrsg, pmrsgc->pamrsg, &pasegbl->tMax);
    }
    if (pasegbl->cmrsgc == 0)
        CalculateBlendAmrsg__FiiPviiP4MRSGPf(pasegbl, 0, 0, 0, &pasegbl->tMax);
    for (ASEGA *pasega = pasegbl->pasega; pasega != 0; pasega = pasega->pnext)
        pasega->tLocal = pasega->tLocal * pasegbl->tMax;
    ASEG *pasegEvents = pasegbl->pasegEvents;
    if (pasegEvents != 0) {
        float gScale = pasegbl->tMax / pasegEvents->tMax;
        for (int iea = 0; iea < pasegbl->ceaFrame; iea++)
            pasegbl->paeaFrame[iea * 4] = gScale * pasegbl->pasegEvents->paea[iea * 4];
    }
}
